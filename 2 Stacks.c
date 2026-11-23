#include<stdio.h>
#define MAX 20

    int Stack[MAX];
    int Top1= -1;
    int Top2 = MAX-1;

    void push1(int x)
    {
        if(Top1 + 1 == Top2)
        {
            printf("Overflow");
            return;
        }
        Stack[++Top1] = x;
    }

    void push2(int x)
    {
        if(Top1+1 == Top2)
        {
            printf("Overflow");
            return;
        }
        Stack[--Top2] = x;
    }

    void Pop1()
    {
        if(Top1 == -1)
        {
            printf("Underflow!");
            return;
        }
        printf("Popped: %d\n", Stack[Top1--]);
    }

    void Pop2()
    {
        if(Top2 == MAX-1)
        {
            printf("Underflow!");
            return;
        }
        printf("Popped: %d\n", Stack[Top2++]);
    }

    int main()
    {
        push1(10);
        push1(20);

        push2(80);
        push2(90);

        Pop1();
        Pop2();
    }