#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype
char** get_words_in_brackets(const char* str);

int main(void) {
  // Sample string with words in square brackets
  const char* str = "[hello][world][how][are][you]";

  // Get the words in square brackets
  char** words = get_words_in_brackets(str);

  // Print the words
  for (int i = 0; words[i] != NULL; i++) {
    printf("%s\n", words[i]);
  }

  // Free the memory allocated for the words
  for (int i = 0; words[i] != NULL; i++) {
    free(words[i]);
  }
  free(words);

  return 0;
}

// Function to get the words in square brackets from a string
char** get_words_in_brackets(const char* str) {
  // Allocate memory for the array of words
  char** words = malloc(strlen(str));

  // Initialize variables
  int word_count = 0;
  int word_start = 0;
  int word_len = 0;
  int in_brackets = 0;

  // Loop through the string
  for (int i = 0; str[i] != '\0'; i++) {
    // Check if the current character is a square bracket
    if (str[i] == '[') {
      // Start of a new word in brackets
      in_brackets = 1;
      word_start = i + 1;
      word_len = 0;
    } else if (str[i] == ']') {
      // End of a word in brackets
      in_brackets = 0;
      words[word_count] = malloc(word_len + 1);
      strncpy(words[word_count], str + word_start, word_len);
      words[word_count][word_len] = '\0';
      word_count++;
    } else if (in_brackets) {
      // Inside a word in brackets
      word_len++;
    }
  }

  // Add a NULL element to the end of the array
  words[word_count] = NULL;

  // Return the array of words
  return words;
}