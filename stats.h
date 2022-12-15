#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "linkedList.h"

#ifndef STATS_H_INCLUDED
#define STATS_H_INCLUDED
void produce_stats(recipes_book *book, char *file_name);
/**
 * Gets the number of lines in the input file
 *
 * @param book the recipes book
 *
 * @return the number of lines in the input file
 */
int num_lines(recipes_book *book);

/**
 * Gets the number of unique words in the input file
 *
 * @param book the recipes book
 *
 * @return the number of unique words in the input file
 */
int num_unique_words(recipes_book *book);

/**
 * Gets the number of words (including duplicates) in the input file
 *
 * @param book the recipes book
 *
 * @return the number of unique words in the input file
 */
int num_words(recipes_book *book);

/**
 * Gets the most frequent letter in the input file (ignoring duplicates)
 *
 * @param book the recipes book
 *
 * @return the most frequent letter in the input file (ignoring duplicates)
 */
char most_frequent_letter(recipes_book *book);

/**
 * Gets the number of categories in the input file
 *
 * @param book the recipes book
 *
 * @return the number of categories in the input file
 */
int num_categories(recipes_book *book);

/**
 * Gets the number of recipes in the input file
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