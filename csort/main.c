#include <stdio.h>
#include <stdlib.h>
#include "sortList.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char* argv[]) {

  if (argc != 2) {
    printf("use as '%s filename'\n", argv[0]);
    return -1;
  }

  FILE* fstream = fopen(argv[1], "r");

  if (!fstream) {
    printf("Error opening file '%s'\n", argv[1]);
    return -1;
  }

  node_t* list = NULL;
  char* line = (char*) malloc(MAX_LINE_LENGTH);

  while(fgets(line, MAX_LINE_LENGTH, fstream)) {
    if (!list) {
      list = createList(line);
    } else {
      list = addToNewList(list, line);
    }
  }

  fclose(fstream);

  printList(list);

  return 0;
}
