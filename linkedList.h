#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGHT 120

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct category_node {
    char *name;
    unsigned int num_recipes;
    struct recipe_node *recipes;
    struct category_node *next;
};

struct recipe_node {
    char name[MAX_LINE_LENGHT];
    struct recipe_node *next;
};

typedef struct {
    struct category_node *first;
    unsigned int num_categories;
} recipes_book;

/**
 * Initialize a recipe book, allocating memory and returning its adress
 *
 * @return pointer to a recipe book struct
 */
recipes_book *recipes_book_initialize();

/**
 * Adds a category to the recipe book
 * This is the main function that handles all cases of where to
 * add a given category
 *
 * @param book the recipes book
 * @param category the category to add
 */
void recipes_book_add_category(recipes_book *book, const char *category);

/**
 * Adds a category to a recipe book
 * Handles the case when it's the first category to be addded
 *
 * @param book the recipes book
 * @param category the category to add
 */
void add_initial_category(recipes_book *book, const char *category);

/**
 * Adds a category to a recipe book
 * Handles the case when the new category should be the first one
 *
 * @param current pointer to a category_node
 * @param category the category to add
 * 
 * @return pointer to the added category_node
 */
struct category_node* add_first_category(struct category_node *current, const char *category);

/**
 * Adds a category to a recipe book
 * Handles all others cases
 *
 * @param book the recipes book
 * @param category the category to add
 */
void add_category(struct category_node *previous, const char *category);

/**
 * Goes through the categories to find the one in which the recipe
 * should be added
 *
 * @param book the recipes book
 * @param category in what category to add the recipe
 * @param recipe the recipe to add
 */
void recipes_book_add_recipe(recipes_book *book, const char *category, const char *recipe);

/**
 * Adds a recipe to the recipe book
 * This is the main function that handles all cases of where to
 * add a given recipe
 *
 * @param book the recipes book
 * @param category in what category to add the recipe
 * @param recipe the recipe to add
 */
void add_recipe(struct category_node *category, const char *recipe);

/**
 * Adds a recipe to a recipe book
 * Handles the case when it's the first recipe to be addded
 *
 * @param category pointer to the category_node in which the recipe
 *                 will be added
 * @param recipe the recipe to add
 */
void add_initial_recipe(struct category_node *category, const char *recipe);

/**
 * Adds a recipe to a recipe book
 * Handles the case when the new recipe should be the first one
 *
 * @param current pointer to a recipe_node
 * @param recipe the recipe to add
 * 
 * @return pointer to the added recipe_node
 */
struct recipe_node* add_first_recipe(struct recipe_node *current, const char *recipe);

/**
 * Adds a recipe to a recipe book
 * Handles all others cases
 *
 * @param category pointer to the category_node in which the recipe
 *                 will be added
 * @param recipe the recipe to add
 */
void add_this_recipe(struct recipe_node *previous, const char *recipe);

/**
 * Searches through the book to find and return a pointer to a recipe with the given name.
 *
 * @param book the recipes book to search through
 * @param recipe_name the name of the recipe to search for
 * @return a pointer to the recipe node with the given name, or NULL if no such recipe is found
 */
struct recipe_node* get_recipe(recipes_book *book, const char *recipe_name);

/**
 * Frees all the dinamically allocated memory used for a recipe_book
 *
 * @param book the recipes book to free
 */
void free_recipe_book(recipes_book *book);

/**
 * Frees all the dinamically allocated memory used for recipes in a
 * given category_node
 *
 * @param category the category in which the recipe_node will be freed
 */
void free_recipes(struct category_node *category);

/**
 * Prints an error message when a memory allocation error occurs 
 * and exit the program.
 *
 * This function is called when a call to malloc or calloc fails to 
 * allocate memory. It prints an error message indicating that a 
 * memory allocation error occurred and exits the program with 
 * a 7 exit status.
 */
void throw_malloc_error();

#endif
