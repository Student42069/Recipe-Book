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

void load_recipes(char *file_name) {
    FILE *fp = open_file(file_name, "r");
    close_file(fp);
}

void run_prompt() {
    puts("Okok !");
    return;
}

int main(int argc, char *argv[]) {
    check_args(argc, argv);
    load_recipes(argv[1]);
    produce_stats();
    run_prompt();
    // test_module_inclusion();
}