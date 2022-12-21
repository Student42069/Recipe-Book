#include "central.h"
#include "main.h"

int main(int argc, char *argv[]) {
   check_args(argc, argv);
   
   recipes_book *book = recipes_book_initialize();
   
   load_recipes(argv[1], book);

   if (argc == 4)
      produce_stats(book, argv[3], argv[1]);
   
   run_prompt(book);

   free_recipe_book(book);

   return 0;
}