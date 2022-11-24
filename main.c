#include "main.h"
#include "linkedList.h"
#include "stats.h"

FILE* open_file(const char *file_name) {
   FILE *fptr = fopen(file_name, "r");
   
   if (fptr == NULL) {
      printf("Erreur dans l'ouverture du fichier.\n");
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

void checkargs(const int argc) {
   if (argc != 2) {
      printf("%s\n", "nombre arguments invalide");
    //   printf(USAGE, "./motcache");
      exit(ERREUR_NB_ARGS);
   }
}

void load_recipes(char *file_name) {
   FILE *fp = open_file(file_name);
   close_file(fp);
}

void produce_stats() {
   return;
}

void run_prompt() {
   puts("Okok !");
   return;
}

int main(int argc, char *argv[]) {
    checkargs(argc);
    load_recipes(argv[1]);
    produce_stats();
    run_prompt();
    test_module_inclusion();
}