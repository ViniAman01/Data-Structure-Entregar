#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

    typedef struct _dnode DNode;
typedef struct _dlinkedlist DList;

DNode* Node_create(int val);
DList* List_create();

void List_Destroy(DList **list);
void List_size(DList *list);
bool List_is_empty(const DList *list);
void List_add_first(DList *list, int val);
void List_add_last(DList *list, int val);
void List_print(const DList *list);
void List_inverted_print(const DList *list);
void List_remove(DList *list, int val);
DNode* List_search(DList *list, int val);
void List_insert_sort(DList *list, int val);
DNode* List_binary_search(DList *list, int val);