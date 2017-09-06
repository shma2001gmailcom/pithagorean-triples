#include <stdio.h>
#include <stdlib.h>
#include "collection.h"

struct node* append(struct triangle* triple, struct node* root, struct node* current)
{
    current = end(current);
    current->next = malloc(sizeof(struct node));
    current = current->next;
    current->next = 0;
    current->data = triple;
    return current;
}

struct node* end(struct node* current)
{
    if ( current != 0 )
    {
        while ( current->next != 0)
        {
            current = current->next;
        }
    }
    return current;
}

struct node* createRoot(struct triangle* triple, struct node* root, struct node* current)
{
    root = malloc(sizeof(struct node));
    root->next = 0;
    root->data = triple;
    current = root;
    return current;
}

struct node* pyth(int limit)
{
    struct node* root = 0;
    struct node* current = 0;
    struct triangle first = initial();
    root = createRoot(&first, root, current);
    current = end(root);
    int hypo = 0;
    int m = 2;
    while (hypo < limit)
    {
        for (int n = 1; n < m; ++n)
        {
            hypo = m*m + n*n;
            if(hypo > limit) break;
            struct triangle* triple = make_triple(m*m - n*n, 2*m*n, hypo);
            printf("\n%d %d %d from (%d, %d)\n ", m*m - n*n, 2*m*n, hypo, m, n);
            append(triple, root, current);
            current = current->next;
        }
        ++m;
    }
    current = root;
    return root;
}

struct triangle* make_triple(int small, int big, int hypo)
{
    struct triangle* result = (struct triangle*) malloc(sizeof(struct triangle));
    result->small_catet = small;
    result->big_catet = big;
    result->hypotenuse = hypo;
    return result;
}

struct triangle initial()
{
    struct triangle INITIAL;
    INITIAL.small_catet = 3;
    INITIAL.big_catet = 4;
    INITIAL.hypotenuse = 5;
    return INITIAL;
}




