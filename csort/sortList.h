typedef struct node_t {
  char* s_val;
  struct node_t* next;
} node_t;

node_t* createList(char* s_val);
node_t* addToNewList(node_t* self, char* s_val);
void printList(node_t* self);
