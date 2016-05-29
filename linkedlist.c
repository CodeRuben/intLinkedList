#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/* Adds a node to the beginning of the list. */
 void addfirst(struct list *lis, int data) {
    struct node *newnode = nalloc(data);

    if(newnode == NULL)
        return;
    if(lis->head == NULL) {
        lis->head = newnode;
        lis->tail = newnode;
        return;
    }
    newnode->next = lis->head;
    lis->head = newnode;
}

/* Adds a node to the tail of the list. */ 
void addlast(struct list *lis, int data) {
    struct node *newnode = nalloc(data);
    struct node *tmp = lis->head; 

    /* If the list is initially empty */
    if(lis->head == NULL) {
        lis->head = newnode;
        lis->tail = newnode;
        return;
    }
    lis->tail->next = newnode;
    lis->tail = newnode;
}

/* Checks to see if the list contains a certain element*/
bool contains(struct list *lis, int data) {
    struct node *current = lis->head;

    if(current == NULL)
        return false;

    while(current != NULL) {
        if(current->data == data)
            return true;
        current = current->next;
    }
    return false;
}

/* Deletes the first node of the list. */
bool deletefirst(struct list *lis) {
    struct node *tmp = lis->head;

    if(tmp == NULL)
        return false;

    /* One element list */
    if(tmp->next == NULL) {
        lis->head = lis->tail = NULL;
        free(tmp);
        return true;
    }
    lis->head = tmp->next;
    free(tmp);  // Deallocate memory of deleted node
    return true;
}

/* Deletes the last element in the list. */
bool deletelast(struct list *lis) {
    struct node *current = lis->head;
    struct node *previous = NULL;

    if(current == NULL)
        return false;
    /* If list has one element */
    if(current->next == NULL) {
         lis->head = NULL;
         lis->tail = NULL;
         free(current);
         return true;
    }
    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    lis->tail = previous;
    free(current);  // Deallocate memory of deleted node
    return true;
}

/* Searches for and deletes a node from the list. */
bool delete(struct list *lis, int element) {
    struct node *current = lis->head;
    struct node *previous = NULL;

    if(current == NULL)
        return false;

    while(current != NULL && current->data != element) {
        previous = current;
        current = current->next;
    }
    if(current == NULL)       // Item not found
        return false;
    else if(current == lis->head)   // Item is in the first position
        lis->head = lis->head->next;
    else if(current == lis->tail) {  // Item is in the last position
        previous->next = NULL;
        lis->tail = previous;
    }
    else                     // Item is in the middle of the list
        previous->next = current->next;
    
    if(lis->head == NULL)
        lis->tail = NULL;

    return true;
}

/* Prints out the contents of the linked list. */
void display(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

/* Deallocates memory for every node in the list. */
void freelist(struct list *lis) {
    while(lis->head != NULL)
        deletefirst(lis);
}

/* Allocates space for a new node. */
struct node * nalloc(int data) {
    struct node *p = (struct node *) malloc(sizeof(struct node));
    /* Initialize the members of the new node*/
    if(p != NULL) {
        p->data = data;
        p->next = NULL;
    }
    return p;
}

/* Initializes a new linked list. */
struct list * newlist() {
    struct list *l = (struct list *) malloc(sizeof(struct list));
    if(l != NULL) {
        l->head = NULL;
        l->tail = NULL;
    }
    return l;
}

