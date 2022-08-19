#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

struct float_vector
{
	int capacity;
	int size;
	float *data;
	
};

FloatVector *create(int tam)
{
	FloatVector *vet = (FloatVector*)calloc(1,sizeof(FloatVector));	
	vet->capacity = tam;
	vet->size = 0;
	vet->data = (float *)calloc(vet->capacity, sizeof(float));	

	return vet;	
}

void destroy(FloatVector *vet_ref)
{
	free(vet_ref->data);
	free(vet_ref);
}

int size(const FloatVector *vector)
{
	return vector->size;
}

int capacity(const FloatVector *vector)
{
	return vector->capacity;
}

float at(const FloatVector *vector, int pos)
{
	if(pos < 0 || pos >= vector->size)
	{
		fprintf(stderr, "Erro: Invalid position\n");
		exit(1);
	}

	return vector->data[pos];
}

void put(FloatVector *v, int pos, float value)
{
	v->data[pos] = value;
}

void append(FloatVector *vec, float value)
{
	vec->data[vec->size] = value;
	vec->size++;
}

void print(FloatVector *vec)
{
	for(int i = 0; i < vec->size; i++)
	{
		printf("%.2f ",vec->data[i]);
	}
	printf("\n");
}