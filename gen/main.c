#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "strings.h"

#define MAX_PATHNAME_LENGTH 4096

char* getFilepath(char* filename, char* projectpath);

int main (int argc, char* argv[]) {

  if (argc != 2) {
    printf("Usage:\tgen [name]\n");
    return 1;
  }

  char* dir = calloc(MAX_PATHNAME_LENGTH, sizeof(char));
  getcwd(dir, sizeof(char) * MAX_PATHNAME_LENGTH);

  if (!dir) {
    printf("Error retrieving current directory. Aborting...\n");
    return 1;
  }

  strcat(dir, "/");

  char* projectName = argv[1];
  char* fullProjectPath = strcat(dir, projectName);

  if (mkdir(fullProjectPath, S_IRWXU | S_IRWXG) == -1) {
    printf("File or directory already exists\nPlease choose another name or run gen in a different directory\n"); 
    return 1;
  }

  FILE* mainc = fopen(getFilepath("main.c", fullProjectPath), "w");
  fprintf(mainc, MAINCSTR);
  fclose(mainc);
  
  FILE* makefile = fopen(getFilepath("Makefile", fullProjectPath), "w");
  fprintf(makefile, MAKESTR1);
  fprintf(makefile, projectName);
  fprintf(makefile, MAKESTR2);
  fclose(makefile);

  FILE* readme = fopen(getFilepath("README.md", fullProjectPath), "w");
  fprintf(readme, READMESTR);
  fclose(readme);

  return 0;  
}

char* getFilepath(char* filename, char* fullProjectPath) {
  char* filepath = malloc(sizeof(char) * MAX_PATHNAME_LENGTH);
  strcpy(filepath, fullProjectPath);
  strcat(filepath, "/");
  strcat(filepath, filename);
  return filepath;
}
