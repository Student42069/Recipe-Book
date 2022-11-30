#include "linkedList.h"

void recipes_book_initialize(recipes_book *l) {
    l->first = NULL;
    l->num_categories = 0;
}

void recipes_book_add_category(recipes_book *book, const char *category) {
    struct category_node *current = book->first;
    struct category_node *previous;
    // printf("\n\nList elements are - \n");
    if (current == NULL) {
        current = (struct category_node*)malloc(sizeof(struct category_node));
        
        strcpy(current->category, category);
        current->num_recipes = 0;
        current->recipes = NULL;
        current->next = NULL;
        
        book->first = current;
        return;
    }

    while(current) {
        // printf("%s\n",current->category);
        if (strcmp(current->category, category) == 0) {
            return;
        } else if (strcmp(current->category, category) < 0) {
            previous = current;
            current = current->next;
        } else {
            // add_category(previous, category);
            // ++book->num_categories;
            // return;
            break;
        }
    }

    add_category(previous, category);
    ++book->num_categories;

    // puts("ne devrais pas arriver !??!!?");
}

void recipes_book_add_recipe(recipes_book *book, const char *category, const char *recipe) {
    struct category_node *current = book->first;

    while(strcmp(current->category, category) != 0) {
        current = current->next;
    }

    add_recipe(current, recipe);
}

void add_recipe(struct category_node *category, const char *recipe) {
    struct recipe_node *current = category->recipes;
    struct recipe_node *previous;

    if (current == NULL) {
        current = (struct recipe_node*)malloc(sizeof(struct recipe_node));
        strcpy(current->name, recipe);
        current->next = NULL;
        category->recipes = current;
        return;
    }

    while(current) {
        // printf("%s\n",current->category);
        if (strcmp(current->name, recipe) == 0) {
            // add_this_recipe(previous, recipe);
            // ++category->num_recipes;
            // return;
            break;
        } else if (strcmp(current->name, recipe) < 0) {
            previous = current;
            current = current->next;
        } else {
            // add_this_recipe(previous, recipe);
            // ++category->num_recipes;
            // return;
            break;
        }
    }

    add_this_recipe(previous, recipe);
    ++category->num_recipes;

    // puts("ne devrais pas arriver !??!!?");
}

void add_this_recipe(struct recipe_node *previous, const char *recipe) {
    struct recipe_node* new_node;
	new_node = (struct recipe_node*)malloc(sizeof(struct recipe_node));
    strcpy(new_node->name, recipe);
    new_node->next = previous->next;
    previous->next = new_node;
}


void add_category(struct category_node *previous, const char *category) {
    struct category_node* new_node;
	new_node = (struct category_node*)malloc(sizeof(struct category_node));
    
    strcpy(new_node->category, category);
    new_node->num_recipes = 0;
    new_node->recipes = NULL;
    new_node->next = previous->next;

    previous->next = new_node;
}

void free_recipe_book(recipes_book *book) {
    struct category_node *current = book->first;
    struct category_node *previous;
    while(current){
        previous = current;
        current = current->next;
        free_recipes(previous);
        free(previous);
    }
}

void free_recipes(struct category_node *category) {
    struct recipe_node *current = category->recipes;
    struct recipe_node *previous;
    while(current){
        previous = current;
        current = current->next;
        free(previous);
    }
}
