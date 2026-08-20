#include <stdio.h>
#include <stdbool.h>

void intake(int m, int n, int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_matrix(int m, int n, int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

int num_non_zero(int m, int n, int arr[m][n])
{
    int k = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                k++;
            }
        }
    }

    return k;
}

bool is_sparse(int m, int n, int k)
{
    if (k <= (m * n) / 2)
    {
        return true;
    }

    return false;
}

void compact(int m, int n, int arr[m][n], int k, int res[k + 1][3])
{
    res[0][0] = m;
    res[0][1] = n;
    res[0][2] = k;

    int idx = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                res[idx][0] = i;
                res[idx][1] = j;
                res[idx][2] = arr[i][j];
                idx++;
            }
        }
    }
}

void print_compact(int k, int arr[k + 1][3])
{
    for (int i = 0; i <= k; i++)
    {
        printf("%d\t%d\t%d\n",
               arr[i][0],
               arr[i][1],
               arr[i][2]);
    }
}

void simple_transpose(int k, int arr[k + 1][3], int result[k + 1][3])
{
    result[0][0] = arr[0][1];
    result[0][1] = arr[0][0];
    result[0][2] = arr[0][2];

    int id = 1;

    for (int col = 0; col < arr[0][1]; col++)
    {
        for (int i = 1; i <= k; i++)
        {
            if (arr[i][1] == col)
            {
                result[id][0] = arr[i][1];
                result[id][1] = arr[i][0];
                result[id][2] = arr[i][2];
                id++;
            }
        }
    }
}

void fast_transpose(int k, int arr[k + 1][3], int result[k + 1][3])
{
    result[0][0] = arr[0][1];
    result[0][1] = arr[0][0];
    result[0][2] = arr[0][2];

    int s[arr[0][1]];
    int t[arr[0][1]];

    for (int i = 0; i < arr[0][1]; i++)
    {
        s[i] = 0;
    }

    for (int i = 1; i <= k; i++)
    {
        s[arr[i][1]]++;
    }

    t[0] = 1;

    for (int i = 1; i < arr[0][1]; i++)
    {
        t[i] = t[i - 1] + s[i - 1];
    }

    for (int i = 1; i <= k; i++)
    {
        int pos = t[arr[i][1]];

        result[pos][0] = arr[i][1];
        result[pos][1] = arr[i][0];
        result[pos][2] = arr[i][2];

        t[arr[i][1]]++;
    }
}

int main()
{
    int m, n;

    printf("Enter the matrix size (rows columns): ");
    scanf("%d %d", &m, &n);

    int arr[m][n];

    printf("\nEnter the matrix elements:\n");
    intake(m, n, arr);

    printf("\nOriginal Matrix:\n");
    print_matrix(m, n, arr);

    printf("\nChoose the transpose method:\n");
    printf("1. Simple Transpose\n");
    printf("2. Fast Transpose\n");
    printf("Enter your choice: ");

    int ch;
    scanf("%d", &ch);

    int k = num_non_zero(m, n, arr);

    if (is_sparse(m, n, k))
    {
        int compact_mat[k + 1][3];
        int result[k + 1][3];

        compact(m, n, arr, k, compact_mat);

        switch (ch)
        {
            case 1:
                simple_transpose(k, compact_mat, result);
                printf("\nSimple Transpose:\n");
                print_compact(k, result);
                break;

            case 2:
                fast_transpose(k, compact_mat, result);
                printf("\nFast Transpose:\n");
                print_compact(k, result);
                break;

            default:
                printf("\nInvalid choice.\n");
        }
    }
    else
    {
        printf("\nThe given matrix is not a sparse matrix.\n");
    }

    return 0;
}