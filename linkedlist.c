#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define TRUE 1
#define FALSE 0

struct node * nalloc(int);
struct list * newlist();

/**
 * Adds a new node to the start of the linked list
 * @param struct list, struct containing the head pointer
 * @param data, value to be stored in the list
 */
 void addfirst(struct list *l, int data) {
    struct node *newnode = nalloc(data);

    if(newnode == NULL)
        return;
    newnode->next = l->head;
    l->head = newnode;
}

/**
 * Adds a new node to the end of the linked list
 * @param struct list, struct containing the head pointer
 * @param data, value to be stored in the list
 */
void addlast(struct list *lis, int data) {
    struct node *newnode = nalloc(data);
    struct node *tmp = lis->head;

    if(lis->head == NULL) {
        lis->head = newnode;
        return;
    }
    /* Get to the tail end of the list */
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newnode;
}

/**
 * Checks to see if the list has a given value
 * @param struct list, struct containing the head pointer
 * @param data, the value to be searched for
 * @return 1 if the value is found, 0 otherwise
 */
int contains(struct list *lis, int data) {
    struct node *current = lis->head;

    if(current == NULL)
        return FALSE;

    while(current != NULL) {
        if(current->data == data)
            return TRUE;
        current = current->next;
    }
    return FALSE;
}

/**
 * Deletes the first element in the linked list
 * @param struct list, struct containing head pointer
 * @return 1 if the value was deleted, 0 otherwise
 */
int deletefirst(struct list *lis) {
    struct node *tmp = lis->head;

    if(tmp == NULL)
        return -1;
    lis->head = tmp->next;
    free(tmp);
    return 0;
}

/**
 * Deletes the last element in the linked list
 * @param struct list, struct containing head pointer
 * @return 1 if the value was deleted, 0 otherwise
 */
int deletelast(struct list *lis) {
    struct node *current = lis->head;
    struct node *previous = NULL;

    if(current == NULL)
        return FALSE;
    /* If list has one element */
    if(current->next == NULL) {
         lis->head = NULL;
         free(current);
         return TRUE;
    }
    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);  // Deallocate memory of deleted node
    return TRUE;
}

/**
 * Prints all of the elements in the list
 * @param struct node, the head pointer of the list
 */
void display(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

/**
 * Creates and allocates memory for a new node
 * @param data, the value to be stored in the node
 * @return struct node *, a pointer to the new node
 */
struct node * nalloc(int data) {
    struct node *p = (struct node *) malloc(sizeof(struct node));
    /* Initialize the members of the new node*/
    if(p != NULL) {
        p->data = data;
        p->next = NULL;
    }
    return p;
}

/**
 * Creates a new list structure. The list contains a pointer
 * that will serve as the head of the linked list.
 * @return struct list *, a pointed to the new list structure
 */
struct list * newlist() {
    struct list *l = (struct list *) malloc(sizeof(struct list));
    if(l != NULL)
        l->head = NULL;
    return l;
}

