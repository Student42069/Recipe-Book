#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linkedList.h"
#include "stats.h"

#define USAGE "\
Usage: %s <FICHIER TEXTE CONTENANT LES RECETTES>\n\
\n\
Recherche dans un fiechier de recettes.\n\
\n\
Si aucun argument n'est fourni,\n\
le programme affiche ce message et se termine.\n\
"

#define USAGE_STATISTIQUE "\
Usage: %s <FICHIER TEXTE CONTENANT LES RECETTES> -S <FICHIER OÙ ENRIGISTRER LES STATISTIQUES>\n\
\n\
Recherche dans un fiechier de recettes\n\
et enrigistre des statistiques sur les données du\n\
fichier d'entrée et écrira ces statistiques dans le fichier de sortie spécifié.\n\
\n\
Si aucun argument n'est fourni,\n\
le programme affiche ce message et se termine.\n\
"

// #define MAX_LINE_LENGHT 120


enum error {
    OK                      = 0,
    ERREUR_NB_ARGS          = 1,
    ERREUR_FILE_FORMAT      = 3,
    ERREUR_OPEN_FILE        = 4,
    ERREUR_CLOSE_FILE       = 5,
    ERREUR_ARGS          = 6
};


/**
 * -----------------------
 * Function prototypes
 * -----------------------
 */

/**
 *  Opens a file and handles error cases
 * 
 *  @param file_name name of the file
 *  @param mode string containing a file access mode
 *
 *  @return pointer to the file
 */
FILE* open_file(const char *file_name, const char *mode);

/**
 *  Closes a file and handles error cases
 *
 *  @param file pointer to the file to close
 */
void close_file(FILE *file);

/**
 * Checks the command-line arguments and verifies that they 
 * are valid.
 *
 * @param argc the number of command-line arguments
 * @param argv an array containing the command-line arguments
 */
void check_args(const int argc, char *argv[]);

/**
 * Checks the command-line arguments for the '-S' flag and 
 * verifies that they are valid.
 *
 * @param argv an array containing the command-line arguments
 */
void check_stats_args(char *argv[]);

/**
 * Prints an error message for an invalid number of 
 * command-line arguments and exits the program.
 */
void throw_error_args_count();

/**
 * Loads the recipes from the given file into the given 
 * recipes book.
 *
 * @param file_name the name of the file containing the recipes
 * @param book a pointer to the recipes book to load the recipes into
 */
void load_recipes(char *file_name, recipes_book *book);

/**
 * Loads a single recipe from the given string and adds it 
 * to the given recipes book.
 *
 * @param buffer the string containing the recipe to load
 * @param book a pointer to the recipes book to add the recipe to
 */
void load_one_recipe(char *buffer, recipes_book *book);

/**
 * Loads a recipe into the categories specified in the given string.
 *
 * @param name the name of the recipe to load
 * @param buffer the string containing the categories for the recipe
 * @param book a pointer to the recipes book to add the recipe to
 */
void load_recipe_into_categories(char *name, char *buffer, recipes_book *book);

/**
 * Loads a recipe into a single category.
 *
 * @param buffer the string containing the recipe and category information
 * @param book a pointer to the recipes book to add the recipe to
 * @param name the name of the recipe to add
 * @param start the starting index of the category name in the input string
 * @param end the ending index of the category name in the input string
 */
void load_recipe_into_one_category(char *buffer, recipes_book *book, char *name, int start, int end);

/**
 * Extracts the recipe name from the given string.
 *
 * @param name the string to store the recipe name in
 * @param buffer the input string containing the recipe name
 */
void get_recipe_name(char *name, char *buffer);

void run_prompt(recipes_book *book);