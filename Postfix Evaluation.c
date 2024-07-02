// craig da gama
// 22co10
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack
{
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack)
        return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array)
        return NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item)
{
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack)
{
    return stack->array[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp)
{
    struct Stack* stack = createStack(100);
    if (!stack)
        return -1; // Stack creation failed

    for (int i = 0; exp[i]; i++)
    {
        if (isdigit(exp[i]))
        {
            push(stack, exp[i] - '0');
        }
        else
        {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (exp[i])
            {
            case '+':
                push(stack, operand1 + operand2);
                break;
            case '-':
                push(stack, operand1 - operand2);
                break;
            case '*':
                push(stack, operand1 * operand2);
                break;
            case '/':
                push(stack, operand1 / operand2);
                break;
            }
        }
    }
    int result = pop(stack);
    free(stack);
    return result;
}

int main()
{
    char exp[100];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Result of evaluation: %d\n", result);
    return 0;
}



