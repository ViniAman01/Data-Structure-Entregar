#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

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

SNode* SNode_create(int val)
{
    SNode *snode = (SNode*)malloc(sizeof(SNode));
    snode->val = val;
    snode->next = NULL;
    return snode;
}

LinkedList* LinkedList_create()
{
    LinkedList *linked_list = (LinkedList*)malloc(sizeof(LinkedList));
    linked_list->begin = NULL;
    linked_list->size = 0;
    return linked_list;
}

void add_first(LinkedList *L, int val)
{
    SNode *p = SNode_create(val);
	L->begin = p;
	L->size++;
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
		if(p->next != NULL)
			printf("%d - ",p->val);
		else
			printf("%d\n",p->val);
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
		while(aux->next != NULL && aux->next->val < val)
		{
			aux = aux->next;
		}
		p->next = aux->next;
		aux->next = p;
	}
	L->size++;
}

int search_LL(LinkedList *L, int val)
{
	if(L->begin == NULL)
	{
		printf("Não há elementos para acessar!\n");
	}
	else
	{
		SNode *aux = L->begin;
		int cont = 0;
		while(aux != NULL && aux->val != val)
		{
			cont++;
			aux = aux->next;
		}
		if(aux == NULL)
		{
			printf("Valor não foi encontrado!\n");
			return -1;
		}
		else
		{
			return cont;
		}
	}
}

void remove_LL(LinkedList *L, int val)
{
	if(L->begin == NULL)
	{
		printf("Não há elementos para remover!\n");
	}
	else
	{
		int pos = search_LL(L,val);
		SNode *aux = L->begin;

		if(pos != -1)
		{
			if(pos == 0)
			{
				if(L->begin->next != NULL)
				{
					L->begin = L->begin->next;
				}
				else
				{
					L->begin = NULL;
				}
			}
			else
			{
				SNode *aux_2;
				for(int i = 0; i < pos-1; i++)
				{
					aux = aux->next;
				}
				aux_2 = aux->next;
				aux->next = aux->next->next;
				free(aux_2);
			}
		}
	}
}
