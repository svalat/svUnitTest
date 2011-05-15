######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

This directory contain the requierd files to build the project on distributions, please read this file before using it.

I. Ubuntu :
___________

This project support the ubuntu packing to build .dev files. To build such package you may use the files in packaging/ubuntu.
First create a directory in your home dir, place the project archive in it and rename it to svUnitTest_0.3.0.orig.tar.gz.

To setup your working environneemnt, you will found documentation on https://wiki.ubuntu.com/PbuilderHowto. We mosly need :

--------------------------------------------------------------------
sudo apt-get install pbuilder debootstrap devscripts cdbs debhelper
sudo pbuilder create
--------------------------------------------------------------------

If you work with git version you can build the archive with :

--------------------------------------------------------------------
$user> git archive --prefix=svUnitTest-0.3.0/ v0.3.0 | gzip > YOUR_LOCATION/svUnitTest_0.3.0.orig.tar.gz
--------------------------------------------------------------------

Go to your directory and extract svUnitTest_0.3.0.orig.tar.gz with and go in the directory.

--------------------------------------------------------------------
$user> tar -xvzf svUnitTest_0.3.0.orig.tar.gz
$user> cd svUnitTest_0.3.0
--------------------------------------------------------------------

Now go to the  kaudioconverter-0.3 directory and move the packaging/ubunt into debian :

--------------------------------------------------------------------
$user> mv packaging/ubunt debian
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

