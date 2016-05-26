#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    struct list *list = newlist();
    int i, result, flag = 0; 

    for(i = 0; i < 20; i++)
        addlast(list, i + 1);

    printf("List after 20 additions....\n");
    display(list->head);
    
    printf("\n\nContains testing...\n");
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

    printf("\nList after 10 deletions....\n");
    display(list->head);
    printf("\n\n");
    
    return 0;
}
