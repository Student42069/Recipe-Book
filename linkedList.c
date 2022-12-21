#include "linkedList.h"

recipes_book *recipes_book_initialize() {
    recipes_book *book;
    if(!(book = (recipes_book*) malloc(sizeof(recipes_book))))
        throw_malloc_error();
    book->first = NULL;
    book->num_categories = 0;
    return book;
}

void recipes_book_add_category(recipes_book *book, const char *category) {
    struct category_node *current = book->first;
    struct category_node *previous = NULL;
    if (current == NULL) {
        add_initial_category(book, category);
        return;
    }

    while (current) {
        if (strcmp(current->name, category) == 0) {
            return;
        } else if (strcmp(current->name, category) < 0) {
            previous = current;
            current = current->next;
        } else {
            break;
        }
    }

    if (previous == NULL) {
        book->first = add_first_category(current, category);
    } else {
        add_category(previous, category);
    }

    ++book->num_categories;
}

void add_initial_category(recipes_book *book, const char *category) {
    struct category_node *current = book->first;
    current = (struct category_node*)malloc(sizeof(struct category_node));
    if(!(current->name = malloc(strlen(category) + 1)))
        throw_malloc_error();
    strcpy(current->name, category);
    current->num_recipes = 0;
    current->recipes = NULL;
    current->next = NULL;
    book->first = current;
    ++book->num_categories;
}

struct category_node* add_first_category(struct category_node *current, const char *category) {
    struct category_node* new_node;
	new_node = (struct category_node*)malloc(sizeof(struct category_node));
    if(!(new_node->name = malloc(strlen(category) + 1)))
        throw_malloc_error();
    strcpy(new_node->name, category);
    new_node->num_recipes = 0;
    new_node->recipes = NULL;
    new_node->next = current;
    return new_node;
}

void add_category(struct category_node *previous, const char *category) {
    struct category_node* new_node;
	new_node = (struct category_node*) malloc(sizeof(struct category_node));
    if(!(new_node->name = malloc(strlen(category) + 1)))
        throw_malloc_error();
    strcpy(new_node->name, category);
    new_node->num_recipes = 0;
    new_node->recipes = NULL;
    new_node->next = previous->next;
    previous->next = new_node;
}

void recipes_book_add_recipe(recipes_book *book, const char *category, const char *recipe) {
    recipes_book_add_category(book, category);
    struct category_node *current = book->first;

    while(strcmp(current->name, category) != 0) {
        current = current->next;
    }

    add_recipe(current, recipe);
}

void add_recipe(struct category_node *category, const char *recipe) {
    struct recipe_node *current = category->recipes;
    struct recipe_node *previous = NULL;

    if (current == NULL) {
        add_initial_recipe(category, recipe);
        return;
    }

    while (current) {
        if (strcmp(current->name, recipe) == 0) {
            return;
        } else if (strcmp(current->name, recipe) < 0) {
            previous = current;
            current = current->next;
        } else {
            break;
        }
    }

    if (previous == NULL) {
        category->recipes = add_first_recipe(current, recipe);
    } else {
        add_this_recipe(previous, recipe);
    }

    ++category->num_recipes;
}

void add_initial_recipe(struct category_node *category, const char *recipe) {
    struct recipe_node *current = category->recipes;

    current = (struct recipe_node*)malloc(sizeof(struct recipe_node));

    strcpy(current->name, recipe);
    current->next = NULL;

    category->recipes = current;
    ++category->num_recipes;
}

struct recipe_node* add_first_recipe(struct recipe_node *current, const char *recipe) {
    struct recipe_node* new_node;
	new_node = (struct recipe_node*)malloc(sizeof(struct recipe_node));
    
    strcpy(new_node->name, recipe);
    new_node->next = current;

    return new_node;
}

void add_this_recipe(struct recipe_node *previous, const char *recipe) {
    struct recipe_node* new_node;
	new_node = (struct recipe_node*)malloc(sizeof(struct recipe_node));
    
    strcpy(new_node->name, recipe);
    new_node->next = previous->next;
    
    previous->next = new_node;
}

struct recipe_node* get_recipe(recipes_book *book, const char *recipe_name) {
    struct category_node *current_category = book->first;
    while (current_category) {
        struct recipe_node *current_recipe = current_category->recipes;
        while (current_recipe) {
            if (strcmp(current_recipe->name, recipe_name) == 0)
                return current_recipe;
            current_recipe = current_recipe->next;
        }
        current_category = current_category->next;
    }
    return NULL;
}

void free_recipe_book(recipes_book *book) {
    struct category_node *current = book->first;
    struct category_node *previous;
    while(current){
        previous = current;
        current = current->next;
        free_recipes(previous);
        free(previous->name);
        free(previous);
    }
    free(book);
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

void throw_malloc_error() {
    puts("Une erreur d'allocation de memoire s'est produite.");
    exit(7);
}