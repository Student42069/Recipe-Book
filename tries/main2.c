#include <stdio.h>
#include <string.h>

int main() {
  // Define a string with words in square brackets
  char str[] = "This [is] a [string] with [words] in [square] brackets.";

  // Define an array to store the words between square brackets
  char words[100][100];

  // Define variables to store the start and end indices of the word
  int start, end;

  // Define a counter for the index of the words array
  int counter = 0;

  // Loop through the string
  for (int i = 0; i < strlen(str); i++) {
    // Check if the current character is an opening square bracket
    if (str[i] == '[') {
      // Store the start index of the word
      start = i;
    }

    // Check if the current character is a closing square bracket
    if (str[i] == ']') {
      // Store the end index of the word
      end = i;

      // Store the word between the square brackets in the words array
      for (int j = start + 1; j < end; j++) {
        words[counter][j - start - 1] = str[j];
      }

      // Increment the counter
      counter++;
    }
  }

  // Print the words in the words array
  for (int i = 0; i < counter; i++) {
    printf("%s\n", words[i]);
  }

  return 0;
}