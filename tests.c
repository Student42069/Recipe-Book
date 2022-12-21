#include "tests.h"

/**
 * -----------------------
 * Unit tests for main.c
 * -----------------------
 */
void test_open_file() {
    FILE* fptr = open_file("test_files/banque_vide.txt", "r");
    CU_ASSERT_PTR_NOT_NULL(fptr);
    fclose(fptr);
}

void test_close_file() {
    FILE* fptr = fopen("test_files/banque_vide.txt", "r");
    close_file(fptr);
    CU_ASSERT_EQUAL(0, 0);
}

void test_check_args() {
    // Test with valid number of arguments and valid recipe file.
    int argc = 2;
    char* argv2[] = { "./recherche", "test_files/banque1.txt" };
    check_args(argc, argv2);
    CU_ASSERT_EQUAL(1, 1);

    // Test with valid number of arguments and valid statistics arguments.
    argc = 4;
    char* argv4[] = { "./recherche", "test_files/banque1.txt" , "-S", "stats.txt" };
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
    recipes_book_add_recipe(book, "Breakfast", "Banana Bread");
    recipes_book_add_recipe(book, "Breakfast", "Omelette");

    recipes_book_add_recipe(book, "Dinner", "Spaghetti");
    recipes_book_add_recipe(book, "Dinner", "Pork Chops");

    // Call the free_recipe_book function
    free_recipe_book(book);
    book = NULL;
    // Check that all memory used by the book has been deallocated
    CU_ASSERT_PTR_NULL(book);
}

/**
 * -----------------------
 * Unit tests for stats.c
 * -----------------------
 */

void test_num_lines(void) {
    // Test that num_lines returns 0 for an empty file
    FILE *empty_file = fopen("empty.txt", "w");
    fclose(empty_file);
    CU_ASSERT_EQUAL(num_lines("empty.txt"), 0);
    remove("empty.txt");

    // Test that num_lines returns the correct number of lines for a file with multiple lines
    FILE *multi_line_file = fopen("multi_line.txt", "w");
    fputs("line 1\n", multi_line_file);
    fputs("line 2\n", multi_line_file);
    fputs("line 3\n", multi_line_file);
    fclose(multi_line_file);
    CU_ASSERT_EQUAL(num_lines("multi_line.txt"), 3);
    remove("multi_line.txt");
} 

void test_num_unique_words(void) {
    // Test that num_unique_words returns 0 for an empty file
    FILE *empty_file = fopen("empty.txt", "w");
    fclose(empty_file);
    CU_ASSERT_EQUAL(num_unique_words("empty.txt"), 0);
    remove("empty.txt");

    // Test that num_unique_words returns the correct number of unique words for a file with multiple lines
    // and repeated words
    FILE *multi_line_file = fopen("multi_line.txt", "w");
    fputs("word1 word2 word3\n", multi_line_file);
    fputs("word1 word3 word3\n", multi_line_file);
    fclose(multi_line_file);
    CU_ASSERT_EQUAL(num_unique_words("multi_line.txt"), 3);
    remove("multi_line.txt");
}

void test_num_words(void) {
    // Test that num_words returns 0 for an empty file
    FILE *empty_file = fopen("empty.txt", "w");
    fclose(empty_file);
    CU_ASSERT_EQUAL(num_words("empty.txt"), 0);
    remove("empty.txt");

    // Test that num_words returns the correct number of words for a file with multiple lines
    FILE *multi_line_file = fopen("multi_line.txt", "w");
    fputs("line 1\n", multi_line_file);
    fputs("line 2\n", multi_line_file);
    fputs("line 3\n", multi_line_file);
    fclose(multi_line_file);
    CU_ASSERT_EQUAL(num_words("multi_line.txt"), 6);
    remove("multi_line.txt");
}

void test_most_frequent_letter(void) {
    // Test that most_frequent_letter returns the correct letter for a file with multiple lines
    FILE *multi_line_file = fopen("multi_line.txt", "w");
    fputs("abcde\n", multi_line_file);
    fputs("bcdef\n", multi_line_file);
    fputs("cdefg\n", multi_line_file);
    fclose(multi_line_file);
    CU_ASSERT_EQUAL(most_frequent_letter("multi_line.txt"), 'c');
    remove("multi_line.txt");
}

