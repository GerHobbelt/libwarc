dnl This file is the template file for autoconf.
dnl Copyright (C) 2020 Free Software Foundation, Inc.

dnl libwarc is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.

dnl libwarc is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.

dnl You should have received a copy of the GNU General Public License
dnl along with libwarc.  If not, see <https://www.gnu.org/licenses/>.

dnl Initial setup
AC_PREREQ([2.63])
LT_PREREQ([2.4.6])
AC_INIT([libWARC],
        [0.0],
        [wget-libwarc@gnu.org],
        [libwarc],
        [https://gitlab.com/gnuwget/libwarc])

dnl What version of LibWARC are we building?
AC_MSG_NOTICE([Configuring for LibWARC $PACKAGE_VERSION])

dnl Configure Directories
AC_CONFIG_SRCDIR([src/libwarc_main.c])
AC_CONFIG_AUX_DIR([build-aux])

dnl Initialize Automake
AM_INIT_AUTOMAKE([subdir-objects gnu check-news])

AC_PROG_CC_C99
gl_EARLY

AC_CONFIG_MACRO_DIRS([m4])

dnl Initialize libtool
LT_INIT()

AC_PROG_SED
AC_PROG_MKDIR_P

gl_INIT
AC_ARG_ENABLE([tests],
    AS_HELP_STRING([--disable-tests], [Disable running the tests]))

if test x"$enable_tests" != x"no"; then
    PKG_CHECK_MODULES([CHECK], [check >= 0.10.0])
fi
AM_CONDITIONAL([ENABLE_TESTS], [test x"$enable_tests" != "xno"])
AC_CHECK_PROGS([DOXYGEN], [doxygen])
AC_CHECK_PROGS([DOT], [dot])
AS_IF([test -z "$DOXYGEN"], [AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])])

dnl Option to disable building examples
AC_ARG_ENABLE([examples],
    AS_HELP_STRING([--disable-examples], [Disable building examples]))
AM_CONDITIONAL([EXAMPLES], [test "x$enable_examples" != "xno"])

AM_CONDITIONAL([HAVE_DOXYGEN],[test -n "$DOXYGEN" && test -n "$DOT"])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile lib/Makefile])
AM_COND_IF([HAVE_DOXYGEN], [AC_CONFIG_FILES([docs/Doxyfile])])

AC_OUTPUT
