#include "float_vector.h"
#include "sort.h"
#include <stdio.h>

void swap(FloatVector *v, int pos, int pos2)
{
    float aux1,aux2;
    aux1 = at(v,pos);
    aux2 = at(v,pos2);
    put(v,pos,aux2);
    put(v,pos2,aux1);
}

void selecsort(FloatVector *v)
{
    int menor_i;
    for(int i = 0; i < size(v)-1; i++)
    {
        menor_i = i;
        for(int j = i+1; j < size(v); j++)
        {
            if(at(v,j) < at(v,menor_i))
                menor_i = j;
        }
        if(menor_i != i)
            swap(v,i,menor_i);
    }
}

void bubsort(FloatVector *v)
{
    int k,cont;
    do
	{
		k = 0;
		for(int i = 0; i < size(v)-1; i++)
		{
			cont++;
			if(at(v,i) > at(v,i+1))
			{
				swap(v,i,i+1);
				k = 1;
			}
		}
	}while(k);
}