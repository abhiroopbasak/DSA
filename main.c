#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
int x;
struct Node*next;
struct Node*prev;
}dl;


dl*head;


void create(dl*);
void display(dl*);
void insert_beg(dl*);
void insert_end(dl*);
void insert_before(dl*);
void insert_after(dl*);
void delete_beg(dl*);
void delete_end(dl*);
void delete_before(dl*);
void delete_after(dl*);


int main()
{
    int ele;
    do
    {
        system("cls");
        printf("****DOUBLY LINKED LIST****\n");
        printf("\n1.\tCreate node\n2.\tDisplay node\n3.\tAdd in the beginning\n4.\tAdd in the end\n5.\tAdd before\n6.\tAdd after\n");
        printf("7.\tDelete at the beginning\n8.\tDelete at the end\n9.\tDelete before\n10.\tDelete after\n11.\tExit\n");
        printf("Enter your choice:");
        scanf("%d",&ele);
        switch(ele)
        {
            case 1:
                head=(dl*)malloc(sizeof(dl));
                head->prev=NULL;
                create(head);
                break;
            case 2:
                display(head);
                getch();
                break;
            case 3:
                insert_beg(head);
                break;
            case 4:
                insert_end(head);
                break;
            case 5:
                insert_before(head);
                break;
            case 6:
                insert_after(head);
                break;
            case 7:
                delete_beg(head);
                break;
            case 8:
                delete_end(head);
                break;
            case 9:
                delete_before(head);
                break;
            case 10:
                delete_after(head);
                break;
            case 11:
                exit(0);
            default:
                printf("\nPlease enter a value between 1 and 11\n");
        }
    }while(ele!=-1);
    return 0;
}


void create(dl *ptr)
{
    char ch='y';
   // dl *new1;
    printf("Creating node of double linked list");
    printf("\nEnter number: ");
    scanf("%d",&ptr->x);
    ptr->next=NULL;
    printf("Do you want to continue?");
    scanf(" %c",&ch);
    if(ch=='y')
    {
        ptr->next=(dl*)malloc(sizeof(dl));
        //ptr->next=new1;
        //new1->prev=ptr;
        //new1->next=NULL;
        ptr->next->prev=ptr;
        ptr=ptr->next;
        create(ptr);
    }
}


void display(dl*ptr)
{
    printf("Displaying the list\n");
    while(ptr->next!=NULL)
    {
        printf("%d -> ",ptr->x);
        ptr=ptr->next;
    }
    do
    {
        printf("%d -> ",ptr->x);
        ptr=ptr->prev;
    }while(ptr!=NULL);

}


void insert_beg(dl *ptr)
{
    dl *new1;
    printf("Insert element in the beginning\n");
    new1=(dl*)malloc(sizeof(dl));
    printf("\nEnter the number: ");
    scanf("%d",&new1->x);
    new1->prev=ptr->prev;
    new1->next=ptr;
    ptr->prev=new1;
    head=new1;
}

void insert_end(dl *ptr)
{
    dl *new1;
    printf("Insert at the end\n");
    new1=(dl*)malloc(sizeof(dl));
    printf("\nEnter the number: ");
    scanf("%d",&new1->x);
    while(ptr->next!=NULL)
        ptr=ptr->next;
    new1->next=ptr->next;
    new1->prev=ptr;
    ptr->next=new1;
}


void insert_before(dl *ptr)
{
    int ele;
    dl*new1;
    printf("Insert before an element\n");
    printf("Insert the element before which to add: ");
    scanf("%d",&ele);
    while(ptr!=NULL)
    {
        if(ptr->x==ele)
        {
            new1=(dl*)malloc(sizeof(dl));
            printf("Enter the number: ");
            scanf("%d",&new1->x);
            if(ptr->prev==NULL)
            {
                new1->next=ptr;
                new1->prev=ptr->prev;
                ptr->prev=new1;
                head=new1;
            }
            else
            {
                new1->next=ptr;
                new1->prev=ptr->prev;
                ptr->prev->next=new1;
                ptr->prev=new1;
            }
        }
        ptr=ptr->next;
    }
}


void insert_after(dl *ptr)
{
    int ele;
    dl*new1;
    printf("Insert after an element: ");
    scanf("%d",&ele);
    while(ptr!=NULL)
    {
        if(ptr->x==ele)
        {
            new1=(dl*)malloc(sizeof(dl));
            printf("\nEnter the element: ");
            scanf("%d",&new1->x);
            if(ptr->next==NULL)
            {
                new1->prev=ptr;
                new1->next=ptr->next;
                ptr->next=new1;
            }
            else
            {
                new1->prev=ptr;
                new1->next=ptr->next;
                ptr->next->prev=new1;
                ptr->next=new1;
            }
        }
        ptr=ptr->next;
    }
}


void delete_beg(dl*ptr)
{
    dl*loc;
    if(ptr==NULL)
    {
        printf("\nUnderflow");
        getch();
    }
    else
    {
        head=ptr->next;
        head->prev=ptr->prev;
        loc=ptr;
        free(loc);
    }
    printf("\nElement deleted at the beginning\n");
}


void delete_end(dl *ptr)
{
    if(ptr==NULL)
    {
        printf("\nUnderflow");
        getch();
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        dl *loc=ptr;
        //ptr1->next=ptr->next;
        ptr->prev->next=ptr->next;
        free(loc);
        printf("\nElement deleted at the end\n");
    }
}


void delete_before(dl *ptr)
{
    int ele;
    dl*loc;
    printf("Enter the element before which you want to delete");
    scanf("%d",&ele);
    if(ptr==NULL)
    {
        printf("Underflow\n");
        getch();
    }
    while(ptr!=NULL)
    {
        if(ptr->x==ele)
        {
            if(ptr->prev==NULL)
            {

                printf("No elements present before\n");
                getch();
            }
            else
            {
                if(ptr->prev->prev==NULL)
                {
                    loc=ptr->prev;
                    ptr->prev=loc->prev;
                    free(loc);
                }
                else
                {
                    loc=ptr->prev;
                    loc->prev->next=ptr;
                    ptr->prev=loc->prev;
                    free(loc);
                }
                printf("Elements deleted\n");
                getch();
            }
        }
        ptr=ptr->next;
    }

}


void delete_after(dl*ptr)
{
    dl*ptr1;
    int ele;
    printf("Enter the element after which you want to delete: ");
    scanf("%d",&ele);
    if(ptr==NULL)
    {
        printf("\nUnderflow");
    }
    while(ptr!=NULL)
    {
        if(ptr->x==ele)
        {
            if(ptr->next==NULL)
            {
                printf("\nNo element after the last element!");
                getch();
            }
            else
            {

                if(ptr->next->next==NULL)
                {
                    ptr1=ptr->next;
                    ptr->next=ptr1->next;
                    free(ptr1);
                }
                else
                {
                    ptr1=ptr->next;
                    ptr1->next->prev=ptr;
                    ptr->next=ptr1->next;
                    free(ptr1);
                }
            printf("\nElements deleted after the element\n");
            }
        }
        ptr=ptr->next;
    }
    getch();
}
