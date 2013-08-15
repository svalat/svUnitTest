######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

Name:           svUnitTest
Version:        0.4.0
Release:        1%{?dist}
Summary:        A C++ test suite library, similar to CPPunit.

Group:          Development/Libraries
License:        CeCILL-C
URL:            https://github.com/downloads/svalat/svUnitTest/%{name}-%{version}.tar.bz2
Source0:        %{name}-%{version}.tar.bz2
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

BuildRequires:  cmake, gcc-c++
Requires:       libxslt

%description
A C++ test suite library, similar to CPPunit.

%prep
%setup -q


%build
%cmake -DENABLE_SELF_TEST=yes -DCMAKE_BUILD_TYPE=Debug
make %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT


%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(-,root,root,-)
%{_bindir}/*
%{_libdir}/*
%{_datadir}/*
%{_includedir}/*
%doc


%changelog
