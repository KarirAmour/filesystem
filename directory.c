#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "directory.h"
#include "file.h"

void safePointer(void *p);
void validName(char *name);


void NewDirectory(char *name, Directory *parent) {
  safePointer(parent);
  safePointer(name);

  validName(name);
  Directory *dir = calloc(1, sizeof(Directory));
  dir->dirName = calloc(NAME_SIZE, sizeof(char));
  strcpy(dir->dirName, name);
  dir->dirSize = 0;

  dir->fileCapacity = 0;
  dir->numFiles = 0;
  dir->dirFiles = NULL;

  dir->dirParent = parent;
  dir->numChildren = 0;
  dir->dirChildren = NULL;

}

void NewRootDirectory(Directory *dir, char *name) {
  NewDirectory(name, NULL);
}



void DirectoryLocation(Directory *dir) {


  Directory *dirloop = dir;
  while (dirloop != NULL) {
    printf("%s/", dirloop->dirName);
    dirloop = dirloop->dirParent;
  }
  printf("~\n");

}

void RemoveDirectory(Directory *dir) {
  free(dirName);
  for (file = dirFiles; *file; ++file) {
    RemoveFile
  }
  dir = NULL;

}