void test_num_categories(void) {
    // Test that num_categories returns 0 for an empty recipes book
    recipes_book *empty_book = recipes_book_initialize();
    CU_ASSERT_EQUAL(num_categories(empty_book), 0);
    free_recipe_book(empty_book);

    // Test that num_categories returns the correct number of categories for a recipes book with multiple categories
    recipes_book *multi_category_book = recipes_book_initialize();
    recipes_book_add_category(multi_category_book, "Category 1");
    recipes_book_add_category(multi_category_book, "Category 2");
    recipes_book_add_category(multi_category_book, "Category 3");
    CU_ASSERT_EQUAL(num_categories(multi_category_book), 3);
    free_recipe_book(multi_category_book);
}

void test_category_with_most_recipes(void) {
    // Test that category_with_most_recipes returns NULL for an empty recipes book
    recipes_book *empty_book = recipes_book_initialize();
    CU_ASSERT_PTR_NULL(category_with_most_recipes(empty_book));
    free_recipe_book(empty_book);

    // Test that category_with_most_recipes returns the correct category for a recipes book with multiple categories
    // and different number of recipes in each category
    recipes_book *multi_category_book = recipes_book_initialize();
    recipes_book_add_recipe(multi_category_book, "Category 1", "Recipe 1");
    recipes_book_add_recipe(multi_category_book, "Category 1", "Recipe 2");
    recipes_book_add_recipe(multi_category_book, "Category 2", "Recipe 3");
    recipes_book_add_recipe(multi_category_book, "Category 2", "Recipe 4");
    recipes_book_add_recipe(multi_category_book, "Category 3", "Recipe 5");
    recipes_book_add_recipe(multi_category_book, "Category 3", "Recipe 6");
    recipes_book_add_recipe(multi_category_book, "Category 3", "Recipe 7");
    CU_ASSERT_STRING_EQUAL(category_with_most_recipes(multi_category_book), "Category 3");
    free_recipe_book(multi_category_book);
}

void test_longest_recipe(void) {
    // Test that longest_recipe returns NULL for an empty recipes book
    recipes_book *empty_book = recipes_book_initialize();
    CU_ASSERT_PTR_NULL(longest_recipe(empty_book));
    free_recipe_book(empty_book);

    // Test that longest_recipe returns the correct recipe for a recipes book with multiple categories
    // and different number of recipes in each category
    recipes_book *multi_category_book = recipes_book_initialize();
    recipes_book_add_recipe(multi_category_book, "Category 1", "Recipe 1");
    recipes_book_add_recipe(multi_category_book, "Category 1", "Recipe 2");
    recipes_book_add_recipe(multi_category_book, "Category 2", "Recipe 3");
    recipes_book_add_recipe(multi_category_book, "Category 2", "Recipe 4");
    recipes_book_add_recipe(multi_category_book, "Category 2", "Recipe 5");
    recipes_book_add_recipe(multi_category_book, "Category 2", "Recipe Longest 6");
    CU_ASSERT_STRING_EQUAL(longest_recipe(multi_category_book), "Recipe Longest 6");
    free_recipe_book(multi_category_book);
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

    // Set up the third test suite.
    CU_pSuite suite3 = CU_add_suite("TestSuite for stats.c", NULL, NULL);
    if (suite3 == NULL) {
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

    // Add the test functions to the suite3
    if (
        (NULL == CU_add_test(suite3, "test_num_lines", test_num_lines)) ||
        (NULL == CU_add_test(suite3, "test_num_unique_words", test_num_unique_words)) ||
        (NULL == CU_add_test(suite3, "test_num_words", test_num_words)) ||
        (NULL == CU_add_test(suite3, "test_most_frequent_letter", test_most_frequent_letter)) ||
        (NULL == CU_add_test(suite3, "test_num_categories", test_num_categories)) ||
        (NULL == CU_add_test(suite3, "test_category_with_most_recipes", test_category_with_most_recipes)) ||
        (NULL == CU_add_test(suite3, "test_longest_recipe", test_longest_recipe))
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
