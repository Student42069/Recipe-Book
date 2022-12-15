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

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_load_recipes(void)
{
    // Create a new recipes_book instance
    recipes_book book;
    recipes_book_initialize(&book);

    // Load the recipes from the test file
    char* file_name = "test_recipes.txt";
    load_recipes(file_name, &book);

    // Check that the correct number of categories was loaded
    CU_ASSERT_EQUAL(book.num_categories, 4);

    // Check that the "poulet" category was loaded correctly
    struct category_node* poulet_category = book.first;
    CU_ASSERT_STRING_EQUAL(poulet_category->category, "poulet");
    CU_ASSERT_EQUAL(poulet_category->num_recipes, 2);

    // Check that the first recipe in the "poulet" category is "Poulet au romarin"
    struct recipe_node* poulet_recipe = poulet_category->recipes;
    CU_ASSERT_STRING_EQUAL(poulet_recipe->name, "Poulet au romarin");

    // Check that the "vegetarien" category was loaded correctly
    struct category_node* vegetarien_category = poulet_category->next;
    CU_ASSERT_STRING_EQUAL(vegetarien_category->category, "vegetarien");
    CU_ASSERT_EQUAL(vegetarien_category->num_recipes, 1);

    // Check that the first recipe in the "vegetarien" category is "Salade du jardin"
    struct recipe_node* vegetar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "main.h"
#include "linkedList.h"

// Test function for load_one_recipe()
void test_load_one_recipe(void) {
    recipes_book book;
    recipes_book_initialize(&book);

    char buffer[MAX_LINE_LENGTH] = "Banana Bread [Breakfast, Dessert]";

    // Test adding a recipe to the book
    load_one_recipe(buffer, &book);
    CU_ASSERT_EQUAL(book.num_categories, 2);

    struct category_node *current = book.first;
    CU_ASSERT_EQUAL(strcmp(current->category, "Breakfast"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);

    current = current->next;
    CU_ASSERT_EQUAL(strcmp(current->category, "Dessert"), 0);
    CU_ASSERT_EQUAL(current->num_recipes, 1);
    CU_ASSERT_EQUAL(strcmp(current->recipes->name, "Banana Bread"), 0);
}

// Add test suites and test cases to the CUnit registry
int main(void) {
    CU_pSuite pSuite = NULL;

    // Initial

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
    buffer[0]

void run_prompt(recipes_book *book) {
    char query[MAX_LINE_LENGHT];
    while (1) {
        printf("Entrez votre critère de recherche :\n");
        scanf("%[^\n]", query);

        if (strcmp(query, "exit") == 0) {
            break;
        } else if (strchr(query, ' ') == NULL) {
            search_by_category(book, query);
        } else {
            char *keyword = strchr(query, ' ') + 1;
            *strchr(query, ' ') = '\0';
            if (strchr(keyword, ' ') != NULL) {
                printf("Critère de recherche invalide.\n");
            } else {
               search_by_category_and_keyword(book, query, keyword);
            }
        }
    }
}

//-------------------------------------------------
int num_unique_words(char *file_name)
{
  // Open the input file
  FILE *file = open_file(file_name, "r");

  // Create a linked list to store the unique words
  linked_list *list = linked_list_initialize();

  // Initialize the unique word count
  int count = 0;

  // Read each line from the file
  char buffer[MAX_LINE_LENGHT];
  while (fgets(buffer, MAX_LINE_LENGHT, file) != NULL)
  {
    // Split the line into words
    char *word = strtok(buffer, " ");

    // Iterate over the words in the line
    while (word != NULL)
    {
      // Check if the current word is already in the list of unique words
      if (!linked_list_contains(list, word))
      {
        // Add the word to the list of unique words
        linked_list_add(list, word);
        count++;
      }

      // Move to the next word in the line
      word = strtok(NULL, " ");
    }
  }

  // Free the memory allocated for the linked list
  linked_list_free(list);

  // Close the input file
  close_file(file);

  // Return the number of unique words
  return count;
}
//Note that this implementation uses a linked list data structure to store the unique words. You will need to implement the linked_list and linked_list_node structures, as well as the functions linked_list_initialize(), linked_list_add(), linked_list_contains(), and linked_list_free() to use this implementation. You can refer to the linked list data structure documentation for more information on how to implement these functions.
//===============================================
int num_unique_words(char *recipes_file_name)
{
  // Open the input file
  FILE *file = open_file(recipes_file_name, "r");

  // Initialize a set to store the unique words
  set *words = set_initialize();

  // Read each line from the file
  char buffer[MAX_LINE_LENGHT];
  while (fgets(buffer, MAX_LINE_LENGHT, file) != NULL)
  {
    // Iterate over the words in the line
    char *word = strtok(buffer, " ");
    while (word != NULL)
    {
      // Add the word to the set
      set_add(words, word);

      // Get the next word
      word = strtok(NULL, " ");
    }
  }

  // Close the input file
  close_file(file);

  // Get the number of unique words in the set
  int num_words = set_size(words);

  // Free the set
  set_free(words);

  // Return the number of unique words in the file
  return num_words;
}
//Note that this implementation uses the strtok() function from the string.h header file to iterate over the words in each line, and the set_add(), set_size(), and set_free() functions from a set implementation to store the unique words and get their count. It also uses the open_file() and close_file() functions from the previous example to open and close the input file. Finally, it iterates over the words in each line and adds them to the set, and then returns the number of unique words in the set.
//=====================================
