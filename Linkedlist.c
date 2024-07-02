// operations on singly linked list
// 22co10 Craig Da Gama
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *start=NULL;

void insertatbeg()
{
    struct node *p,*tmp;
    int element;
    printf("Enter element to be inserted :");
    scanf("%d",&element);
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        tmp->link=NULL;
        tmp->data=element;
        start=tmp;
        return;
    }
    else
    {
        tmp->data=element;
        tmp->link=start;
        start=tmp;
        return;
    }
}

void insertAtEnd()
{
    struct node *p,*tmp;
    int element;
    printf("Enter element to be inserted :");
    scanf("%d",&element);
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
    {
        tmp->link=NULL;
        tmp->data=element;
        start=tmp;
        return;
    }
    else
    {
        p=start;
        while(p->link!=NULL)
            p=p->link;
        tmp->data=element;
        tmp->link=NULL;
        p->link=tmp;
        return;
    }
}

void insertAftNode()
{
    struct node *p,*tmp;
    int element,item;

    if(start==NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Enter element to be inserted :");
    scanf("%d",&element);
    printf("Enter element after which to be inserted :");
    scanf("%d",&item);
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start->data==item)
    {
        tmp->link=start->link;
        tmp->data=element;
        start->link=tmp;
        return;
    }
    else
    {
        p=start;
        while(p!=NULL)
        {
            if(p->data==item)
            {
                tmp->data=element;
                tmp->link=p->link;
                p->link=tmp;
                return;
            }
            p=p->link;
        }
    }
    printf("element not found");
    return;
}

void insertBfrNode()
{
    struct node *p,*tmp;
    int element,item;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    printf("Enter element to be inserted :");
    scanf("%d",&element);
    printf("Enter element before which to be inserted :");
    scanf("%d",&item);
    tmp=(struct node *)malloc(sizeof(struct node));
    if(start->data==item)
    {
        tmp->link=start;
        tmp->data=element;
        start=tmp;
        return;
    }
    else
    {
        p=start;
        while(p->link!=NULL)
        {
            if(p->link->data==item)
            {
                tmp->data=element;
                tmp->link=p->link;
                p->link=tmp;
                return;
            }
            p=p->link;
        }
    }
        printf("element not found");
        return;
}

void insertAtPos(){
    struct node *p,*tmp;
    int element,pos,i;

    printf("Enter element to be inserted :");
    scanf("%d",&element);

    printf("Enter position to be inserted at:");
    scanf("%d",&pos);

    tmp=(struct node *)malloc(sizeof(struct node));

    if(pos==1)
    {
        tmp->link=start;
        tmp->data=element;
        start=tmp;
        return;
    }
    else{
        p=start;
        for(i=1; i<pos-1 && p!=NULL;i++)
        p=p->link;
        if(p==NULL)
        {
            printf("less than %d elements present",pos);
            return;
        }

        else
        {
            tmp->link=p->link;
            tmp->data=element;
            p->link=tmp;
        }
        return;
    }
}

void delBeg()
{
    struct node *p,*tmp;
    int element;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp=start;
    start=start->link;
    printf("Element %d deleted\n",tmp->data);
    free(tmp);
    return;
    }

void delEnd()
{
    struct node *p,*tmp;
    int element;
    if(start==NULL)
    {
        printf("List is empty");
        return;
    }
    if(start->link==NULL)
    {
        printf("Element %d deleted\n",start->data);
        start=NULL;
        return;
    }
    tmp=(struct node *)malloc(sizeof(struct node));
    p=start;
    while(p->link->link!=NULL)
    p=p->link;
    tmp=p->link;
    p->link=NULL;
    printf("Element %d deleted\n",tmp->data);
    free(tmp);
    return;
}

void del_element()
{
    struct node *p,*tmp;
    int element;
    if(start==NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to be deleted:");
    scanf("%d",&element);

    tmp=(struct node *)malloc(sizeof(struct node));
    if(start->data==element)
    {
        tmp=start;
        start=start->link;
        free(tmp);
        return;
    }
    p=start;
    while(p->link->data!=element)
    p=p->link;
    tmp=p->link;
    p->link=tmp->link;
    printf("Element %d deleted\n",tmp->data);
    free(tmp);
    return;
}

void display()
{
    struct node *p;
    p=start;
    if(p==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
    printf("\n");
}

void count()
{
    struct node *p;
    int count=0;
    p=start;
    while(p!=NULL)
    {
        p=p->link;
        count++;
    }
    printf("count = %d \n",count);
}

void search()
{
    struct node *p;
    int element,pos=1;

    printf("Enter element to be searched:");
    scanf("%d",&element);
    if(start->data==element)
    {
        printf("element %d found at position %d\n",element,pos);
        return;
    }

    p=start;
    while(p!=NULL)
    {
        if(p->data==element)
        {
            printf("element %d found at position %d\n",element,pos);
            return;
        }
        p=p->link;
        pos++;
    }
    printf("element not found\n");
}

void reversal()
{

        if(start==NULL)
        {
            printf("List is empty");
            return;
        }

        struct node *ptr, *prev, *next;
        prev=NULL;
        ptr=start;

        while(ptr!=NULL)
        {
            next=ptr->link;
            ptr->link=prev;
            prev=ptr;
            ptr=next;
        }
        start=prev;
        printf("reversal complete.");
}

int main()
{
    int choice;
    printf("1: insert at beginning\n2: insert at end\n3: insert after node\n4: insert before node\n5: insert at position\n6: delete first element\n7: delete last element\n8: delete element\n9: display\n10: count\n11: search\n12: reverse list\n13: exit");
    while(1)
    {
        printf("\nenter choice :");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:insertatbeg();
                    break;
            case 2:insertAtEnd();
                    break;
            case 3:insertAftNode();
                    break;
            case 4:insertBfrNode();
                    break;
            case 5:insertAtPos();
                    break;
            case 6:delBeg();
                    break;
            case 7:delEnd();
                    break;
            case 8:del_element();
                    break;
            case 9:display();
                    break;
            case 10:count();
                    break;
            case 11:search();
                    break;
            case 12:reversal();
                    break;
            case 13:exit(0);
                    break;
            default:printf("invalid choice\n");
        }
    }
    return 0;
}



