/*
 * Copyright (c) 2020 Free Software Foundation, Inc.
 *
 * This file is part of libwarc.
 *
 * LibWARC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LibWARC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libwget.  If not, see <https://www.gnu.org/licenses/>.
 */

/*
 * Header file for libwarc library routines
 */
/// \file

#ifndef LIBWARC_LIBWARC_H
#define LIBWARC_LIBWARC_H


// see https://www.gnu.org/software/gnulib/manual/html_node/Exported-Symbols-of-Shared-Libraries.html
#if defined BUILDING_LIBWARC && HAVE_VISIBILITY
#       define WARCAPI __attribute__ ((__visibility__("default")))
#elif defined BUILDING_LIBWARC && defined _MSC_VER && !defined LIBWARC_STATIC
#       define WARCAPI __declspec(dllexport)
#elif defined _MSC_VER && !defined LIBWARC_STATIC
#       define WARCAPI __declspec(dllimport)
#else
#       define WARCAPI
#endif


WARCAPI int print_hw(int);

#endif /* LIBWARC_LIBWARC_H */
