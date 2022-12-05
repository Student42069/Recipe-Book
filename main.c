#include "main.h"
#include "linkedList.h"
#include "stats.h"

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
        // printf("%s\n", buffer);
    }
    close_file(fp);
}

void load_one_recipe(char *buffer, recipes_book *book) {
    char name[strlen(buffer) + 1];
    name[0] = '\0';
    get_recipe_name(name, buffer);
    load_recipe_into_categories(name, buffer, book);
    printf("%s\n", name);
}

void load_recipe_into_categories(char *name, char *buffer, recipes_book *book) {
    int start, end;
    char category_name[MAX_LINE_LENGHT];
    int counter = 0;

    for (int i = 0; i < (int) strlen(buffer); i++) {
        if (buffer[i] == '[')
            start = i;

        if (buffer[i] == ']') {
            end = i;
            for (int j = start + 1; j < end; j++)
                category_name[counter++] = buffer[j];
            category_name[counter] = '\0';
            counter = 0;
            printf("%s\n", category_name);
        }
  }
}

void get_recipe_name(char *name, char *buffer) {
    strncat(name, buffer, strlen(buffer) - strlen(strchr(buffer, '[')) - 1);
    name[strlen(buffer) - strlen(strchr(buffer, '['))] = '\0';
}

void run_prompt() {
    puts("Okok !");
    return;
}

int main(int argc, char *argv[]) {
    check_args(argc, argv);
    recipes_book *book = (recipes_book*) malloc(sizeof(recipes_book));
    recipes_book_initialize(book);
    load_recipes(argv[1], book);
    if (argc == 4)
        produce_stats();
    run_prompt();

    // recipes_book *book = (recipes_book*)malloc(sizeof(recipes_book));
    // recipes_book_initialize(book);

    // char cat1[] = "Poulet";
    // char cat2[] = "BBQ";
    // char cat3[] = "Asiatique";
    // char cat4[] = "Soupe";

    // char rec1[] = "Poulet au romarin";
    // char rec2[] = "Boeuf au satay";
    // char rec3[] = "Salade du jardin";
    // char rec4[] = "Poulet crapaudine";
    // char rec5[] = "Pho";
    // char rec6[] = "Authentique gibelotte des iles de Sorel";
    // char rec7[] = "Won-tong big shlong soup";
    // char rec8[] = "Epaves aux milles et 1 crabes";

    // recipes_book_add_category(book, cat1);
    // recipes_book_add_category(book, cat2);
    // recipes_book_add_category(book, cat3);
    // recipes_book_add_category(book, cat4);

    // recipes_book_add_recipe(book, cat1, rec1);
    // recipes_book_add_recipe(book, cat1, rec2);
    // recipes_book_add_recipe(book, cat1, rec3);
    // recipes_book_add_recipe(book, cat1, rec4);
    // recipes_book_add_recipe(book, cat3, rec5);
    // recipes_book_add_recipe(book, cat4, rec6);
    // recipes_book_add_recipe(book, cat3, rec7);
    // recipes_book_add_recipe(book, cat3, rec8);

    // print_book(book);
    // free_recipe_book(book);

    return 0;
}