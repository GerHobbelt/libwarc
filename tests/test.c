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

#include <config.h>

#include <stdlib.h>
#include <check.h>

#include "libwarc.h"

START_TEST(test_double)
{
    int x;
    x = print_hw(5);
    ck_assert_int_eq(x, 10);
} END_TEST

Suite *libwarc_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("libwarc");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_double);
    suite_add_tcase(s, tc_core);

    return s;
}

int main()
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = libwarc_suite();
    runner = srunner_create(s);

    srunner_set_tap(runner, "libwarc.tap");
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
