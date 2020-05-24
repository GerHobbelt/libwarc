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
AM_INIT_AUTOMAKE([subdir-objects])

AC_PROG_CC

gl_EARLY
gl_INIT

AC_CONFIG_MACRO_DIRS([m4])

dnl Initialize libtool
LT_INIT()

AC_PROG_SED
AC_PROG_MKDIR_P

PKG_CHECK_MODULES([CHECK], [check >= 0.10.0])

dnl Option to disable building examples
AC_ARG_ENABLE([examples],
    AS_HELP_STRING([--disable-examples], [Disable building examples]))
AM_CONDITIONAL([EXAMPLES], [test "x$enable_examples" != "xno"])

dnl For supporting gnumakefile module from gnulib
GNUmakefile=GNUmakefile

AC_DEFINE([GL_COMPILE_CRYPTO_STREAM], 1, [Compile Gnulib crypto stream ops.])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile lib/Makefile])

dnl For non recursive make:
dnl AC_CONFIG_COMMANDS_PRE([
  dnl Note we can't currently pass $gl_source_base instead of 'lib',
  dnl because $gl_source_base is unset or the wrong value in the references
  dnl generated in m4/non-recursive-gnulib-prefix-hack.m4
dnl   gl_NON_RECURSIVE_GNULIB_PREFIX_HACK([lib])
dnl   ])

AC_OUTPUT
