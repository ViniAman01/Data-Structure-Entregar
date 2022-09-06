#include <stdlib.h>
#include <stdio.h>

typedef struct _snode
{
    int val;
    struct _snode *next;
}SNode;

typedef struct _slinked_list
{
    SNode *begin;
    int size;
}LinkedList;

SNode *SNode_create(int val)
{
    SNode *snode = (SNode*)calloc(1,sizeof(SNode));
    snode->val = val;
    snode->next = NULL;
    return snode;
}

LinkedList *LinkedList_create()
{
    LinkedList *linked_list = (LinkedList*)calloc(1,sizeof(LinkedList));
    linked_list->begin = NULL;
    linked_list->size = 0;
    return linked_list;
}

void add_first(LinkedList *L, int val)
{
    SNode *p = SNode_create(val);
    p->next = L->begin;
}

void add_last(LinkedList *L, int val)
{
    SNode *p = SNode_create(val);
    if(L->begin == NULL)
    {
        L->begin = p;
    }
    else
    {
       SNode *aux =L->begin;
       while(aux->next != NULL)
       {
          aux = aux->next; 
       } 
       aux->next = p;
       L->size++;
    }
}

void print_LL(LinkedList *L)
{
    SNode *p = L->begin;
    printf("L -> ");

    while(p != NULL)
    {
        printf("%d - ", p->val);
        p = p->next;
    }
}

void insert_sort(LinkedList *L, int val)
{
    SNode *p = SNode_create(val);
    if(L->begin == NULL)
    {
        L->begin = p;
    }
    else
    {
       SNode *aux = L->begin;
       while(val > aux->val && aux->next != NULL)
       {
          aux = aux->next; 
       } 
       aux->next = p;
       aux->val = val;
       L->size++;
    }
}

SNode* search_LL(LinkedList *L, int val)
{
    SNode *auxN = L->begin;
    if(L->begin != NULL)
    {
        printf("Lista vazia!");
    }
    else
    {
        while(auxN->val != val)
        {
            auxN = auxN->next;
        }
        return auxN;
    }
}

void remove_N(LinkedList *L, int val)
{
    SNode *auxN = L->begin;
    if(L->begin != NULL)
    {
        printf("Lista vazia! Não há oque remover.");
    }
    else
    {
        while(auxN->val != val)
        {
            auxN = auxN->next;
        }
        free(auxN);
        while(L->begin != NULL)
        {
            L->begin = auxN;        
        }
    }
}