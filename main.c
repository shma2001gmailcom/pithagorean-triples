#include <stdio.h>
#include <stdlib.h>
#include "collection.h"

int main()
{
    int limit = 0;
    while(limit < 2 || limit >= 100000000)
    {
        printf("Type positive integer greater than 2 and less then 100000000 : ");
        scanf("%d", &limit);
    }
    struct node* result = pyth(limit);
    struct node* current = result;
    FILE* file = fopen("../../answer.txt", "w");
    while (current != NULL)
    {
        struct triangle* triple = current->data;
        fprintf(file, "%d %d %d\n", triple->small_catet, triple->big_catet, triple->hypotenuse);
        current = current->next;
    }
    fclose(file);
    current = result;
    return 0;
}
