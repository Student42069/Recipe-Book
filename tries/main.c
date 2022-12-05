#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "This [is] a [string] with [words] in [square] brackets.";
  int start, end;

  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == '[') {
      start = i;
    }

    if (str[i] == ']') {
      end = i;
      for (int j = start + 1; j < end; j++) {
        printf("%c", str[j]);
      }
      printf("\n");
    }
  }
  return 0;
}