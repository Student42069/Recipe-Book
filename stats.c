#include "stats.h"
#include "main.h"

void produce_stats(recipes_book *book, char *file_name, char *recipes_file_name) {
    FILE *file = open_file(file_name, "w");

    fprintf(file, "Le nombre de lignes dans le fichier d'entrée: %d\n", num_lines(recipes_file_name));
    fprintf(file, "Le nombre de mots sans doublons: %d\n", num_unique_words(recipes_file_name));
    fprintf(file, "Le nombre de mots avec doublons: %d\n", num_words(recipes_file_name));
    // fprintf(file, "La lettre la plus fréquente (sans considérer les doublons): %c\n", most_frequent_letter(recipes_file_name));
    fprintf(file, "Le nombre de catégories: %d\n", num_categories(book));
    fprintf(file, "Le nombre de recettes: %d\n", num_recipes(book));
    fprintf(file, "La catégorie qui a le plus grand nombre de recettes: %s\n", category_with_most_recipes(book));
    fprintf(file, "La recette la plus longue (en termes de nombre de caractères): %s\n", longest_recipe(book));

    close_file(file);
}

int num_lines(char *file_name) {
    FILE *file = open_file(file_name, "r");
    int count = 0;

    char buffer[MAX_LINE_LENGHT];
    while (fgets(buffer, MAX_LINE_LENGHT, file) != NULL)
    count++;

    close_file(file);
    return count;
}

int num_unique_words(char *file_name) {
    FILE *file = open_file(file_name, "r");
    char *words[MAX_LINE_LENGHT];
    int count = 0;
    char buffer[MAX_LINE_LENGHT];

    while (fgets(buffer, MAX_LINE_LENGHT, file) != NULL) {
        char *word = strtok(buffer, " ");

        while (word != NULL) {
            int found = 0;
            for (int i = 0; i < count; i++)
                if (strcmp(word, words[i]) == 0) {
                    found = 1;
                    break;
                }

            if (!found) 
                words[count++] = word;

            word = strtok(NULL, " ");
        }
    }

    close_file(file);

    return count;
}

int num_words(char *recipes_file_name) {
    FILE *file = open_file(recipes_file_name, "r");
    int count = 0;
    char buffer[MAX_LINE_LENGHT];

    while (fgets(buffer, MAX_LINE_LENGHT, file) != NULL) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
        count++;
        word = strtok(NULL, " ");
        }
    }
    close_file(file);
    return count;
}

int num_categories(recipes_book *book) {
    return book->num_categories;
}

int num_recipes(recipes_book *book) {
    int num_recipes = 0;

    struct category_node *current_category = book->first;
    while (current_category != NULL) {
    num_recipes += current_category->num_recipes;
    current_category = current_category->next;
    }

    return num_recipes;
}

char *category_with_most_recipes(recipes_book *book) {
    char *category_with_most_recipes = NULL;
    unsigned int max_num_recipes = 0;
    struct category_node *current_category = book->first;

    while (current_category != NULL) {
        if (current_category->num_recipes > (unsigned int) max_num_recipes) {
        category_with_most_recipes = current_category->category;
        max_num_recipes = current_category->num_recipes;
        }
        current_category = current_category->next;
    }

    return category_with_most_recipes;
}

char *longest_recipe(recipes_book *book) {
    char *longest_recipe = NULL;
    unsigned int max_recipe_length = 0;
    struct category_node *current_category = book->first;
    
    while (current_category != NULL) {
        struct recipe_node *current_recipe = current_category->recipes;
        while (current_recipe != NULL) {
            if ((unsigned int) strlen(current_recipe->name) > max_recipe_length) {
                longest_recipe = current_recipe->name;
                max_recipe_length = strlen(current_recipe->name);
            }
            current_recipe = current_recipe->next;
        }
        current_category = current_category->next;
    }
    return longest_recipe;
}
