#include <iostream>
#include <stdio.h>
#include "Leitura.h"

int main(void)
{
	bool k;
	int cont = 0;
	int *v;
	int tam;

	v = (int*)malloc(sizeof(int));
	tam = Leitura(v);

	for(int i = 0; i < tam; i++)
	{
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;

	do
	{
		k = 0;
		for(int i = 0; i < tam-1; i++)
		{
			cont++;
			std::cout << cont << std::endl;
			if(v[i] > v[i+1])
			{
				int aux;
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				k = 1;
			}
		}
	}while(k);

	std::cout << "Fim cont" << std::endl;
	
	for(int i = 0; i < tam; i++)
	{
		std::cout << v[i] << " ";
	}
	
	free(v);

	std::cout << std::endl;
	return 0;
}
