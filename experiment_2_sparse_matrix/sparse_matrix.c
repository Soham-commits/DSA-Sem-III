#include <stdio.h>

#define MAX 100

void createSparse(int a[][10], int r, int c, int s[][3])
{
    int i, j, k = 1;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(a[i][j] != 0)
            {
                s[k][0] = i;
                s[k][1] = j;
                s[k][2] = a[i][j];
                k++;
            }
        }
    }

    s[0][0] = r;
    s[0][1] = c;
    s[0][2] = k - 1;
}

void displaySparse(int s[][3])
{
    int i;

    printf("\nRow Col Value\n");

    for(i = 0; i <= s[0][2]; i++)
    {
        printf("%d   %d   %d\n",
               s[i][0], s[i][1], s[i][2]);
    }
}

void fastTranspose(int s[][3], int t[][3])
{
    int rowTerms[10] = {0};
    int startingPos[10];
    int i, j, pos;
    int cols = s[0][1];
    int terms = s[0][2];

    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];

    if(terms == 0)
        return;

    for(i = 1; i <= terms; i++)
    {
        rowTerms[s[i][1]]++;
    }

    startingPos[0] = 1;

    for(i = 1; i < cols; i++)
    {
        startingPos[i] =
            startingPos[i - 1] + rowTerms[i - 1];
    }

    for(i = 1; i <= terms; i++)
    {
        j = s[i][1];

        pos = startingPos[j];

        t[pos][0] = s[i][1];
        t[pos][1] = s[i][0];
        t[pos][2] = s[i][2];

        startingPos[j]++;
    }
}

int main()
{
    int a[10][10];
    int s[MAX][3];
    int t[MAX][3];

    int r, c, i, j;
    int choice;
    int created = 0;
    int transposed = 0;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    do
    {
        printf("\n1. Create Compact Form");
        printf("\n2. Display Compact Form");
        printf("\n3. Fast Transpose");
        printf("\n4. Display Fast Transpose");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createSparse(a, r, c, s);
                created = 1;
                printf("Compact form created.\n");
                break;

            case 2:
                if(created)
                    displaySparse(s);
                else
                    printf("Create compact form first.\n");
                break;

            case 3:
                if(created)
                {
                    fastTranspose(s, t);
                    transposed = 1;
                    printf("Fast transpose completed.\n");
                }
                else
                {
                    printf("Create compact form first.\n");
                }
                break;

            case 4:
                if(transposed)
                    displaySparse(t);
                else
                    printf("Perform fast transpose first.\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 5);

    return 0;
}