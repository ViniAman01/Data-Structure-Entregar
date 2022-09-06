#ifndef _SORT_C
#define _SORT_C
#include "float_vector.h"

void quicksort(FloatVector *v, int inicio, int fim);
void selecsort(FloatVector *v);
void bubsort(FloatVector *v);
void mergeSort(FloatVector *v, int inicio, int fim);
void swap(FloatVector *v, int pos, int pos2);

#endif
