#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _slinked_list LinkedList;
typedef struct _snode SNode;
SNode *SNode_create(int val);
SNode *LinkedList_create(void);
void add_first(LinkedList *L, int val);
void add_last(LinkedList *L, int val);
void print_LL(LinkedList *L);
void insert_sort(LinkedList *L, int val);
SNode* search_LL(LinkedList *L, int val);
void remove_N(LinkedList *L, int val);

#endif