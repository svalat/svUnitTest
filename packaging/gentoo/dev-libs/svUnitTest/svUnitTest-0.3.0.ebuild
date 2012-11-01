######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.4.0                        #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

EAPI=4

inherit cmake-utils

RESTRICT="primaryuri"
DESCRIPTION="A C++ test suite library, similar to CPPunit."
HOMEPAGE="https://github.com/svalat/svUnitTest"
SRC_URI="https://github.com/downloads/svalat/svUnitTest/svUnitTest-0.3.0.tar.bz2"

LICENSE="CeCILL-C"
SLOT="0"
KEYWORDS="~x86 ~amd64"
IUSE=""

DEPEND="dev-libs/libxslt"
RDEPEND="dev-libs/libxslt"

src_configure() {
	#disable cppunit by default, not required for package installation
	#it's only to test the lib itself.
	local mycmakeargs=(-DDISABLE_CPPUNIT=yes)
	cmake-utils_src_configure
}
