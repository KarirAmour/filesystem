// Directory


#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "file.h"

typedef struct File File;
typedef struct Directory Directory;

struct Directory {

  char *dirName; // name of dir for user
  int dirSize; // in bytes

  int fileCapacity; // allocated memory in dirFiles
  int numFiles; // number of elements in *dirFiles
  File **dirFiles; // pointer to each File within self
  
  Directory *dirParent; // parent directory
  int numChildren; // number of directories within self
  Directory **dirChildren; // pointer to each directory in self
  
};


// Directory
void AddDirectory(Directory *to, Directory *from);

void NewDirectory(Directory *dir, char *name, Directory *parent);

void NewRootDirectory(Directory *dir, char *name);

void RemoveDirectory(Directory *dir);

void RenameDirectory(Directory *dir);

void ListDirectory(Directory *dir);

int DirectorySize(Directory *dir);

void DirectoryLocation(Directory *dir);

#endif
  
