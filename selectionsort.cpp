#include <iostream>
#define TAM 10

void swap(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(void)
{
	int menor_i;
	int v[TAM] = {1,2,3,4,5,6,7,8,9,10};
	for(int i = 0; i < TAM-1; i++)
	{
		menor_i = i;
		for(int j = i+1; j < TAM; j++)
		{
			if(v[j] < v[menor_i])
				menor_i = j;
		}
		if(menor_i != i)
			swap(v+i,v+menor_i);
		
	}
	for(int i = 0; i < TAM; i++)
	{
		std::cout << v[i] << " ";
	}
}