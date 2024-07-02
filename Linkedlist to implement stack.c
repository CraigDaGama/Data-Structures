// singly linked list to implement stacks
// 22co10 Craig Da Gama
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top=NULL;

void push()
{
    int x;
    printf("enter the element to be inserted: ");
    scanf("%d",&x);
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));

    if (tmp==NULL)
        printf("stack overflow");
    else
    {
        tmp->data=x;
        tmp->link=top;
        top=tmp;
    }
}

void pop()
{
    struct node *p;
    if (top==NULL)
        printf("the list is empty\n");
    else
    {
        p=top;
        top=p->link;
        printf("element %d is deleted\n",p->data);
        free(p);
    }
}

underflow()
{
    if (top==NULL)
        printf("underflow\n");
    else
        printf("elements can be deleted\n");
}

void peek()
{
    if (top==NULL)
        printf("underflow\n");
    else
        printf("%d\n",top->data);
}

void display()
{
    struct node *p;
    p=top;
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
            case 1:push();
                    break;
            case 2:pop();
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
