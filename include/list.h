#ifndef LIST_H_
#define LIST_H_

typedef struct
{
    void *arr;
    size_t size;
    size_t elem_size;
    unsigned int pos;
} ArrayList;

int al_init(ArrayList *l, size_t elem_size);
int al_is_empty(ArrayList *l);
int al_insert(ArrayList *l, void *elem);
int al_get(ArrayList *l, unsigned int index, void *elem);


struct Node 
{
    struct Node *next;
    struct Node *prev;
    void *data;
};

typedef struct 
{
    struct Node *first;
    struct Node *last;
    size_t size;
} LinkedList;

int ll_init(ArrayList *l);
int ll_is_empty(ArrayList *l);
int al_insert(ArrayList *l);


#endif
