#include "main.h"

FILE* open_file(const char *file_name, const char *mode) {
    FILE *fptr = fopen(file_name, mode);
    
    if (fptr == NULL) {
      printf("Erreur dans l'ouverture du fichier: %s\n", file_name);
      exit(ERREUR_OPEN_FILE);
    }
    return fptr;
}

void close_file(FILE *fptr) {
    if (fclose(fptr) == EOF) {
      printf("Erreur dans la fermeture du fichier.\n");
      exit(ERREUR_CLOSE_FILE);
    }
}

void check_args(const int argc, char *argv[]) {
    if (argc == 2) {
        FILE *fp = open_file(argv[1], "r");
        close_file(fp);
        return;
    } else if (argc == 4) {
        check_stats_args(argv);
        return;
    }
    throw_error_args_count();
}

void check_stats_args(char *argv[]) {
    if (strcmp(argv[2], "-S") == 0) {
        FILE *fp = open_file(argv[3], "w");
        close_file(fp);
    } else {
        printf("%s\n", "Deuxieme argument invalide");
        printf(USAGE_STATISTIQUE, "./recherche");
        exit(ERREUR_ARGS);
    }
}

void throw_error_args_count() {
    printf("%s\n", "nombre arguments invalide");
    printf(USAGE, "./recherche");
    exit(ERREUR_NB_ARGS);
}

void load_recipes(char *file_name, recipes_book *book) {
    FILE *fp = open_file(file_name, "r");
    char buffer[MAX_LINE_LENGHT + 1];
    while(fgets(buffer, MAX_LINE_LENGHT, fp)) {
        if (buffer[strlen(buffer) - 1] == '\n')
            buffer[strlen(buffer)- 1] = '\0';
        load_one_recipe(buffer, book);
    }
    close_file(fp);
}

void load_one_recipe(char *buffer, recipes_book *book) {
    char name[strlen(buffer) + 1];
    name[0] = '\0';
    get_recipe_name(name, buffer);
    load_recipe_into_categories(name, buffer, book);
}

void load_recipe_into_categories(char *name, char *buffer, recipes_book *book) {
    int start;
    for (int i = 0; i < (int) strlen(buffer); i++) {
        if (buffer[i] == '[') start = i;
        if (buffer[i] == ']')
            load_recipe_into_one_category(buffer, book, name, start, i);
    }
}

void load_recipe_into_one_category(char *buffer, recipes_book *book, char *name, int start, int end) {
    char category_name[MAX_LINE_LENGHT];
    int counter = 0;
    for (int j = start + 1; j < end; j++)
        category_name[counter++] = buffer[j];
    category_name[counter] = '\0';
    recipes_book_add_recipe(book, category_name, name);
}

void get_recipe_name(char *name, char *buffer) {
    strncat(name, buffer, strlen(buffer) - strlen(strchr(buffer, '[')) - 1);
    name[strlen(buffer) - strlen(strchr(buffer, '['))] = '\0';
}

// void run_prompt(recipes_book *book) {
//     char query[MAX_LINE_LENGHT];
//     while (1) {
//         printf("Entrez votre critère de recherche : ");
//         scanf("%s", query);
//         struct category_node *current = book->first;
//         while (current && strcmp(current->category, query) != 0) {
//             current = current->next;
//         }

//         if (!current)
//             printf("Catégorie inexistante.\n");

//         // printf("Recipes in the %s category:\n", current->category);
//         struct recipe_node *recipe = current->recipes;
//         while (recipe) {
//             printf("- %s\n", recipe->name);
//             recipe = recipe->next;
//         }
//     }
// }
void search_by_category(recipes_book *book, char *category) {
    struct category_node *current = book->first;
    while (current) {
        if (strcmp(current->category, category) == 0) {
            struct recipe_node *recipe = current->recipes;
            while (recipe) {
                printf("%s\n", recipe->name);
                recipe = recipe->next;
            }
            return;
        }
        current = current->next;
    }
    printf("La catégorie '%s' n'existe pas.\n", category);
}

void search_by_category_and_keyword(recipes_book *book, char *category, char *keyword) {
    struct category_node *current = book->first;
    while (current) {
        if (strcmp(current->category, category) == 0) {
            struct recipe_node *recipe = current->recipes;
            int found = 0;
            while (recipe) {
                if (strstr(recipe->name, keyword) != NULL) {
                    printf("%s\n", recipe->name);
                    found = 1;
                }
                recipe = recipe->next;
            }
            if (found == 0) {
                printf("Aucune recette trouvée pour la catégorie '%s' et le mot-clé '%s'.\n", category, keyword);
            }
            return;
        }
        current = current->next;
    }
    printf("La catégorie '%s' n'existe pas.\n", category);
}

void run_prompt(recipes_book *book) {
    char query[MAX_LINE_LENGHT];
    while (1) {
        printf("Entrez votre critère de recherche : ");
        scanf("%s", query);

        if (strcmp(query, "exit") == 0) {
            break;
        } else if (strchr(query, ' ') == NULL) {
            search_by_category(book, query);
        } else {
            char *keyword = strchr(query, ' ') + 1;
            *strchr(query, ' ') = '\0';
            search_by_category_and_keyword(book, query, keyword);
        }
    }
}


int main(int argc, char *argv[]) {
    check_args(argc, argv);
    
    recipes_book *book = recipes_book_initialize();
    
    load_recipes(argv[1], book);
    // print_book(book);

    // if (argc == 4)
    //     produce_stats();
    
    run_prompt(book);

    free_recipe_book(book);

    return 0;
}