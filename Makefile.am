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

EXTRA_DIST =
CLEANFILES =

# For non recursive make: include $(top_builddir)/lib/gnulib.mk

ACLOCAL_AMFLAGS = -I m4
AM_CPPFLAGS = \
    -I$(top_builddir)/lib\
    -I$(top_srcdir)/lib\
    -I$(top_srcdir)/include
AM_CFLAGS = $(CFLAG_VISIBILITY)
include_HEADERS = include/libwarc.h
CLEANFILES += *.tap

SUBDIRS = lib

# libwarc shared library
lib_LTLIBRARIES = libwarc.la
libwarc_la_SOURCES = src/libwarc_main.c
libwarc_la_LIBADD = lib/libgnu.la
libwarc_la_CPPFLAGS = $(AM_CPPFLAGS) -DBUILDING_LIBWARC

if EXAMPLES
# Examples
    noinst_PROGRAMS = \
    examples/hello

    # Example generated from the shared library
    examples_hello_SOURCES = examples/main.c
    examples_hello_LDADD = libwarc.la
endif

if ENABLE_TESTS
TESTS = tests/printhwtest
check_PROGRAMS = tests/printhwtest
tests_printhwtest_SOURCES = tests/test.c
tests_printhwtest_CFLAGS = $(AM_CFLAGS) $(CHECK_CFLAGS)
tests_printhwtest_LDADD = libwarc.la $(CHECK_LIBS)
endif

dist-hook: gen-ChangeLog

gen-ChangeLog:
	$(top_srcdir)/build-aux/gitlog-to-changelog > $(distdir)/cl-t \
		&& { rm -f $(distdir)/ChangeLog && \
		     mv $(distdir)/cl-t $(distdir)/ChangeLog; }

###
# GnuLib Support
###

EXTRA_DIST += $(top_srcdir)/GNUmakefile \
	      $(top_srcdir)/maint.mk \
	      $(top_srcdir)/m4/gnulib-cache.m4

distclean-local: clean-GNUmakefile
clean-GNUmakefile:
	test '$(srcdir)' = . || rm -f $(top_builddir)/GNUmakefile

# Documentation generation using doxygen
if HAVE_DOXYGEN
man3_MANS = $(builddir)/docs/man/man3/libwarc_main.c.3

.PHONY = docs
docs: $(man3_MANS)

$(man3_MANS): $(libwarc_la_SOURCES)
	$(DOXYGEN) $(builddir)/docs/Doxyfile

EXTRA_DIST += $(man3_MANS)
DOCS_BUILDFILES = $(builddir)/docs/html/ \
		  $(builddir)/docs/man/
endif

mostlyclean-local:
	-rm -rf $(DOCS_BUILDFILES)
