// craig da gama
// 22co10
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;


void insert()
{
    struct node *p,*temp;
    temp=(struct node *)malloc(sizeof(struct node));

    printf("Enter element to be inserted :");
    scanf("%d",&temp->data);

    temp->link=front;

    if(front==NULL)
    {
        front=temp;
    }
    else
    {
        rear->link=temp;
    }
    rear=temp;
}

void del()
{
    struct node *temp, *p;

    if(front==NULL)
    {
        printf("List is empty");
        return;
    }
    if(front==rear)
    {
        p=front;
        printf("%d deleted",p->data);
        free(p);
        front=rear=NULL;
        return;
    }
    temp=front;
    printf("%d deleted",temp->data);
    front=front->link;
    rear->link=front;
    free(temp);
}

void peek()
{
    printf("front = %d",front->data);
}

void display()
{
    struct node *p;

    if(front==NULL)
    {
        printf("List is empty");
        return;
    }
    p=front;
    do
    {
        printf("%d ",p->data);
        p=p->link;
    }
    while(p!=rear->link);
}

int main()
{

    int choice;

    printf("1: Insert element\n2: Delete element\n3: Display\n4: Peek\n5: Exit");

    while(1)
    {
        printf("\nenter choice :");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}
