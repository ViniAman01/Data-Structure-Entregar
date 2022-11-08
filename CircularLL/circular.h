#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _cnode CNode;
typedef struct _clist CList;

CNode* Node_create(int val);
CList* List_create();

void List_Destroy(CList **list);
void List_size(CList *list);
bool List_is_empty(const CList *list);
void List_add_first(CList *list, int val);
void List_add_last(CList *list, int val);
void List_print(const CList *list);
void List_inverted_print(const CList *list);
void List_remove(CList *list, int val);
CNode* List_search(CList *list, int val);
void List_insert_sort(CList *list, int val);
CNode* List_binary_search(CList *list, int val);