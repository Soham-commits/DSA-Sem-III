#include<stdio.h>

void AcceptMatrix(int m, int n, int MatA[m][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &MatA[i][j]);
        }
    }
}

void PrintMatrix(int m, int n, int MatA[m][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t", MatA[i][j]);
        }
        printf("\n");
    }
}

void SubstractionMatrix(int m, int n, int MatA[m][n], int MatB[m][n], int MatC[m][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            MatC[i][j] = MatA[i][j] - MatB[i][j];
        }
    }
}


int main()
{
    int m = 0, n = 0;
    printf("Enter the Matrix row count: ");
    scanf("%d", &m);

    printf("Enter the Matrix column count: ");
    scanf("%d", &n);

    int MatA[m][n];
    int MatB[m][n];
    int MatC[m][n];

    printf("Enter first matrix elements:\n");
    AcceptMatrix(m, n, MatA);

    printf("Enter second matrix elements:\n");
    AcceptMatrix(m, n, MatB);

    SubstractionMatrix(n,m,MatA,MatB,MatC);

    printf("The Substraction of Matrix Elements are:\n");
    PrintMatrix(m, n, MatC);


    return 0;
}