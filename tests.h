#include <stdio.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "main.h"

void test_open_file(void);
void test_close_file(void);
void test_check_args(void);

// void test_open_file() {
//     // Try opening a file that doesn't exist
//     FILE *fp = open_file("nonexistent.txt", "r");
//     assert_null(fp);

//     // Try opening a file that exists
//     fp = open_file("existing.txt", "r");
//     assert_non_null(fp);
//     fclose(fp);
// }

// void test_check_args() {
//     // Check the case where no arguments are passed
//     char *argv[] = {};
//     check_args(0, argv);

//     // Check the case where a single file name is passed
//     char *argv1[] = { "recherche", "recipes.txt" };
//     check_args(2, argv1);

//     // Check the case where the '-S' flag and two file names are passed
//     char *argv2[] = { "recherche", "recipes.txt", "-S", "stats.txt" };
//     check_args(4, argv2);

//     // Check the case where the wrong arguments are passed
//     char *argv3[] = { "recherche", "recipes.txt", "-X", "stats.txt" };
//     expect_exit(ERREUR_ARGS, check_args, 4, argv3);
// }

// int main() {
//     CU_initialize_registry();

//     CU_pSuite suite = CU_add_suite("Test suite", NULL, NULL);
//     CU_add_test(suite, "test_open_file", test_open_file);
//     CU_add_test(suite, "test_check_args", test_check_args);

//     CU_basic_set_mode(CU_BRM_VERBOSE);
//     CU_basic_run_tests();

//     CU_cleanup_registry();
//     return 0;
// }