#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdbool.h>

struct node {
    int data;  
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

typedef struct list Linkedlist;

/**
 * Adds a new node to the start of the linked list
 * @param struct list, struct containing the head pointer
 * @param data, value to be stored in the list
 */
void addfirst(struct list *, int);

/**
 * Adds a new node to the end of the linked list
 * @param struct list, struct containing the head pointer
 * @param data, value to be stored in the list
 */
void addlast(struct list *, int);

/**
 * Checks to see if the list has a given value
 * @param struct list, struct containing the head pointer
 * @param data, the value to be searched for
 * @return true if the value is found, false otherwise
 */
bool contains(struct list *, int);

/**
 * Deletes the first element in the linked list
 * @param struct list, struct containing head pointer
 * @return true if the value was deleted, false otherwise
 */
bool deletefirst(struct list *);

/**
 * Deletes the last element in the linked list
 * @param struct list, struct containing head pointer
 * @return 1 if the value was deleted, -1 otherwise
 */
bool deletelast(struct list *);

/**
 * Searches for an element and deletes it if it's found
 * @param struct list, struct containing head pointer
 * @param int, element to be searched for
 * @return true if the value was deleted, false otherwise
 */
bool delete(struct list *, int data);

/**
 * Prints all of the elements in the list
 * @param struct node, the head pointer of the list
 */
void display(struct node *);

/**
 * Empties the list and all of its contents. Deallocates
 * memory of each node.
 * @param struct list, the list containing the head pointer
 */
void freelist(struct list *);

/**
 * Creates and allocates memory for a new node
 * @param data, the value to be stored in the node
 * @return struct node *, a pointer to the new node
 */
struct node * nalloc(int);

/**
 * Creates a new list structure. The list contains a pointer
 * that will serve as the head of the linked list.
 * @return struct list *, a pointed to the new list structure
 */
struct list * newlist();

#endif // LINKEDLIST_H_INCLUDED
