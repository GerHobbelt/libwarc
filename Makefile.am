# This file is the Makefile template for automake.

# libwarc is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# libwarc is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with libwarc.  If not, see <https://www.gnu.org/licenses/>.

# Basic Setup: Set m4 as libtool configuration file directory
ACLOCAL_AMFLAGS= -I m4
include_HEADERS = include/libwarc.h
CLEANFILES = *.tap

# libwarc shared library
lib_LTLIBRARIES = libwarc.la
libwarc_la_SOURCES = src/libwarc_main.c
libwarc_la_CPPFLAGS = -I$(top_srcdir)/include

if EXAMPLES
# Examples
    noinst_PROGRAMS = \
    examples/hello

    # Example generated from the shared library
    examples_hello_SOURCES = examples/main.c
    examples_hello_CPPFLAGS = -I$(top_srcdir)/include
    examples_hello_LDADD = libwarc.la
endif

TESTS = tests/printhwtest
check_PROGRAMS = tests/printhwtest
tests_printhwtest_SOURCES = tests/test.c
tests_printhwtest_CPPFLAGS = -I$(top_srcdir)/include
tests_printhwtest_CFLAGS = @CHECK_CFLAGS@
tests_printhwtest_LDADD = libwarc.la @CHECK_LIBS@
