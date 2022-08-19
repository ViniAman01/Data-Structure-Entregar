#include "float_vector.h"
#include "sort.h"
#include <stdlib.h>

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

void merge(FloatVector *v, int inicio, int meio, int fim)
{
    float *temp;
    int tamanho,i,j,k,p1,p2;
    int fim1 = 0, fim2 = 0;

    p1 = inicio;
    p2 = meio+1;

    tamanho = fim-inicio+1;

    temp = (float*)malloc(tamanho*sizeof(float));

    if(temp != NULL)
    {
        for(i = 0; i < tamanho; i++)
        {
            if(!fim1 && !fim2)
            {
                if(at(v,p1) < at(v,p2))
                    temp[i] = at(v,p1++);
                else
                    temp[i] = at(v,p2++);
                if(p1 > meio) fim1 = 1;
                if(p2 > fim) fim2 = 1;
            }
            else
            {
                if(!fim1)
                    temp[i] = at(v,p1++);
                if(!fim2)
                    temp[i] = at(v,p2++);
            }
        }
        for(j = 0, k = inicio; j < tamanho; j++,k++)
        {
            put(v,k,temp[j]);
        }
    }
}

void mergeSort(FloatVector *v,int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = inicio + (fim - inicio)/2;
        mergeSort(v,inicio,meio);
        mergeSort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
}