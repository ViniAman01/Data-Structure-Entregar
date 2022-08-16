#include <stdio.h>
#include <stdlib.h>
#include "float_vector.h"
#include "sort.h"
#define TAM 5

int main(void)
{
    FloatVector *v;
    v = create(5);

    append(v,5.2);
    append(v,3.2);
    append(v,1.3);
    append(v,2.5);
    append(v,6.8);

    print(v);

    bubsort(v);
    
    print(v);


    return 0;
}