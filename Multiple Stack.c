#include<stdio.h>
#define MAX 12
#define N 3

int Stack[MAX];
int Top[N];
int Boundary[N+1];

void Initialize()
{
    for(int i=0; i<N; i++)
    {
        Boundary[i] = (MAX/N) * i -1;
        Top[i] = Boundary[i];
    }
    Boundary[N] = MAX - 1;
}

void Push(int i, int x)
{
    if(Top[i] == Boundary[i+1])
    {
        printf("Stack %d Overflow\n", i);
        return;
    }
    Stack[++Top[i]] = x;
}

void Pop(int i)
{
    if(Top[i] == Boundary[i])
    {
        printf("Stack %d Underflow\n", i);
        return;
    }
    printf("Popped from Stack %d: %d\n",i, Stack[Top[i]--]);

}

int main() {
    Initialize();

    Push(0, 10);
    Push(0, 20);

    Push(1, 30);
    Push(1, 40);

    Push(2, 50);
    Push(2, 60);

    Pop(0);
    Pop(1);
    Pop(2);

    return 0;
}
