#include "circular.h"

struct _cnode
{
    CNode *next;
    CNode *prev;
    int val;
};

struct _clist
{
    CNode *begin;
    CNode *end;
    size_t size;    
};

CList* List_create()
{
    CList *list = (CList*)malloc(sizeof(CList));
    if(list != NULL)
    {
        list->begin = list->end = NULL;
        list->size = 0;
        return list;
    }
}

CNode* Node_create(int val)
{
    CNode *node = (CNode*)malloc(sizeof(CNode));
    if(node != NULL)
    {
        node->next = NULL;
        node->prev = NULL;
        node->val = val;
    }
}

bool List_is_empty(const CList *list)
{
    return (list->size == 0);
}

void List_size(CList *list)
{
    printf("size: %d\n",list->size);
}

void List_destroy(CList **list)
{
    if(list != NULL)
    {
        CNode *node = (*list)->begin;
        for(int i = 0; i < (*list)->size; i++)
        {
            node = node->next;
            free(node->prev);
        }
        free(list);
    }
}

void List_add_first(CList *list,int val)
{
    CNode *node = Node_create(val);
    if(List_is_empty(list))
    {
        list->begin = node;
        node->prev = node->next = node;
    }
    else
    {
        list->begin->prev = node;
        node->next = list->begin;
        node->prev = list->end;
        list->begin = node;        
    }
}
