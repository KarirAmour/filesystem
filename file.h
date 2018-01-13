// File



#ifndef FILE_H
#define FILE_H
#include "directory.h"

#define BUFF_SIZE 1023
#define NAME_SIZE 32

typedef enum Extension {
  TXT = 0,
  BIN = 1,
  HID = 2
} Extension;


typedef struct File File;
typedef struct Directory Directory;

struct File {

  Extension fileExt; // either TeXT or BINary
  int fileSize; // Size in byes
  int fileCapacity; // total allocated memory
  
  char *fileName;
  char **fileData;
  int fileDirIndex;
  Directory *fileDirectory;
  
};

// Files

// Initializes a file in a directory
void NewFile(File *f, char *name, Extension ext, Directory *dir);

// Adds a file to a directory; updates dir
void AddFile(File *f, Directory *dir);

// Removes f from dir; updating dirFiles || can this be static?
void RemoveFile(File *f, Directory *dir);

// Frees f and its parent directory
void DeleteFile(File *f);

// Renames file with newname
void RenameFile(File *f, char *newname);

// Moves a f to dir
void MoveFile(File *f, Directory *dir);

// Creates a shallow copy of fsource and moves it to dir, copies contents only
void CopyFile(File *fdest, File *fsource, Directory *dir);

// Creates a link to dir
void LinkFile(File *f, Directory *dir);

int FileSize(File *f);

#endif
