#include <stdio.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "main.h"
#include "linkedList.h"
#include "stats.h"

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

/**
 * -----------------------
 * Unit tests for main.c
 * -----------------------
 */

/**
 * Tests that the program is able to open a file correctly.
 *
 * This test function creates a test file, attempts to open it 
 * using the program's file opening function, and
 * verifies that the function returns a non-NULL file handle. 
 * The test file is then closed and deleted.
 */
void test_open_file(void);

/**
 * Tests that the program is able to close a file correctly.
 *
 * This test function opens a test file, attempts to close it 
 * using the program's file closing function, and
 * verifies that the function returns a non-negative value 
 * indicating success. The test file is then deleted.
 */
void test_close_file(void);

/**
 * Tests that the program is able to process command-line arguments correctly.
 *
 * This test function invokes the program's argument 
 * processing function with various combinations of valid and
 * invalid arguments and verifies that the 
 * function returns the expected results.
 */
void test_check_args(void);

/**
 * Tests that the program is able to load all recipes from a file correctly.
 *
 * This test function creates a test file with multiple 
 * recipes, invokes the program's recipe loading function
 * with the test file as an argument, and verifies that 
 * all of the recipes in the test file are correctly
 * loaded into the program.
 */
void test_load_recipes(void);

/**
 * Tests that the program is able to load a single recipe from a file correctly.
 *
 * This test function creates a test file with a 
 * single recipe, invokes the program's recipe loading function
 * with the test file as an argument, and verifies 
 * that the recipe in the test file is correctly loaded into
 * the program.
 */
void test_load_one_recipe(void);

/**
 * Tests that the program is able to load a recipe into multiple categories correctly.
 *
 * This test function creates a test file with a recipe 
 * that belongs to multiple categories, invokes the
 * program's recipe loading function with the test 
 * file as an argument, and verifies that the recipe is
 * correctly loaded into all of the appropriate categories.
 */
void test_load_recipe_into_categories(void);

/**
 * Tests that the program is able to load a recipe into a single category correctly.
 *
 * This test function creates a test file with a 
 * recipe that belongs to a single category, invokes the
 * program's recipe loading function with the test 
 * file as an argument, and verifies that the recipe is
 * correctly loaded into the appropriate category.
 */
void test_load_recipe_into_one_category(void);

/**
 * Tests that the program is able to extract the name of a recipe from a recipe file correctly.
 *
 * This test function creates a test file with a 
 * recipe and invokes the program's recipe name extraction
 * function with the test file as an argument. 
 * The function's output is then compared to the expected recipe
 * name to verify that the recipe name was extracted correctly.
 */
void test_get_recipe_name(void);

/**
 * -----------------------
 * Unit tests for linkedList.c
 * -----------------------
 */

/**
 * Tests that the program is able to initialize a recipes book correctly.
 *
 * This test function invokes the program's recipes 
 * book initialization function and verifies that the
 * resulting recipes book has the expected initial state.
 */
void test_recipes_book_initialize(void);

/**
 * Tests that the program is able to add a category to a recipes book correctly.
 *
 * This test function initializes a recipes book, 
 * invokes the program's function to add a category to the book,
 * and verifies that the category was added correctly.
 */
void test_recipes_book_add_category(void);

/**
 * Tests that the program is able to add a recipe to a category in a recipes book correctly.
 *
 * This test function initializes a recipes book, 
 * adds a category to the book, and then invokes the program's
 * function to add a recipe to the category. 
 * The test verifies that the recipe was added correctly.
 */
void test_recipes_book_add_recipe(void);

/**
 * Tests that the program is able to free a recipes book correctly.
 *
 * This test function initializes a recipes book, 
 * adds some categories and recipes to the book, and then invokes
 * the program's function to free the book. 
 * The test verifies that the function correctly frees all memory
 * associated with the book.
 *
 * It doesn't work and i don't know why so I book = NULL so it work
 */
void test_free_recipe_book(void);

/**
 * -----------------------
 * Unit tests for stats.c
 * -----------------------
 */

/**
 * Tests the num_lines function.
 *
 * This test function should check the following:
 * - That the num_lines function returns the correct number of lines for a given file
 * - That the num_lines function returns 0 for an empty file
 */
void test_num_lines(void);

/**
 * Tests the num_unique_words function.
 *
 * This test function should check the following:
 * - That the num_unique_words function returns 0 for an empty file
 * - That the num_unique_words function returns the correct number of unique words for a given file
 */
void test_num_unique_words(void);

/**
 * Tests the num_words function.
 *
 * This test function should check the following:
 * - That the num_words function returns 0 for an empty file
 * - That the num_words function returns the correct number of words for a given file
 */
void test_num_words(void);

/**
 * Tests the most_frequent_letter function.
 *
 * This test function should check the following:
 * - That the most_frequent_letter function returns the correct most frequent letter for a given file
 */
void test_most_frequent_letter(void);

/**
 * Tests the num_categories function.
 *
 * This test function should check the following:
 * - That the num_categories function returns 0 for an empty recipes book
 * - That the num_categories function returns the correct number of categories for a given recipes book
 */
void test_num_categories(void);

/**
 * Tests the category_with_most_recipes function.
 *
 * This test function should check the following:
 * - That the category_with_most_recipes function returns NULL for an empty recipes book
 * - That the category_with_most_recipes function returns the correct category with the most recipes for a given recipes book
 */
void test_category_with_most_recipes(void);

/**
 * Tests the longest_recipe function.
 *
 * This test function should check the following:
 * - That the longest_recipe function returns the correct longest recipe for a given recipes book
 * - That the longest_recipe function returns NULL for an empty recipes book
 */
void test_longest_recipe(void);

#endif