/*
 * Copyright (C) 2020 Free Software Foundation, Inc.
 *
 * This file is part of libWARC.
 *
 * libwarc is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libwarc is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libwarc.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#include "libwarc.h"

int main()
{
    int x;
    x = print_hw(2);
    printf ("2*2 = %d\n", x);
    return 0;
}
