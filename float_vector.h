#ifndef _FLOAT_VECTOR_
#define _FLOAT_VECTOR_

typedef struct float_vector FloatVector;

FloatVector *create(int tam);
void destroy(FloatVector *ref_vector);
int size(const FloatVector *vector);
int capacity(const FloatVector *vector);
float at(const FloatVector *vector, int pos);
float get(const FloatVector *vector, int pos);
void append(FloatVector *vector, float value);
void print(FloatVector *vector);
void put(FloatVector *vector, int pos, float value);

#endif
