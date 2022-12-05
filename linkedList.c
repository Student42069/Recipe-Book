#include "linkedList.h"

void recipes_book_initialize(recipes_book *l) {
    l->first = NULL;
    l->num_categories = 0;
}

void recipes_book_add_category(recipes_book *book, const char *category) {
    struct category_node *current = book->first;
    struct category_node *previous = NULL;
    if (current == NULL) {
        current = (struct category_node*)malloc(sizeof(struct category_node));

        strcpy(current->category, category);

        current->num_recipes = 0;
        current->recipes = NULL;
        current->next = NULL;
        
        book->first = current;

        return;
    }

    while (current) {
        if (strcmp(current->category, category) == 0) {
            return;
        } else if (strcmp(current->category, category) < 0) {
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

void recipes_book_add_recipe(recipes_book *book, const char *category, const char *recipe) {
    struct category_node *current = book->first;

    while(strcmp(current->category, category) != 0) {
        current = current->next;
    }

    add_recipe(current, recipe);
}

void add_recipe(struct category_node *category, const char *recipe) {
    struct recipe_node *current = category->recipes;
    struct recipe_node *previous = NULL;

    if (current == NULL) {
        current = (struct recipe_node*)malloc(sizeof(struct recipe_node));
        
        strcpy(current->name, recipe);
        current->next = NULL;

        category->recipes = current;

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

void add_this_recipe(struct recipe_node *previous, const char *recipe) {
    struct recipe_node* new_node;
	new_node = (struct recipe_node*)malloc(sizeof(struct recipe_node));
    
    strcpy(new_node->name, recipe);
    new_node->next = previous->next;
    
    previous->next = new_node;
}


void add_category(struct category_node *previous, const char *category) {
    struct category_node* new_node;
	new_node = (struct category_node*) malloc(sizeof(struct category_node));

    strcpy(new_node->category, category);
    new_node->num_recipes = 0;
    new_node->recipes = NULL;
    new_node->next = previous->next;
    previous->next = new_node;
}

struct category_node* add_first_category(struct category_node *current, const char *category) {
    struct category_node* new_node;
	new_node = (struct category_node*)malloc(sizeof(struct category_node));

    strcpy(new_node->category, category);
    new_node->num_recipes = 0;
    new_node->recipes = NULL;
    new_node->next = current;
    return new_node;
}

struct recipe_node* add_first_recipe(struct recipe_node *current, const char *recipe) {
    struct recipe_node* new_node;
	new_node = (struct recipe_node*)malloc(sizeof(struct recipe_node));
    
    strcpy(new_node->name, recipe);
    new_node->next = current;

    return new_node;
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

// void print_book(recipes_book *book) {
//     if(book==NULL) {
// 		printf("Book is empty !\n");
// 		return;
// 	}

//     printf("\nPrinting book...\n=====================\n");
// 	struct category_node *current = book->first;
//     // printf("%s \n", current->category);

// 	while(current) {
// 		printf("Category : %s\n",current->category);
//         print_recipes(current->recipes);
//         printf("\n=====================\n");
// 		current = current->next;
// 	}
// }

// void print_recipes(struct recipe_node *recipe) {
//     if(!recipe) {
// 		printf("This category is Empty !\n");
// 		return;
// 	}

//     printf("The recipes are : \n");
// 	struct recipe_node *current = recipe;

// 	while(current) {
// 		printf("%s\n", current->name);
// 		current = current->next;
// 	}
// }
