#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGHT 120

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct category_node {
    char *category;
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

recipes_book *recipes_book_initialize();

void recipes_book_add_category(recipes_book *book, const char *category);

void recipes_book_add_recipe(recipes_book *book, const char *category, const char *recipe);

void add_recipe(struct category_node *category, const char *recipe);

void add_this_recipe(struct recipe_node *previous, const char *recipe);

void add_category(struct category_node *previous, const char *category);

struct category_node* add_first_category(struct category_node *current, const char *category);

struct recipe_node* add_first_recipe(struct recipe_node *current, const char *recipe);

struct recipe_node* get_recipe(recipes_book *book, const char *recipe_name);

void free_recipe_book(recipes_book *book);

void free_recipes(struct category_node *category);

void print_book(recipes_book *book);

void print_recipes(struct recipe_node *recipe);


#endif
