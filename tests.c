#include "tests.h"

void test_open_file() {
    // FILE* fptr = open_file("myfile.txt", "r");
    // CU_ASSERT_PTR_NOT_NULL(fptr);
    // close_file(fptr);

    // // Try opening a file that doesn't exist
    // FILE *fp = open_file("nonexistent.txt", "r");
    // CU_ASSERT_PTR_NULL(fp);

    // // Try opening a file that exists
    // fp = open_file("existing.txt", "r");
    // CU_ASSERT_PTR_NOT_NULL(fp);
    // fclose(fp);
}

void test_close_file() {
    // FILE* fptr = open_file("myfile.txt", "r");
    // int ret = close_file(fptr);
    // CU_ASSERT_EQUAL(ret, 0);
}

void test_check_args() {
    // // Test with invalid number of arguments.
    int argc = 1;
    // char* argv[] = { "./recherche" };
    // CU_ASSERT_DEATH(check_args(argc, argv), "nombre arguments invalide");

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

void test_load_recipes() {
    // TODO: Add test cases for the load_recipes function.
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
    // TODO: Add test cases for the get_recipe_name function.
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
        (NULL == CU_add_test(suite, "test_check_args", test_check_args))
        // (NULL == CU_add_test(suite, "test_close_file", test_close_file))
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

// int main() {
//     // Create a CUnit test suite
//     CU_pSuite suite = NULL;
//     if (CUE_SUCCESS != CU_initialize_registry())
//         return CU_get_error();

//     suite = CU_add_suite("Test Suite", NULL, NULL);
//     if (NULL == suite) {
//         CU_cleanup_registry();
//         return CU_get_error();
//     }

//     // Add the test functions to the suite
//     if (
//         (NULL == CU_add_test(suite, "test_check_args", test_check_args)) ||
//         (NULL == CU_add_test(suite, "test_load_recipe_into_one_category", test_check_args))
//         // Add more test functions here
//     ) {
//         CU_cleanup_registry();
//         return CU_get_error();
//     }

//     // Run the tests
//     CU_basic_set_mode(CU_BRM_VERBOSE);
//     CU_basic_run_tests();
//     CU_cleanup_registry();
//     return CU_get_error();
// }
