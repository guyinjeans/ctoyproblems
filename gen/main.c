#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#include "strings.h"

#define MAX_PATHNAME_LENGTH 4096

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
  
  strcat(fullProjectPath, "/");

  char* mainName = malloc(sizeof(char) * MAX_PATHNAME_LENGTH);
  strcpy(mainName, fullProjectPath);
  strcat(mainName, "main.c");
  FILE* mainc = fopen(mainName, "w");
  fprintf(mainc, MAINCSTR);
  fclose(mainc);

  return 0;  
}
