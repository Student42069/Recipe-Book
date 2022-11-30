#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct category_node {
    char *category;
    unsigned int num_recipes;
    struct recipe_node *recipes;
    struct category_node *next;
};

struct recipe_node {
    char *name;
    struct recipe_node *next;
};

typedef struct {
    struct category_node *first;
    unsigned int num_categories;
} recipes_book;

void recipes_book_initialize(recipes_book *l);

void recipes_book_add_category(recipes_book *book, const char *category);

void recipes_book_add_recipe(recipes_book *head_ref, const char *category, const char *recipe);

void add_recipe(struct category_node *category, const char *recipe);

void add_this_recipe(struct recipe_node *previous, const char *recipe);

void add_category(struct category_node *previous, const char *category);

void free_recipe_book(recipes_book *book);

void free_recipes(struct category_node *category);

#endif
