// program to perform operations on queue
// 22co10 Craig Da Gama
#include<stdio.h>
#define MAX 5
int front = -1, rear = -1, queue[MAX], i;
//function for insert/enqueue operation
void insert(int i)
{
    if(rear==MAX-1)
        printf("queue overflow\n");
    else
    {
        if(front==-1)
            front=0;
            rear++;
        queue[rear] = i;

    }
}
//function to delete/dequeue elements from the queue
int delete()
{
    if(front == -1 || front>rear)
    {
    printf("queue underflow\n");
    }
    else{
    i = queue[front];
    front++;
    printf("Element deleted successfully\n");
    return front;
    }
}
//function to check overflow condition
void isfull()
{
    if(rear == MAX -1)
        printf("queue overflow\n");
    else
     printf("queue is not full\n");
}
//function to check underflow condition
void isempty()
{
    if(front == -1 ||front>rear)
        printf("queue underflow\n");
    else
        printf("queue is not empty\n");
}
//function to display front most element
void peek()
{
     if(front == -1 ||front>rear)
        printf("queue underflow\n");
     else
        printf("front element is %d\n",queue[front]);
}
//function to display queue
void display()
{
    int i;
    if(front == -1 ||front>rear)
        printf("queue underflow\n");
    else
    {
        for(i=front ;i<=rear;i++)
        {
        printf("%d ", queue[i]);
        printf("\n");
        }
    }
}

int main()
{
    void exit();
    int c;
    while(1)
    {
    printf("Choose operation to perform: \n1: insertion\n2: deletion\n3: queue overflow\n4: queue underflow\n5: peek\n6: display\n7: exit\n");
    scanf("%d", &c);
    switch(c)
    {
    case 1: printf("Enter element to insert: ");
            scanf("%d", &i);
            insert (i);
            break;

    case 2: delete();
            break;

    case 3: isfull();
            break;

    case 4: isempty();
            break;

    case 5: peek();
            break;

    case 6: display();
            break;

    case 7: exit(1);
            break;
    default:
        printf("Invalid choice\n");
        break;
        }
    }
}
