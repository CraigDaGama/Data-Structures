// craig da gama
// 22co10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to determine the precedence of operators
int precedence(char operator)
{
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    return 0; // Default precedence
}

// Function to check if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to convert infix expression to postfix
void infixToPostfix(const char* infix, char* postfix)
{
    int i, j;
    char stack[MAX_SIZE];
    int top = -1;

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        char token = infix[i];

        if (isOperator(token))
        {
            // Pop operators with higher or equal precedence from the stack
            while (top >= 0 && precedence(stack[top]) >= precedence(token))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token;
        }
        else if (token == '(')
        {
            stack[++top] = token;
        }
        else if (token == ')')
        {
            // Pop operators from the stack until an opening parenthesis is encountered
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(')
                top--; // Pop the opening parenthesis
        }
        else
        {
            // If the token is an operand, copy it to the output
            postfix[j++] = token;
        }
    }

    // Pop any remaining operators from the stack
    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}
