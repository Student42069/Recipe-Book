#include "tests.h"

// void test_open_file(void) {
//     // Test opening a file in read mode
//     FILE *fp = open_file("test_file.txt", "r");
//     CU_ASSERT_PTR_NOT_NULL(fp);
//     close_file(fp);

//     // Test opening a file in write mode
//     fp = open_file("test_file.txt", "w");
//     CU_ASSERT_PTR_NOT_NULL(fp);
//     close_file(fp);
// }

// void test_close_file(void) {
//     // Test closing a file
//     FILE *fp = open_file("test_file.txt", "r");
//     CU_ASSERT_EQUAL(close_file(fp), 0);
// }

// void test_check_args(void) {
//     // Test valid arguments
//     int argc1 = 2;
//     char *argv1[] = {"./recherche", "test_file.txt"};
//     check_args(argc1, argv1);

//     int argc2 = 4;
//     char *argv2[] = {"./recherche", "-S", "test_file.txt", "test_file2.txt"};
//     check_args(argc2, argv2);

//     // Test invalid argument count
//     int argc3 = 1;
//     char *argv3[] = {"./recherche"};
//     CU_ASSERT_EQUAL(check_args(argc3, argv3), ERREUR_NB_ARGS);

//     int argc4 = 3;
//     char *argv4[] = {"./recherche", "test_file.txt", "test_file2.txt"};
//     CU_ASSERT_EQUAL(check_args(argc4, argv4), ERREUR_NB_ARGS);

//     int argc5 = 5;
//     char *argv5[] = {"./recherche", "-S", "test_file.txt", "test_file2.txt", "test_file3.txt"};
//     CU_ASSERT_EQUAL(check_args(argc5, argv5), ERREUR_NB_ARGS);

//     // Test invalid arguments
//     int argc6 = 4;
//     char *argv6[] = {"./recherche", "-X", "test_file.txt", "test_file2.txt"};
//     CU_ASSERT_EQUAL(check_args(argc6, argv6), ERREUR_ARGS);
// }

void test_check_args() {
    // Check the case where no arguments are passed
    char *argv[] = {};
    check_args(0, argv);

    // Check the case where a single file name is passed
    char *argv1[] = { "recherche", "recipes.txt" };
    check_args(2, argv1);

    // Check the case where the '-S' flag and two file names are passed
    char *argv2[] = { "recherche", "recipes.txt", "-S", "stats.txt" };
    check_args(4, argv2);

    // Check the case where the wrong arguments are passed
    char *argv3[] = { "recherche", "recipes.txt", "-X", "stats.txt" };
    expect_exit(ERREUR_ARGS, check_args, 4, argv3);
}

// /* Test suite for the check_args function */
// void test_check_args(void) {
//     /* Test 1: Check that the function correctly handles the case where two arguments are passed (interactive mode) */
//     const int argc1 = 2;
//     char *argv1[] = {"recherche", "recipes.txt"};
//     check_args(argc1, argv1);

//     /* Test 2: Check that the function correctly handles the case where four arguments are passed (statistics mode) */
//     const int argc2 = 4;
//     char *argv2[] = {"recherche", "-S", "stats.txt", "recipes.txt"};
//     check_args(argc2, argv2);

//     /* Test 3: Check that the function correctly handles the case where the wrong number of arguments are passed */
//     const int argc3 = 1;
//     char *argv3[] = {"recherche"};
//     CU_ASSERT_EXIT(check_args(argc3, argv3));
// }

// /* Test suite for the check_stats_args function */
// void test_check_stats_args(void) {
//     /* Test 1: Check that the function correctly handles the case where valid arguments are passed */
//     char *argv1[] = {"recherche", "-S", "stats.txt", "recipes.txt"};
//     check_stats_args(argv1);

//     /* Test 2: Check that the function correctly handles the case where the second argument is invalid */
//     char *argv2[] = {"recherche", "-X", "stats.txt", "recipes.txt"};
//     CU_ASSERT_EXIT(check_stats_args(argv2));

//     /* Test 3: Check that the function correctly handles the case where the third argument is missing */
//     char *argv3[] = {"recherche", "-S", "recipes.txt"};
//     CU_ASSERT_EXIT(check_stats_args(argv3));
// }

// /* Test suite for the load_one_recipe function */
// void test_load_one_recipe(void) {
//     recipes_book book;
//     recipes_book_initialize(&book);

//     /* Test 1: Check that the function correctly loads a recipe into the book */
//     load_one_recipe("Chicken Soup [Soups]", &book);
//     CU_ASSERT_TRUE(recipes_book_contains(&book, "Soups", "Chicken Soup"));

//     /* Test 2: Check that the function correctly loads a recipe with multiple categories */
//     load_one_recipe("Beef Stew [Main Dishes][Stew]", &book);
//     CU_ASSERT_TRUE(recipes_book_contains(&book, "Main Dishes", "Beef Stew"));
//     CU_ASSERT_TRUE(recipes_book_contains(&book, "Stew", "Beef Stew"));

//     /* Test 3: Check that the function correctly handles leading/trailing whitespace */
//     load_one_recipe("   Lemon Cake   [Desserts]   ", &book);
//     CU_ASSERT_TRUE(recipes_book_contains(&book, "Desserts", "Lemon Cake"));

//     free_recipe_book(&book);
// }

void test_load_recipe_into_one_category() {
    // Create a recipes book and a recipe string
    recipes_book book;
    char *recipe_string = "Recipe Name [Category]";

    // Call the function to add the recipe to the book
    load_recipe_into_one_category(recipe_string, &book, "Recipe Name", 10, 21);

    // Check that the recipe was added to the correct category
    assert_true(recipes_book_recipe_in_category(&book, "Category", "Recipe Name"));
}

// int main() {
//     CU_initialize_registry();

//     CU_pSuite load_one_recipe_suite = CU_add_suite("test_load_one_recipe", NULL, NULL);
//     CU_add_test(load_one_recipe_suite, "test_load_one_recipe", test_load_one_recipe);

//     CU_pSuite check_args_suite = CU_add_suite("test_check_args", NULL, NULL);
//     CU_add_test(check_args_suite, "test_check_args", test_check_args);

//     CU_pSuite check_stats_args_suite = CU_add_suite("test_check_stats_args", NULL, NULL);
//     CU_add_test(check_stats_args_suite, "test_check_stats_args", test_check_stats_args);

//     CU_basic_set_mode(CU_BRM_VERBOSE);
//     CU_basic_run_tests();
//     CU_cleanup_registry();

//     return CU_get_error();
// }

int main() {
    // Create a CUnit test suite
    CU_pSuite suite = NULL;
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    suite = CU_add_suite("Test Suite", NULL, NULL);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test functions to the suite
    if (
        (NULL == CU_add_test(suite, "test_check_args", test_check_args)) ||
        (NULL == CU_add_test(suite, "test_load_recipe_into_one_category", test_load_recipe_into_one_category))
        // Add more test functions here
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
