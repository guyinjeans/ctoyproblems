#ifndef SORTLIST_H
#define SORTLIST_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "sortList.h"

node_t* createList(char* s_val) {

  node_t* tail = (node_t*) malloc(sizeof(node_t*));

  tail->s_val = (char*) malloc(sizeof(s_val));
  strcpy(tail->s_val, s_val);

  tail->next = NULL;

  return tail;
}

node_t* addToNewList(node_t* self, char* s_val) {

  node_t* node = (node_t*) malloc(sizeof(node_t*));
  
  node->s_val = (char*) malloc(sizeof(s_val));
  strcpy(node->s_val, s_val);

  node->next = self;
  // New value added is at head of newly created list, so long as it is greater than next node's value it will be pushed down 
  node_t* cursor = node;
  while(cursor) {
    if (cursor->next) {
      if (strcmp(cursor->s_val, cursor->next->s_val) > 0) {
        char* temp = (char*) malloc(sizeof(cursor->s_val));
        strcpy(temp, cursor->s_val);
        strcpy(cursor->s_val, cursor->next->s_val);
        strcpy(cursor->next->s_val, temp);
      } else {
        break;
      }
    }
    cursor = cursor->next;
  }
  // Returns new head, reference should be modified to point to new node
  return node;
}

void printList(node_t* self) {
  node_t* cursor = self;
  while(cursor != NULL) {
    printf("%s", cursor->s_val);
    cursor = cursor->next;
  }
}

#endif //SORTLIST_H
