#include "tests.h"

/**
 * -----------------------
 * Unit tests for main.c
 * -----------------------
 */
void test_open_file() {
    // Try opening a file that exists
    FILE* fptr = open_file("test/banque_vide.txt", "r");
    CU_ASSERT_PTR_NOT_NULL(fptr);
    fclose(fptr);
}

void test_close_file() {
    FILE* fptr = fopen("test/banque_vide.txt", "r");
    close_file(fptr);
    CU_ASSERT_EQUAL(0, 0);
}

void test_check_args() {
    // Test with valid number of arguments and valid recipe file.
    int argc = 2;
    char* argv2[] = { "./recherche", "test/banque1.txt" };
    check_args(argc, argv2);
    CU_ASSERT_EQUAL(1, 1);

    // Test with valid number of arguments and valid statistics arguments.
    argc = 4;
    char* argv4[] = { "./recherche", "test/banque1.txt" , "-S", "stats.txt" };
    check_args(argc, argv4);
    CU_ASSERT_EQUAL(1, 1);
}

void test_load_recipes(void) {
    // Create a recipes book to load the recipes into
    recipes_book *book;
    recipes_book_initialize(book);

    // Create a test recipe file with two recipes
    FILE *fp = fopen("test_recipes.txt", "w");
    fprintf(fp, "recipe1 [category1]\nrecipe2 [category2]");
    fclose(fp);

    // // Load the recipes from the test file
    load_recipes("test_recipes.txt", book);

    // // Check that the book has two categories
    CU_ASSERT_EQUAL(book->num_categories, 2);

    // // Check that the first category has the correct name and contains the first recipe
    struct category_node *category = book->first;
    CU_ASSERT_STRING_EQUAL(category->category, "category1");
    CU_ASSERT_EQUAL(category->num_recipes, 1);
    CU_ASSERT_STRING_EQUAL(category->recipes->name, "recipe1");

    // Check that the second category has the correct name and contains the second recipe
    category = category->next;
    CU_ASSERT_STRING_EQUAL(category->category, "category2");
    CU_ASSERT_EQUAL(category->num_recipes, 1);
    CU_ASSERT_STRING_EQUAL(category->recipes->name, "recipe2");
}

void test_load_one_recipe(void) {
    recipes_book *book;
    recipes_book_initialize(book);

    char buffer[MAX_LINE_LENGHT] = "Banana Bread [Breakfast] [Dessert]";

    // Test adding a recipe to the book
    load_one_recipe(buffer, book);
    CU_ASSERT_EQUAL(book->num_categories, 2);

    struct category_node *current = book->first;
    CU_ASSERT_EQUAL(strcmp(current->category, "Breakfast"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);

    current = current->next;
    CU_ASSERT_EQUAL(strcmp(current->category, "Dessert"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);
}

void test_load_recipe_into_categories(void) {
    // Create a test recipe book
    recipes_book *book;
    recipes_book_initialize(book);

    // Create a test recipe string with two categories
    char buffer[MAX_LINE_LENGHT] = "Banana Bread [Breakfast] [Dessert]";

    // Test adding a recipe to the book
    load_recipe_into_categories("Banana Bread", buffer, book);

    // Check that the book has two categories
    CU_ASSERT_EQUAL(book->num_categories, 2);

    // Check that the first category has the correct name and contains the recipe
    struct category_node *current = book->first;
    CU_ASSERT_EQUAL(strcmp(current->category, "Breakfast"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);

    // Check that the second category has the correct name and contains the recipe
    current = current->next;
    CU_ASSERT_EQUAL(strcmp(current->category, "Dessert"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);

    // Check that the function correctly handles an empty recipe string
    strcpy(buffer,"");

    // Test adding a recipe to the book
    load_recipe_into_categories("Banana Bread", buffer, book);

    // Check that the book still has only 2 categories
    CU_ASSERT_EQUAL(book->num_categories, 2);
}

void test_load_recipe_into_one_category(void) {
    // Create a test recipe book
    recipes_book *book;
    recipes_book_initialize(book);

    // Create a test recipe string with one category
    char buffer[MAX_LINE_LENGHT] = "Banana Bread [Breakfast]";

    // Test adding a recipe to the book
    load_recipe_into_one_category(buffer, book, "Banana Bread", 13, 23);

    // Check that the book has one category
    CU_ASSERT_EQUAL(book->num_categories, 1);

    // Check that the category has the correct name and contains the recipe
    struct category_node *current = book->first;
    CU_ASSERT_EQUAL(strcmp(current->category, "Breakfast"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);
}


void test_get_recipe_name() {
    // First
    char buffer[MAX_LINE_LENGHT] = "Lasagne [plat principal]";
    char expected_name[MAX_LINE_LENGHT] = "Lasagne";
    char result_name[MAX_LINE_LENGHT];
    result_name[0] = '\0';

    get_recipe_name(result_name, buffer);
    CU_ASSERT_STRING_EQUAL(expected_name, result_name);

    // Second
    strcpy(buffer, "Soupe aux pois [soupe]");
    strcpy(expected_name, "Soupe aux pois");
    result_name[0] = '\0';

    get_recipe_name(result_name, buffer);
    CU_ASSERT_STRING_EQUAL(expected_name, result_name);
}

void test_run_prompt() {
    // TODO: Add test cases for the run_prompt function.
}

/**
 * -----------------------
 * Unit tests for linkedList.c
 * -----------------------
 */


int main() {
    // Initialize the CUnit test registry.
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Set up the test suite.
    CU_pSuite suite = CU_add_suite("TestSuite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test functions to the suite
    if (
        (NULL == CU_add_test(suite, "test_open_file", test_open_file)) ||
        (NULL == CU_add_test(suite, "test_close_file", test_close_file)) ||
        (NULL == CU_add_test(suite, "test_check_args", test_check_args)) ||
        (NULL == CU_add_test(suite, "test_load_recipes", test_load_recipes)) ||
        (NULL == CU_add_test(suite, "test_load_one_recipe", test_load_one_recipe)) ||
        (NULL == CU_add_test(suite, "test_load_recipe_into_categories", test_load_recipe_into_categories)) ||
        (NULL == CU_add_test(suite, "test_load_recipe_into_one_category", test_load_recipe_into_one_category)) ||
        (NULL == CU_add_test(suite, "test_get_recipe_name", test_get_recipe_name))
    ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
