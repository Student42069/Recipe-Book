struct recipe_node* get_recipe(recipes_book *book, const char *category, const char *recipe_name) {
    struct category_node *current_category = book->first;
    while (current_category) {
        if (strcmp(current_category->category, category) == 0) {
            // Found the category, now search for the recipe
            struct recipe_node *current_recipe = current_category->recipes;
            while (current_recipe) {
                if (strcmp(current_recipe->name, recipe_name) == 0) {
                    // Found the recipe, return its address
                    return current_recipe;
                }
                current_recipe = current_recipe->next;
            }
            // Recipe was not found in this category
            return NULL;
        }
        current_category = current_category->next;
    }
    // Category was not found in the book
    return NULL;
}

struct recipe_node* get_recipe(recipes_book *book, const char *recipe_name) {
    struct category_node *current_category = book->first;
    while (current_category) {
        // Search for the recipe in this category
        struct recipe_node *current_recipe = current_category->recipes;
        while (current_recipe) {
            if (strcmp(current_recipe->name, recipe_name) == 0) {
                // Found the recipe, return its address
                return current_recipe;
            }
            current_recipe = current_recipe->next;
        }
        // Recipe was not found in this category, move on to the next
        current_category = current_category->next;
    }
    // Recipe was not found in any category
    return NULL;
}

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>

#include "main.h"
#include "linkedList.h"

// Test fixture
static recipes_book book;

static void test_load_recipes_setup() {
    recipes_book_initialize(&book);
}

static void test_load_recipes_teardown() {
    recipes_book_free(&book);
}

static void test_load_recipes() {
    char file_name[] = "test_recipes.txt";
    char* expected_recipe_names[] = { "Spaghetti Carbonara", "Chicken Parmesan", "Baked Ziti" };
    char* expected_categories[] = { "Italian", "Italian", "Italian" };
    int num_expected_recipes = 3;
    int num_expected_categories = 1;

    load_recipes(file_name, &book);

    // Check that the correct number of categories and recipes were loaded
    CU_ASSERT_EQUAL(book.num_categories, num_expected_categories);
    struct category_node *current_category = book.first;
    while (current_category) {
        CU_ASSERT_EQUAL(current_category->num_recipes, num_expected_recipes);
        current_category = current_category->next;
    }

    // Check that the correct recipes and categories were loaded
    for (int i = 0; i < num_expected_recipes; ++i) {
        struct recipe_node *recipe = get_recipe(&book, expected_recipe_names[i]);
        CU_ASSERT_PTR_NOT_NULL_FATAL(recipe);
        CU_ASSERT_STRING_

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

// Import the function you want to test
#include "main.h"

// Define a test case for the load_recipes function
void test_load_recipes(void) {
    // Create a recipes book to load the recipes into
    recipes_book book;
    recipes_book_initialize(&book);

    // Create a test recipe file with two recipes
    FILE *fp = fopen("test_recipes.txt", "w");
    fprintf(fp, "recipe1 [category1]\nrecipe2 [category2]");
    fclose(fp);

    // Load the recipes from the test file
    load_recipes("test_recipes.txt", &book);

    // Check that the book has two categories
    CU_ASSERT_EQUAL(book.num_categories, 2);

    // Check that the first category has the correct name and contains the first recipe
    struct category_node *category1 = book.first;
    CU_ASSERT_STRING_EQUAL(category1->category, "category1");
    CU_ASSERT_EQUAL(category1->num_recipes, 1);
    CU_ASSERT_STRING_EQUAL(category1->recipes->name, "recipe1");

    // Check that the second category has the correct name and contains the second recipe
    struct category_node *category2 = category1->next;
    CU_ASSERT_STRING_EQUAL(category2->category, "category2");
    CU_ASSERT_EQUAL
