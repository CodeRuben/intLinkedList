#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() 
{
    Linkedlist *list = newlist();
    int i, result, flag = 0; 

    for(i = 0; i < 20; i++)
        addlast(list, i + 1);

    printf("List after 20 additions...Should print 1-20\n");
    display(list->head);
    
    printf("\n\nContains testing....\n");
    for(i = 0; i < 20; i++) {
        result = contains(list, i + 1);
        if(result != 1)
            flag++;
    }
    if(flag == 0)
        printf("Success, no errors found\n");
    else
        printf("Error in contains function\n");

    for(i = 0; i < 10; i++)
        deletefirst(list);
    printf("\nList after 10 deletions...Should print 11-20\n");
    display(list->head);
    
    for(i = 0; i < 10; i++)
        deletelast(list);
    printf("\n\nList after 10 deletions...Shouldn't print anything\n");
    display(list->head);
    
    /* Testing freelist() function */
    for(i = 0; i < 10; i++)
        addlast(list, i + 1);
    freelist(list);
    if(list->head != NULL)
        printf("freelist failed");
    
    printf("\n\n");
    
    return 0;
}
