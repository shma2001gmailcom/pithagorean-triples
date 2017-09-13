#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define SIZE 1024

struct node
{
    struct triangle* data;
    struct node* next;
};

struct triangle
{
    int small_catet;
    int big_catet;
    int hypotenuse;
};

void print_greeting(char* const file_name);

struct node* const pyth(const int);

struct node* const append(struct triangle* const data, struct node* current);

struct node* const end(struct node* current);

struct node* const create_root(struct triangle* const triple, struct node* const root, struct node* current);

struct triangle* const make_triple(const int small, const int big, const int hypo);

#endif // LIST_H_INCLUDED
