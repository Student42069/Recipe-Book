#include <stdio.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "main.h"
#include "linkedList.h"

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

/**
 * -----------------------
 * Unit tests for main.c
 * -----------------------
 */
void test_open_file(void);
void test_close_file(void);
void test_check_args(void);
void test_load_recipes(void);
void test_load_one_recipe(void);
void test_load_recipe_into_categories(void);
void test_load_recipe_into_one_category(void);
void test_get_recipe_name(void);

/**
 * -----------------------
 * Unit tests for linkedList.c
 * -----------------------
 */
void test_recipes_book_initialize(void);
void test_recipes_book_add_category(void);
void test_recipes_book_add_recipe(void);
void test_free_recipe_book(void);

#endif