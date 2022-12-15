#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linkedList.h"

#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED

/**
 * Saves the statistics for a recipes book to a text file.
 *
 * @param book a pointer to the recipes book to save the statistics for
 * @param file_name the name of the file to save the statistics to
 * @param recipes_file_name the name of the file the recipes were loaded from
 */
void produce_stats(recipes_book *book, char *file_name, char *recipes_file_name);

/**
 * Gets the number of lines in the input file
 *
 * @param file_name the file name of the recipes file
 *
 * @return the number of lines in the input file
 */
int num_lines(char *file_name);

/**
 * Gets the number of unique words in the input file
 *
 * @param recipes_file_name the name of the file the recipes were loaded from
 *
 * @return the number of unique words in the input file
 */
int num_unique_words(char *recipes_file_name);

/**
 * Gets the number of words (including duplicates) in the input file
 *
 * @param recipes_file_name the name of the file the recipes were loaded from
 *
 * @return the number of unique words in the input file
 */
int num_words(char *recipes_file_name);

/**
 * Gets the most frequent letter in the input file (ignoring duplicates)
 *
 * @param recipes_file_name the name of the file the recipes were loaded from
 *
 * @return the most frequent letter in the input file (ignoring duplicates)
 */
char most_frequent_letter(char *recipes_file_name);

/**
 * Gets the number of categories in the recipe book
 *
 * @param book the recipe book
 *
 * @return the number of categories in the input file
 */
int num_categories(recipes_book *book);

/**
 * Gets the number of recipes in the recipe book
 *
 * Isn't used or implemented because it is the same 
 * as the number of lines in the file
 *
 * @param book the recipes book
 *
 * @return the number of recipes in the input file
 */
int num_recipes(recipes_book *book);

/**
 * Gets the category with the most recipes
 *
 * @param book the recipes book
 *
 * @return the category with the most recipes
 */
char *category_with_most_recipes(recipes_book *book);

/**
 * Gets the longest recipe (in terms of number of characters)
 *
 * @param book the recipes book
 *
 * @return the longest recipe (in terms of number of characters)
 */
char *longest_recipe(recipes_book *book);

#endif