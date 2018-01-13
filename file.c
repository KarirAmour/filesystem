#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
#include "file.h"
#include "directory.h"

void safePointer(void *p) {
  if (p != NULL) return;
  printf("ERROR: Null Pointer exception!\n");
  exit(1);
}

void validExtension(Extension ext) {
  if (ext == TXT || ext == BIN || ext == HID) return;
  printf("ERROR: Invalid Extension.\n");
  exit(1);
}

void validName(char *name) {
  safePointer(name);
  if (strlen(name) < NAME_SIZE) return;
  printf("ERROR: %s\n", name);
  printf("Name too long.\n");
  exit(1);
}




void NewFile(File *f, char *name, Extension ext, Directory *dir) {
  safePointer(f);
  safePointer(name);
  safePointer(dir);
  
  validExtension(ext);
  validName(name);
  
  f->fileExt = ext;
  f->fileSize = 0;
  f->fileCapacity = 0;
  f->fileName = calloc(NAME_SIZE, sizeof(char));
  strcpy(f->fileName, name);
  f->fileData = NULL;
  f->fileDirectory = dir;
  AddFile(f, dir);
  
}


void AddFile(File *f, Directory *dir) {
  safePointer(f);
  safePointer(dir);
  
  if (dir->numFiles >= dir->fileCapacity) {
    dir->fileCapacity *= 2;
    dir->dirFiles = realloc(dir->dirFiles, dir->fileCapacity * sizeof(f));
  }
  
  f->fileDirectory = dir;
  f->fileDirIndex = dir->numFiles;
  dir->dirFiles[dir->numFiles++];

}


void RemoveFile(File *f, Directory *dir) {
  safePointer(f);
  safePointer(dir);

  int location = f->fileDirIndex;
  // Ensure file is in dir and in correct location
  if (f != dir->dirFiles[location]) {
    printf("ERROR: File: %s is not in directory %s.\n", f->fileName, dir->dirName);
    exit(1);
  }
  
  f->fileDirectory = NULL; // Delete location/directory
  const int length = dir->numFiles--; // Decrease number of files by 1
  // Shift all files down (defragging? ish); 
  for (int fileShift = location; fileShift < length; ++fileShift) {
    dir->dirFiles[fileShift - 1] = dir->dirFiles[fileShift++];
  }
  // possibly change dirSize?
}

void DeleteFile(File *f) {
  safePointer(f);

  free(f->fileName);
  free(f->fileData);
  RemoveFile(f, f->fileDirectory);
  free(f);

}

void RenameFile(File *f, char *newname) {
  safePointer(f);
  safePointer(newname);

  validName(newname);
  strcpy(f->fileName, newname);

}

void MoveFile(File *f, Directory *dir) {
  safePointer(f);
  safePointer(dir);

  RemoveFile(f, dir);
  AddFile(f, dir);
}

void CopyFile(File *fdest, File *fsource, Directory *dir) {
  safePointer(fsource);
  // No need for safePointer fdest?

  fdest->fileExt = fsource->fileExt;
  fdest->fileSize = fsource->fileSize;
  fdest->fileCapacity = fsource->fileCapacity;

  validName(fsource->fileName);
  fdest->fileName = malloc(NAME_SIZE * sizeof(char));
  fdest->fileName = strncpy(fdest->fileName, fsource->fileName, NAME_SIZE);
  
  fdest->fileData = malloc(fsource->fileSize * sizeof(*(fsource->fileData)));

  AddFile(fdest, dir);
}
				       






static void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}




static void getTime(char string[]) {
  //assert(strlen(string) > 17);

  time_t t;
  struct tm *timeinfo;
  time(&t);
  timeinfo = localtime(&t);
  strftime(string, 18, "%m/%d/%y %H:%M:%S", timeinfo);

}
