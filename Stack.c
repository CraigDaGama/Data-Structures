// program to perform operations on stacks
// 22co10 Craig Da Gama
#include<stdio.h>
void push(int);
int pop();
void overflow();
void underflow();
int pop();
void display();

int stack[10],top=-1,MAX=10;
int main()
{
    int item,choice,element;
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. STACK OVERFLOW\n");
        printf("4. STACK UNDERFLOW\n");
        printf("5. PEEK\n");
        printf("6. DISPLAY\n");
        printf("7. QUIT\n");
    while(1)
    {   printf("enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :printf("enter the element to be inserted\n");
                scanf("%d",&item);
                push(item);
                break;
        case 2 :element=pop();
                printf("Element %d deleted\n",element);
                break;
        case 3 :overflow();
                break;
        case 4 :underflow();
                break;
        case 5 :printf("top element = %d\n",stack[top]);
                break;
        case 6 :display();
                break;
        case 7 :exit(1);
        }
    }
}

void display()
{
    if(top==-1)
        printf("stack underflow\n");
    else
    {
        int i;
        for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
        printf("\n");
    }
}

void push(int item)
{
    if(top==MAX-1)
        printf("Stack overflow \n");
    else
        {
        top=top+1;
        stack[top]=item;
        }
}

int pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack underflow \n");
        return;
    }
    else
    {
        item=stack[top];
        top=top-1;
        return item;
    }
}

void overflow()
{
    if(top==MAX-1)
        printf("stack overflow\n");
    else
        printf("Elements can be inserted\n");
}

void underflow()
{
    if(top==-1)
    {
    printf("stack underflow\n");
    }
    else printf("Stack is not empty\n");
}
