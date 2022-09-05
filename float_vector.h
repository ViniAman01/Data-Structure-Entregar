#ifndef _FLOAT_VECTOR_
#define _FLOAT_VECTOR_

typedef struct float_vector FloatVector;

FloatVector *create(int tam);
void destroy(FloatVector *v);
int size(const FloatVector *v);
int capacity(const FloatVector *v);
float at(const FloatVector *v, int pos);
void append(FloatVector *v, float value);
void print(FloatVector *v);
void put(FloatVector *v, int pos, float value);
void addValues(FloatVector *v, int MAX);

#endif