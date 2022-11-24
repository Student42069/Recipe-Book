#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum error {
    OK                      = 0,
    ERREUR_NB_ARGS          = 1,
    ERREUR_FILE_FORMAT      = 3,
    ERREUR_OPEN_FILE        = 4,
    ERREUR_CLOSE_FILE       = 5
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
 *
 *  @return pointer to the file
 */
FILE* open_file(const char *file_name);

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

