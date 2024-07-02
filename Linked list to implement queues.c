// singly linked list to implement queues
// 22co10 Craig Da Gama
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

void insert()
{
    int x;
    printf("enter the element to be inserted: ");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));

    if (tmp==NULL)
        printf("no space for dynamic memory allocation");
    else
    {
        tmp->data=x;
        tmp->link=NULL;
        if (front==NULL)
            front=tmp;
        else
            rear->link=tmp;
        rear=tmp;
        printf("element inerted is %d\n",x);
    }
}

void delete()
{
    struct node *p;
    if (front==NULL)
        printf("the list is empty\n");
    else
    {
        p=front;
        front=p->link;
        printf("element %d is deleted\n",p->data);
        free(p);
    }
}

underflow()
{
    if (front==NULL)
        printf("underflow\n");
    else
        printf("elements can be deleted\n");
}

void peek()
{
    if (front==NULL)
        printf("underflow\n");
    else
        printf("front element is %d\n",front->data);
}

void display()
{
    struct node *p;
    p=front;
    if(p==NULL)
    {
        printf("underflow\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("1: insert\n2: delete\n3: underflow\n4: peak\n5: display\n6: exit");
    while(1)
    {
        printf("\nenter choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insert();
                    break;
            case 2:delete();
                    break;
            case 3:underflow();
                    break;
            case 4:peek();
                    break;
            case 5:display();
                    break;
            case 6:exit(0);
                    break;
            default:printf("invalid choice\n");
        }
    }
    return 0;
}

