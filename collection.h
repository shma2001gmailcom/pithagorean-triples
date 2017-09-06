#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

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

struct node* pyth(int);

struct node* append(struct triangle* data, struct node* root, struct node* current);

struct node* end(struct node* current);

struct node* createRoot(struct triangle* triple, struct node* root, struct node* current);

struct triangle* make_triple(int small, int big, int hypo);

struct triangle initial();

#endif // LIST_H_INCLUDED
