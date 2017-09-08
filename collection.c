#include <stdio.h>
#include <stdlib.h>
#include "collection.h"


void print_greeting(char* file_name)
{
    size_t read;
    char* buf = malloc(SIZE);
    if (buf == NULL)
    {
        printf("out of memory.");
    }
    FILE* file = fopen(file_name, "r");
    while ((read = fread(buf, 1, sizeof buf, file)) > 0)
        fwrite(buf, 1, read, stdout);
    if (ferror(file))
    {
        print_greeting("error.txt");
    }
    fclose(file);
}

struct node* append(struct triangle* triple, struct node* current)
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

struct node* create_root(struct triangle* triple, struct node* root, struct node* current)
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
    struct triangle* first = make_triple(2, 3, 4);
    root = create_root(first, root, current);
    current = end(root);
    int hypo = 0;
    int m = 3;
    while (hypo < limit)
    {
        for (int n = 1; n < m; ++n)
        {
            hypo = m*m + n*n;
            if(hypo > limit) break;
            struct triangle* triple = make_triple(m*m - n*n, 2*m*n, hypo);
            append(triple, current);
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
