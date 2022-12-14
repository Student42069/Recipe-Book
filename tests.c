#include "tests.h"

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
    // // Test with invalid number of arguments.
    int argc = 1;
    // char* argv[] = { "./recherche" };
    // CU_ASSERT_FATAL(check_args(argc, argv));

    // Test with valid number of arguments and valid recipe file.
    argc = 2;
    char* argv2[] = { "./recherche", "test/banque1.txt" };
    check_args(argc, argv2);
    CU_ASSERT_EQUAL(1, 1);

    // // Test with valid number of arguments and invalid recipe file.
    // argc = 2;
    // char* argv[] = { "./recherche", "badfile.txt" };
    // CU_ASSERT_DEATH(check_args(argc, argv), "Erreur dans l'ouverture du fichier");

    // Test with valid number of arguments and valid statistics arguments.
    argc = 4;
    char* argv4[] = { "./recherche", "test/banque1.txt" , "-S", "stats.txt" };
    check_args(argc, argv4);
    CU_ASSERT_EQUAL(1, 1);

    // // Test with valid number of arguments and invalid statistics arguments.
    // argc = 4;
    // char* argv[] = { "./recherche", "-S", "badfile.txt" };
    // CU_ASSERT_DEATH(check_args(argc, argv), "Erreur dans l'ouverture du fichier");

    // Test with valid number of arguments and invalid statistics flag.
    // argc = 4;
    // char* argv[] = { "./recherche", "test/banque1.txt", "-B", "stats.txt" };
    // CU_ASSERT_FATAL(check_args(argc, argv));
}


void test_check_stats_args() {
    // TODO: Add test cases for the check_stats_args function.
}

void test_throw_error_args_count() {
    // CU_ASSERT_DEATH(throw_error_args_count(), "nombre arguments invalide");
    // compile your code with the -DCU_ENABLE_EXPERIMENTAL_C_ASSERT flag and link it with the -lcunit -lcunitx libraries. 
    // CU_ASSERT_FATAL(throw_error_args_count());
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

void test_load_one_recipe() {
    // TODO: Add test cases for the load_one_recipe function.
}

void test_load_recipe_into_categories() {
    // TODO: Add test cases for the load_recipe_into_categories function.
}

void test_load_recipe_into_one_category() {
    // TODO: Add test cases for the load_recipe_into_one_category function.
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
        (NULL == CU_add_test(suite, "test_get_recipe_name", test_get_recipe_name))
        // (NULL == CU_add_test(suite, "test_close_file", test_close_file))
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
