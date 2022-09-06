#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct float_vector
{
	int capacity;
	int size;
	float *data;
	
};

FloatVector *create(int tam)
{
	FloatVector *v = (FloatVector*)calloc(1,sizeof(FloatVector));	
	v->capacity = tam;
	v->size = 0;
	v->data = (float *)calloc(v->capacity, sizeof(float));	

	return v;	
}

void destroy(FloatVector *v)
{
	free(v->data);
	free(v);
}

int size(const FloatVector *v)
{
	return v->size;
}

int capacity(const FloatVector *v)
{
	return v->capacity;
}

float at(const FloatVector *v, int pos)
{
	if(pos < 0 || pos >= v->size)
	{
		fprintf(stderr, "Erro: Invalid position\n");
		exit(1);
	}

	return v->data[pos];
}

void put(FloatVector *v, int pos, float value)
{
	v->data[pos] = value;
}

void append(FloatVector *v, float value)
{
	v->data[v->size] = value;
	v->size++;
}

void print(FloatVector *v)
{
	for(int i = 0; i < v->size; i++)
	{
		printf("%.2f ",v->data[i]);
	}
	printf("\n");
}

void addValues(FloatVector *v, int MAX)
{
	srand(time(NULL));
	for(int i = 0; i < v->capacity; i++)
	{
		append(v,rand() % MAX);
	}
}
