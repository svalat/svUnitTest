######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.4.0                        #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

This directory contain some files to help you to build a package on distributions, please read this file before using it.

I. UBUNTU / DEBIAN :
____________________

This project support the ubuntu packing to build .dev files. To build such package you may use the files in packaging/ubuntu.
First create a directory in your home dir, place the project archive in it and rename it to svUnitTest_0.4.0.orig.tar.gz.

To setup your working environneemnt, you will found documentation on https://wiki.ubuntu.com/PbuilderHowto. We mosly need :

--------------------------------------------------------------------
sudo apt-get install pbuilder debootstrap devscripts cdbs debhelper
sudo pbuilder create
--------------------------------------------------------------------

If you work with git version you can build the archive with :

--------------------------------------------------------------------
$user> git archive --prefix=svUnitTest-0.4.0/ v0.4.0 | gzip > svUnitTest_0.4.0.orig.tar.gz
--------------------------------------------------------------------

Go to your directory and extract svUnitTest_0.4.0.orig.tar.gz with and go in the directory.

--------------------------------------------------------------------
$user> tar -xvzf svUnitTest-0.4.0.orig.tar.gz
$user> cd svUnitTest-0.4.0
--------------------------------------------------------------------

Now go to the svUnitTest-0.3 directory and move the packaging/ubunt into debian :

--------------------------------------------------------------------
$user> mv packaging/debian debian
--------------------------------------------------------------------

You can quickly build the package for the running ubuntu with (remove -uc and -us if you have some GPG keys to sign the package) :

--------------------------------------------------------------------
$user> debuild -uc -us
--------------------------------------------------------------------

You may get a .deb archive in the parent directory.

You can build a source package with :

--------------------------------------------------------------------
$user> debuild -S -uc -us
--------------------------------------------------------------------

So you can build package with your source package by running :

--------------------------------------------------------------------
sudo pbuilder build ../*.dsc
--------------------------------------------------------------------

You will obtain the package in /var/cache/pbuilder/results.



II. FEDORA / CENTOS / REDHAT :
______________________________

You can find more documentation on http://fedoraproject.org/wiki/How_to_create_an_RPM_package.
First ensure to get the required tools :

--------------------------------------------------------------------
$user> sudo yum install rpmdevtools yum-utils cmake 
$user> rpmdev-setuptree
--------------------------------------------------------------------

Now generate the archive file (or download it from internet) :

--------------------------------------------------------------------
$user> git archive --prefix=svUnitTest-0.4.0/ v0.4.0 | bzip2 > ~/rpmbuild/SOURCES/svUnitTest-0.4.0.tar.bz2
--------------------------------------------------------------------

And build the package :

--------------------------------------------------------------------
$user> rpmbuild -ba packaging/fedora/svUnitTest.spec
--------------------------------------------------------------------

Now you may get *.rpm files in ~/rpmbuild/RPMS and ~/rpmbuild/SRPMS dirs.



III. GENTOO :
_____________

This project support a Gentoo integration, for that you may found the corresponding ebuild file int the packaging/gentoo 
subdirectory. To use this, simply place the dev-libs/svUnitTest directory on your own portage overlay.

For overlay documentation see : http://www.gentoo.org/proj/en/overlays/userguide.xml.

--------------------------------------------------------------------
#root> mkdir /usr/local/portage/myoverlay
#root> cp -r dev-libs /usr/local/portage/myoverlay/
--------------------------------------------------------------------

Add "/usr/local/portage/myoverlay" in your PORTDIR_OVERLAY variable in /etc/make.conf.

Now get the project archive and place it in /usr/portage/distfiles (or corresponding dir if you change it in make.conf). If 
you work on the git version, you can build the project archive with :

--------------------------------------------------------------------
$user> git archive --prefix=svUnitTest-0.4.0/ v0.4.0 | gzip > svUnitTest-0.4.0.tar.gz
--------------------------------------------------------------------

Now got to the /usr/local/portage/myoverlay/dev-libs and build the Manifest file :

--------------------------------------------------------------------
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild manifest
--------------------------------------------------------------------

Ok now you can test the build septs one by one :

--------------------------------------------------------------------
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild clean
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild fetch
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild unpack
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild prepare
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild configure
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild compile
#root> ebuild /usr/local/portage/myoverlay/dev-libs/svUnitTest-0.4.0.ebuild test
--------------------------------------------------------------------

... (I don't do install here bu you also can do preinst, install, postinst, qmerge (maybe qmerge is not a goot idea for the 
fist testings steps).

Or you can simply run :

--------------------------------------------------------------------
#root> echo "=dev-libs/svUnitTest-0.4.0" >> /etc/portage/package.keywords
#root> emerge -a svUnitTest
--------------------------------------------------------------------


