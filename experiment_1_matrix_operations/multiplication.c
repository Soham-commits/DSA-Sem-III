#include <stdio.h>

void AcceptMatrix(int m, int n, int MatA[m][n])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
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

void MultiplicationMatrix(int r1, int c1, int c2,
                          int A[r1][c1],
                          int B[c1][c2],
                          int C[r1][c2])
{
    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int r1, c1, r2, c2;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if(c1 != r2)
    {
        printf("Multiplication not possible\n");
        return 0;
    }

    int MatA[r1][c1];
    int MatB[r2][c2];
    int MatC[r1][c2];

    printf("Enter first matrix elements:\n");
    AcceptMatrix(r1, c1, MatA);

    printf("Enter second matrix elements:\n");
    AcceptMatrix(r2, c2, MatB);

    MultiplicationMatrix(r1, c1, c2, MatA, MatB, MatC);

    printf("The Multiplication of Matrix Elements are:\n");
    PrintMatrix(r1, c2, MatC);

    return 0;
}
