#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSION 200

typedef struct
{
    char items[MAX_EXPRESSION][MAX_EXPRESSION];
    int top;
} StringStack;

int isOperator(char token)
{
    return token == '+' || token == '-' || token == '*' ||
           token == '/' || token == '^';
}

int precedence(char operator)
{
    if (operator == '^')
        return 3;
    if (operator == '*' || operator == '/')
        return 2;
    if (operator == '+' || operator == '-')
        return 1;
    return 0;
}

void push(StringStack *stack, const char value[])
{
    if (stack->top < MAX_EXPRESSION - 1)
        strcpy(stack->items[++stack->top], value);
}

void pop(StringStack *stack, char value[])
{
    if (stack->top >= 0)
        strcpy(value, stack->items[stack->top--]);
    else
        value[0] = '\0';
}

void appendOperator(char output[], int *length, char operator)
{
    output[(*length)++] = operator;
    output[*length] = '\0';
}

void infixToPostfix(const char infix[], char postfix[], int reversed)
{
    char operators[MAX_EXPRESSION];
    int top = -1;
    int length = 0;

    postfix[0] = '\0';
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char token = infix[i];
        if (isalnum((unsigned char)token))
            postfix[length++] = token;
        else if (token == '(')
            operators[++top] = token;
        else if (token == ')')
        {
            while (top >= 0 && operators[top] != '(')
                appendOperator(postfix, &length, operators[top--]);
            if (top >= 0)
                top--;
        }
        else if (isOperator(token))
        {
            while (top >= 0 && operators[top] != '(' &&
                   (precedence(operators[top]) > precedence(token) ||
                    (precedence(operators[top]) == precedence(token) &&
                     (reversed || token != '^'))))
                appendOperator(postfix, &length, operators[top--]);
            operators[++top] = token;
        }
    }
    while (top >= 0)
        appendOperator(postfix, &length, operators[top--]);
}

void reverseExpression(const char source[], char destination[])
{
    int length = 0;
    for (int i = (int)strlen(source) - 1; i >= 0; i--)
    {
        if (source[i] == '(')
            destination[length++] = ')';
        else if (source[i] == ')')
            destination[length++] = '(';
        else
            destination[length++] = source[i];
    }
    destination[length] = '\0';
}

void infixToPrefix(const char infix[], char prefix[])
{
    char reversed[MAX_EXPRESSION];
    char postfix[MAX_EXPRESSION];
    char result[MAX_EXPRESSION];
    reverseExpression(infix, reversed);
    infixToPostfix(reversed, postfix, 1);
    reverseExpression(postfix, result);
    strcpy(prefix, result);
}

void combine(const char left[], char operator, const char right[], char result[])
{
    snprintf(result, MAX_EXPRESSION, "%s%c%s", left, operator, right);
}

void prefixToPostfix(const char prefix[], char postfix[])
{
    StringStack stack = {.top = -1};
    char left[MAX_EXPRESSION], right[MAX_EXPRESSION], result[MAX_EXPRESSION];
    for (int i = (int)strlen(prefix) - 1; i >= 0; i--)
    {
        if (isalnum((unsigned char)prefix[i]))
        {
            char operand[2] = {prefix[i], '\0'};
            push(&stack, operand);
        }
        else if (isOperator(prefix[i]))
        {
            pop(&stack, left);
            pop(&stack, right);
            combine(left, prefix[i], right, result);
            push(&stack, result);
        }
    }
    pop(&stack, postfix);
}

void prefixToInfix(const char prefix[], char infix[])
{
    StringStack stack = {.top = -1};
    char left[MAX_EXPRESSION], right[MAX_EXPRESSION], result[MAX_EXPRESSION];
    for (int i = (int)strlen(prefix) - 1; i >= 0; i--)
    {
        if (isalnum((unsigned char)prefix[i]))
        {
            char operand[2] = {prefix[i], '\0'};
            push(&stack, operand);
        }
        else if (isOperator(prefix[i]))
        {
            pop(&stack, left);
            pop(&stack, right);
            snprintf(result, MAX_EXPRESSION, "(%s%c%s)", left, prefix[i], right);
            push(&stack, result);
        }
    }
    pop(&stack, infix);
}

void postfixToInfix(const char postfix[], char infix[])
{
    StringStack stack = {.top = -1};
    char left[MAX_EXPRESSION], right[MAX_EXPRESSION], result[MAX_EXPRESSION];
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum((unsigned char)postfix[i]))
        {
            char operand[2] = {postfix[i], '\0'};
            push(&stack, operand);
        }
        else if (isOperator(postfix[i]))
        {
            pop(&stack, right);
            pop(&stack, left);
            snprintf(result, MAX_EXPRESSION, "(%s%c%s)", left, postfix[i], right);
            push(&stack, result);
        }
    }
    pop(&stack, infix);
}

void postfixToPrefix(const char postfix[], char prefix[])
{
    StringStack stack = {.top = -1};
    char left[MAX_EXPRESSION], right[MAX_EXPRESSION], result[MAX_EXPRESSION];
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum((unsigned char)postfix[i]))
        {
            char operand[2] = {postfix[i], '\0'};
            push(&stack, operand);
        }
        else if (isOperator(postfix[i]))
        {
            pop(&stack, right);
            pop(&stack, left);
            snprintf(result, MAX_EXPRESSION, "%c%s%s", postfix[i], left, right);
            push(&stack, result);
        }
    }
    pop(&stack, prefix);
}

void removeSpaces(char expression[])
{
    int write = 0;
    for (int read = 0; expression[read] != '\0'; read++)
    {
        if (!isspace((unsigned char)expression[read]))
            expression[write++] = expression[read];
    }
    expression[write] = '\0';
}

int main(void)
{
    int choice;
    char expression[MAX_EXPRESSION];
    char result[MAX_EXPRESSION];

    do
    {
        printf("\n--- Expression Conversion ---\n");
        printf("1. Infix to Postfix\n");
        printf("2. Infix to Prefix\n");
        printf("3. Prefix to Postfix\n");
        printf("4. Prefix to Infix\n");
        printf("5. Postfix to Infix\n");
        printf("6. Postfix to Prefix\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 6)
        {
            printf("Enter expression (single-character operands): ");
            scanf(" %199[^\n]", expression);
            removeSpaces(expression);
        }

        switch (choice)
        {
        case 1:
            infixToPostfix(expression, result, 0);
            printf("Postfix: %s\n", result);
            break;
        case 2:
            infixToPrefix(expression, result);
            printf("Prefix: %s\n", result);
            break;
        case 3:
            prefixToPostfix(expression, result);
            printf("Postfix: %s\n", result);
            break;
        case 4:
            prefixToInfix(expression, result);
            printf("Infix: %s\n", result);
            break;
        case 5:
            postfixToInfix(expression, result);
            printf("Infix: %s\n", result);
            break;
        case 6:
            postfixToPrefix(expression, result);
            printf("Prefix: %s\n", result);
            break;
        case 7:
            printf("Exiting.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 7);

    return 0;
}
