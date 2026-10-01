#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION 300
#define MAX_STACK 100

int main(void)
{
    char expression[MAX_EXPRESSION];
    double stack[MAX_STACK];
    int top = -1;
    printf("Enter a space-separated postfix expression: ");
    scanf(" %299[^\n]", expression);

    char *token = strtok(expression, " ");
    while (token != NULL)
    {
        char *end;
        double value = strtod(token, &end);
        if (*end == '\0')
        {
            if (top == MAX_STACK - 1)
            {
                printf("Stack overflow.\n");
                return 1;
            }
            stack[++top] = value;
        }
        else if (strlen(token) == 1 && strchr("+-*/%", token[0]) != NULL)
        {
            if (top < 1)
            {
                printf("Invalid postfix expression.\n");
                return 1;
            }
            double right = stack[top--];
            double left = stack[top--];
            switch (token[0])
            {
            case '+':
                stack[++top] = left + right;
                break;
            case '-':
                stack[++top] = left - right;
                break;
            case '*':
                stack[++top] = left * right;
                break;
            case '/':
                if (right == 0)
                {
                    printf("Division by zero.\n");
                    return 1;
                }
                stack[++top] = left / right;
                break;
            case '%':
                stack[++top] = (int)left % (int)right;
                break;
            }
        }
        else
        {
            printf("Invalid token: %s\n", token);
            return 1;
        }
        token = strtok(NULL, " ");
    }

    if (top != 0)
    {
        printf("Invalid postfix expression.\n");
        return 1;
    }
    printf("Result: %.2f\n", stack[top]);
    return 0;
}
