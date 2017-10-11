#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{   int data;
    struct node *next;
};

typedef struct node * NODE; //Alias created for the pointer to another node
NODE head=NULL, current, newNode; // a global declaration to enable access throughout the program

void display()
{   if(head == NULL)
        printf("\nNo elements to show.");
    else
    {   printf("\nList data: ");
        current = head;
        while(current->next != NULL)
        {   printf("%d ", current->data);
            current = current->next;
        }
        printf("%d \n", current->data);
    }
}

void addElement()
{   int element_data;
    printf("\nEnter element data: ");
    scanf("%d", &element_data);

    newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = element_data;
    newNode->next = NULL;

    if(head == NULL)
    {   head = newNode;
    }
    else
    {   current = head;
        while(current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    display();
}

void deleteByIndex()
{   int index_value, count=0;
    printf("\nEnter index of element to delete: ");
    scanf("%d", &index_value);
    if(index_value == 1)
    {   printf("\nValue deleted: %d\n", head->data);
        head = head->next;
        goto deleted1;
    }
    current = head;
    while(current->next != NULL)
    {   count++;
        if(index_value == count+1)
        {   printf("\nValue deleted: %d\n", current->next->data);
            current->next = current->next->next;
            goto deleted1;
        }
        else current = current->next;
    }
    deleted1:
    display();
}

void deleteByValue()
{   NODE prev;
    int del_value;
    printf("\nEnter value of element to delete: ");
    scanf("%d", &del_value);
    if(del_value == head->data)
    {   printf("\nValue deleted: %d\n", current->data);
        head = head->next;
        goto deleted2;
    }
    current = head;
    prev = head;
    while(current->next != NULL)
    {   if(del_value == current->data)
        {   printf("\nValue deleted: %d\n", current->data);
            prev->next = current->next;
            goto deleted2;
        }
        else
        {   prev = current;
            current = current->next;
        }
    }
    if(del_value == current->data)
        {   printf("\nValue deleted: %d\n", current->data);
            prev->next = NULL;
            goto deleted2;
        }
    deleted2:
    display();

}

int main()
{   int choice, element_data;
    start:
    printf("\n1. Add Element\n2. Delete an element by index\n3. Delete an element by value\n4. Display\n\nEnter choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            addElement();
            goto start;
        case 2:
            deleteByIndex();
            goto start;
        case 3:
            deleteByValue();
            goto start;
        case 4:
            display();
            goto start;
        default:
            exit(0);
    }
    return 0;
}
