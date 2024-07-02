//Craig Da Gama
//22co10

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *l_child;
    struct node *r_child;
};
struct node *new_node(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->l_child = temp->r_child = NULL;
    return temp;
}
struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return new_node(value);
    }
    if (value < root->data)
    {
        root->l_child = insert(root->l_child, value);
    }
    else if (value > root->data)
    {
        root->r_child = insert(root->r_child, value);
    }
    return root;
}
struct node *find_min(struct node *root)
{
    while (root->l_child != NULL)
    {
        root = root->l_child;
    }
    return root;
}
struct node *remove_node(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return root;
    }
    if (value < root->data)
    {
        root->l_child = remove_node(root->l_child, value);
    }
    else if (value > root->data)
    {
        root->r_child = remove_node(root->r_child, value);
    }
    else
    {
        printf("Node with value %d found and deleted.\n", value);
        if (root->l_child == NULL)
        {
            struct node *temp = root->r_child;
            free(root);
            return temp;
        }
        else if (root->r_child == NULL)
        {
            struct node *temp = root->l_child;
            free(root);
            return temp;
        }
        struct node *temp = find_min(root->r_child);
        root->data = temp->data;
        root->r_child = remove_node(root->r_child, temp->data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->l_child);
        printf("%d ", root->data);
        inorder(root->r_child);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->l_child);
        preorder(root->r_child);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->l_child);
        postorder(root->r_child);
        printf("%d ", root->data);
    }
}
struct node *search(struct node *root, int value)
{
    if (root == NULL || root->data == value)
        return root;
    if (root->data < value)
        return search(root->r_child, value);
    return search(root->l_child, value);
}
int main()
{
    int choice, value;
    struct node *root = NULL;
    printf("Enter a root node : ");
    scanf("%d", &value);
    root = new_node(value);
    printf("1: Insert a node\n2: Delete a node\n3: Display the nodes of the tree in inorder traversal\n4: Display the nodes of the tree in preorder traversal\n5: Display the nodes of the tree in postorder traversal\n6: Search for a value\n7: Exit\n");
    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &value);
            root = remove_node(root, value);
            break;
        case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
        case 5:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter the value to be searched: ");
            scanf("%d", &value);
            if (search(root, value) != NULL)
            {
                printf("Value %d found in the tree.\n", value);
            }
            else
            {
                printf("Value %d not found in the tree.\n", value);
            }
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }
    while (choice != 7);
    return 0;
}
