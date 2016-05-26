#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

void addfirst(struct list *, int);
void addlast(struct list *, int);
int contains(struct list *, int);
int deletefirst(struct list *);
int deletelast(struct list *);
void display(struct node *);


#endif // LINKEDLIST_H_INCLUDED
