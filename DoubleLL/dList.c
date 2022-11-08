#include "dList.h"

struct _dnode
{
    int val;
    DNode *next;
    DNode *prev;
};

struct _dlinkedlist
{
    DNode *begin;
    DNode *end;
    int size;
};

DNode *Node_create(int val)
{
    DNode *node = (DNode*)malloc(sizeof(struct _dnode));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    return node;
}

DList* List_create()
{
    DList *list = (DList*)malloc(sizeof(struct _dlinkedlist));
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

bool List_is_empty(const DList *list)
{
    if(list->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void List_size(DList *list)
{
    printf("size:%d\n",list->size);
}

void List_Destroy(DList **list)
{
    if(list != NULL)
    {
        DNode *node = (*list)->begin;
        while(node != NULL)
        {
            node = node->next;
            free(node->prev);
        }
        free(list);
    }
}

void List_add_last(DList *list, int val)
{
    DNode *node = Node_create(val);
    if(list->size == 0)
    {
        list->begin = node;
    }
    else
    {
        node->prev = list->end;
        list->end->next = node;
    }
    list->end = node;
    list->size++;
}

void List_add_first(DList *list, int val)
{
    DNode *node = Node_create(val);
    if(list->size == 0)
    {
        list->begin = list->end = node;
    }
    else
    {
        node->next = list->begin;
        list->begin->prev = node;
        list->begin = node;
    }
    list->size++;
}

void List_print(const DList *list)
{
    DNode *node = list->begin;
    while(node != NULL)
    {
        printf("%d ",node->val);
        node = node->next;
    }
    printf("\n");
}

void List_inverted_print(const DList *list)
{
    DNode *node = list->end;
    while(node != NULL)
    {
        printf("%d ",node->val);
        node = node->prev;
    }
    printf("\n");
}

DNode* List_search(DList *list, int val)
{
    DNode *node = list->begin;
    while(node->val != val && node != NULL)
    {
        node = node->next;
    }
    return node;
}

void List_remove(DList *list, int val)
{
    DNode *node = List_search(list,val);

    node->prev->next = node->next;
    node->next->prev = node->prev;
    
    free(node);
}