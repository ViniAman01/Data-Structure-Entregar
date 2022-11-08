#include "dList.h"
#include <stdio.h>

int main(void)
{
	DList *list = List_create();
    DNode *node;

    List_add_first(list,0);
    List_add_last(list,1);
    List_add_last(list,2);

    List_print(list);

    List_remove(list,1);

    List_print(list);

    return 0;
}
