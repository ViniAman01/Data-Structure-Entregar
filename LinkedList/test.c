#include <stdio.h>
#include <stdlib.h>

typedef struct _nsei
{
	int *a;

}Nsei;

int main(void)
{
	Nsei *ns;
	int *b = (int*)malloc(sizeof(int));
	ns = (Nsei*)malloc(sizeof(Nsei));
	*b = 3;
	printf("%x\n",b);
	ns->a = b;
	printf("%x\n",ns->a);
	printf("%d\n",*ns->a);
	
	return 0;
}
	
