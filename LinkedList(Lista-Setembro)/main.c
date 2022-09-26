#include "linked_list.h"
#include <stdio.h>

int main(void)
{
	LinkedList *L;
	L = LinkedList_create();

	add_first(L,1);
	print_LL(L);
	printf("Posição do 6: %d\n",search_LL(L,6));

	add_last(L,4);
	print_LL(L);
	printf("Posição do 6: %d\n",search_LL(L,6));

	add_last(L,6);
	print_LL(L);
	printf("Posição do 6: %d\n",search_LL(L,6));

	add_last(L,8);
	print_LL(L);
	printf("Posição do 6: %d\n",search_LL(L,6));

	insert_sort(L,7);
	print_LL(L);
	printf("Posição do 6: %d\n",search_LL(L,6));

	insert_sort(L,3);
	print_LL(L);
	printf("Posição do 6: %d\n",search_LL(L,6));

	remove_LL(L,1);
	print_LL(L);

	remove_LL(L,6);
	print_LL(L);
	printf("Posição do 6: %d\n",search_LL(L,6));

	remove_LL(L,10);
	print_LL(L);

	return 0;
}
