#include <stdio.h>
#include <stdlib.h>
#include "collection.h"





int main()
{
    int limit;
    printf("Type positive integer greater than 2 and less then 100000000 : ");
    scanf("%d", &limit);
    if(limit < 2 || limit >= 100000000)
    {
        printf("input is incorrect.");
        return 0;
    }
    struct node* result = pyth(limit);
    struct node* current = result;
    while (current != NULL)
    {
        struct triangle* triple = current->data;
        printf("%d %d %d\n", triple->small_catet, triple->big_catet, triple->hypotenuse);
        current = current->next;
    }
    current = result;
    return 0;
}



