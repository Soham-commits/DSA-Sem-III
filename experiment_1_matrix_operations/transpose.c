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

void Transpose(int m, int n, int MatA[m][n], int MatB[n][m])
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            MatB[j][i] = MatA[i][j];
        }
    }
}

int main()
{
    int m, n;

    printf("Enter the Matrix row count: ");
    scanf("%d", &m);

    printf("Enter the Matrix column count: ");
    scanf("%d", &n);

    int MatA[m][n];
    int MatB[n][m];

    printf("Enter The matrix elements:\n");
    AcceptMatrix(m, n, MatA);

    Transpose(m, n, MatA, MatB);

    printf("The Transpose Matrix Elements are:\n");
    PrintMatrix(n, m, MatB);

    return 0;
}
