#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "directory.h"
#include "file.h"


void print_commands() {
  printf("Commands:\n");
  printf("  h -- help\n");
  printf("  ls -- list files\n");
  printf("  mkdir [name] -- make directory\n");
  printf("  rmdir [name] -- remove directory\n");
  printf("  cd [dir] -- enter directory\n");
  printf("  cd . -- -- go to parent directory \n");
  printf("  print [file] print contents of file -- help\n");
  printf("  clear -- clear screen\n");
  

}

int main(int argc, char *argv[]) {

  if (argc > 1) {
    int i = atoi(argv[1]);
    printf("i = %d\n", i);
  }

  Directory root, d1, d2, d3;
  NewRootDirectory(&root, "~");
  // NewDirectory(&d1, "Child1", &root); / Old format
  // NewDirectory(&d2, "Child2", &d1);
  // NewDirectory(&d3, "NormalName", &d2);

  // DirectoryLocation(&root);
  // DirectoryLocation(&d1);
  // DirectoryLocation(&d2);
  // DirectoryLocation(&d3);
  File f1, f2;

  print_commands();
  char *input = calloc(64, sizeof(*input));
  printf("Enter \'help\' for help and \'quit\' to quit.\n");
  Directory *current = &root;
  while (1) {
    if (scanf("%s", input) != 1) {
      printf("Invalid input.\n Exiting...\n");
    }
    if (strcmp(input, "help") == 0) {
      print_commands();
      continue;
    } else if (strcmp(input, "quit") == 0) {
      printf("Quitting...\n");
      return 0;
    } else if (strcmp(input, "mkdir") == 0) {
      char dirname[20];
      if (scanf("%s", &dirname) == 1) {
        Directory NewDirectory(current, )
      }
    }

  }

  free(input);
  
  return 0;
}
