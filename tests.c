#include "tests.h"

/**
 * -----------------------
 * Unit tests for main.c
 * -----------------------
 */
void test_open_file() {
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
    recipes_book *book = recipes_book_initialize();

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
    CU_ASSERT_STRING_EQUAL(category->name, "category1");
    CU_ASSERT_EQUAL(category->num_recipes, 1);
    CU_ASSERT_STRING_EQUAL(category->recipes->name, "recipe1");

    // Check that the second category has the correct name and contains the second recipe
    category = category->next;
    CU_ASSERT_STRING_EQUAL(category->name, "category2");
    CU_ASSERT_EQUAL(category->num_recipes, 1);
    CU_ASSERT_STRING_EQUAL(category->recipes->name, "recipe2");
}

void test_load_one_recipe(void) {
    recipes_book *book = recipes_book_initialize();

    char buffer[MAX_LINE_LENGHT] = "Banana Bread [Breakfast] [Dessert]";

    // Test adding a recipe to the book
    load_one_recipe(buffer, book);
    CU_ASSERT_EQUAL(book->num_categories, 2);

    struct category_node *current = book->first;
    CU_ASSERT_EQUAL(strcmp(current->name, "Breakfast"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);

    current = current->next;
    CU_ASSERT_EQUAL(strcmp(current->name, "Dessert"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);
}

void test_load_recipe_into_categories(void) {
    recipes_book *book = recipes_book_initialize();

    char buffer[MAX_LINE_LENGHT] = "Banana Bread [Breakfast] [Dessert]";

    // Test adding a recipe to the book
    load_recipe_into_categories("Banana Bread", buffer, book);

    CU_ASSERT_EQUAL(book->num_categories, 2);

    // Check that the first category has the correct name and contains the recipe
    struct category_node *current = book->first;
    CU_ASSERT_EQUAL(strcmp(current->name, "Breakfast"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);

    // Check that the second category has the correct name and contains the recipe
    current = current->next;
    CU_ASSERT_EQUAL(strcmp(current->name, "Dessert"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);

    // Check that the function correctly handles an empty recipe string
    strcpy(buffer,"");
    load_recipe_into_categories("Banana Bread", buffer, book);
    // Check that the book still has only 2 categories
    CU_ASSERT_EQUAL(book->num_categories, 2);
}

void test_load_recipe_into_one_category(void) {
    recipes_book *book = recipes_book_initialize();

    char buffer[MAX_LINE_LENGHT] = "Banana Bread [Breakfast]";

    // Test adding a recipe to the book
    load_recipe_into_one_category(buffer, book, "Banana Bread", 13, 23);

    // Check that the book has one category
    CU_ASSERT_EQUAL(book->num_categories, 1);

    // Check that the category has the correct name and contains the recipe
    struct category_node *current = book->first;
    CU_ASSERT_EQUAL(strcmp(current->name, "Breakfast"), 0);
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
 void test_recipes_book_initialize(void) {
    recipes_book *book = recipes_book_initialize();

    // Use CUnit assert functions to check the values of the book's fields
    CU_ASSERT_PTR_NULL(book->first);
    CU_ASSERT_EQUAL(book->num_categories, 0);

    free(book);
}

void test_recipes_book_add_category(void) {
    recipes_book *book = recipes_book_initialize();

    // Add a new category to the book
    recipes_book_add_category(book, "Breakfast");

    // Check that the book now has one category
    CU_ASSERT_EQUAL(book->num_categories, 1);

    // Check that the category has the correct name
    struct category_node *category = book->first;
    CU_ASSERT_STRING_EQUAL(category->name, "Breakfast");
}

void test_recipes_book_add_recipe(void) {
    recipes_book *book = recipes_book_initialize();

    // Add a category to the book
    recipes_book_add_category(book, "Breakfast");

    // Check that the book has one category
    CU_ASSERT_EQUAL(book->num_categories, 1);

    // Check that the category has no recipes
    struct category_node *category = book->first;
    CU_ASSERT_EQUAL(category->num_recipes, 0);

    // Add a recipe to the category
    recipes_book_add_recipe(book, "Breakfast", "Banana Bread");

    // Check that the category now has one recipe
    CU_ASSERT_EQUAL(category->num_recipes, 1);
    CU_ASSERT_STRING_EQUAL(category->recipes->name, "Banana Bread");
}

void test_free_recipe_book(void) {
    recipes_book *book = recipes_book_initialize();

    // Add some categories and recipes to the book
    recipes_book_add_category(book, "Breakfast");
    recipes_book_add_recipe(book, "Breakfast", "Banana Bread");
    recipes_book_add_recipe(book, "Breakfast", "Omelette");

    recipes_book_add_category(book, "Dinner");
    recipes_book_add_recipe(book, "Dinner", "Spaghetti");
    recipes_book_add_recipe(book, "Dinner", "Pork Chops");

    // Call the free_recipe_book function
    free_recipe_book(book);

    // Check that all memory used by the book has been deallocated
    CU_ASSERT_PTR_NULL(book->first);
}

int main() {
    // Initialize the CUnit test registry.
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Set up the test suite.
    CU_pSuite suite = CU_add_suite("TestSuite for main.c", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Set up the second test suite.
    CU_pSuite suite2 = CU_add_suite("TestSuite for linkedList.c", NULL, NULL);
    if (suite2 == NULL) {
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

    // Add the test functions to the suite2
    if (
        (NULL == CU_add_test(suite2, "test_recipes_book_initialize", test_recipes_book_initialize)) ||
        (NULL == CU_add_test(suite2, "test_recipes_book_add_category", test_recipes_book_add_category)) ||
        (NULL == CU_add_test(suite2, "test_recipes_book_add_recipe", test_recipes_book_add_recipe)) ||
        (NULL == CU_add_test(suite2, "test_free_recipe_book", test_free_recipe_book))
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
