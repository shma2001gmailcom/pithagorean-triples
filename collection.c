#include <stdio.h>
#include <stdlib.h>
#include "collection.h"

void print_greeting(char* const file_name)
{
    char* const buf = malloc(SIZE);
    if (buf == NULL)
    {
        printf("out of memory.");
    }
    FILE* const file = fopen(file_name, "r");
    size_t read;
    while ((read = fread(buf, 1, sizeof buf, file)) > 0)
    {
        fwrite(buf, 1, read, stdout);
    }
    if (ferror(file))
    {
        print_greeting("error.txt");
    }
    fclose(file);
}

struct node* const append(struct triangle* const triple, struct node* current)
{
    current = end(current);
    current->next = malloc(sizeof(struct node));
    current = current->next;
    current->next = 0;
    current->data = triple;
    return current;
}

struct node* const end(struct node* current)
{
    if (current != 0)
    {
        while (current->next != 0)
        {
            current = current->next;
        }
    }
    return current;
}

struct node* const create_root(struct triangle* const triple, struct node* root, struct node* current)
{
    root = malloc(sizeof(struct node));
    root->next = 0;
    root->data = triple;
    current = root;
    return current;
}

struct node* const pyth(const int limit)
{
    struct node* root = 0;
    struct node* current = 0;
    struct triangle* const first = make_triple(2, 3, 4);
    root = create_root(first, root, current);
    current = end(root);
    int hypo = 0;
    int m = 3;
    while (hypo < limit)
    {
        for (int n = 1; n < m; ++n)
        {
            hypo = m*m + n*n;
            if (hypo > limit) break;
            struct triangle* const triple = make_triple(m*m - n*n, 2*m*n, hypo);
            append(triple, current);
            current = current->next;
        }
        ++m;
    }
    current = root;
    return root;
}

struct triangle* const make_triple(const int small,const int big, const int hypo)
{
    struct triangle* const result = (struct triangle*) malloc(sizeof(struct triangle));
    result->small_catet = small;
    result->big_catet = big;
    result->hypotenuse = hypo;
    return result;
}
