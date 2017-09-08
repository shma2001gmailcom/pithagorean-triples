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

void print_greeting(char* file_name);

struct node* pyth(int);

struct node* append(struct triangle* data, struct node* current);

struct node* end(struct node* current);

struct node* create_root(struct triangle* triple, struct node* root, struct node* current);

struct triangle* make_triple(int small, int big, int hypo);

#endif // LIST_H_INCLUDED
