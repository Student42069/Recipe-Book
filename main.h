#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
 *  Verifies the number of parameters in argv.
 *  Exits the program if it there isn't 2 parameters.
 *
 *  @param argc  Parameter count
 */
void checkargs(int argc);

void check_stats_args(char *argv[]);

void throw_error_args_count();
