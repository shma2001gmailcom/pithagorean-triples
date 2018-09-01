#include <stdio.h>
#include <stdlib.h>
#include "collection.h"

int main()
{
    print_greeting("../resources/greeting.txt");
    int limit = 0;
    while (limit < 2 || limit > 600000000)
    {
        print_greeting("../resources/error.txt");
        scanf("%d", &limit);
    }
    struct node* const result = pyth(limit);
    struct node* current = result;
    FILE* const file = fopen("../../answer.txt", "w");
    while (current != NULL)
    {
        struct triangle* const triple = current->data;
        fprintf(file, "%d %d %d\n", triple->small_catet, triple->big_catet, triple->hypotenuse);
        current = current->next;
    }
    fclose(file);
    return 0;
}


