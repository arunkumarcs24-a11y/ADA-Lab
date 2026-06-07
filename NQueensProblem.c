#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int N;

int isSafe(int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return 0;
    }

    i = row;
    j = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j])
            return 0;

        i--;
        j--;
    }

    i = row;
    j = col;

    while (i < N && j >= 0)
    {
        if (board[i][j])
            return 0;

        i++;
        j--;
    }

    return 1;
}

int solve(int col)
{
    int i;

    if (col >= N)
        return 1;

    for (i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            if (solve(col + 1))
                return 1;

            board[i][col] = 0;
        }
    }

    return 0;
}

void printBoard()
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (board[i][j])
                printf("Q ");
            else
                printf(". ");
        }

        printf("\n");
    }
}

int main()
{
    printf("Enter value of N: ");
    scanf("%d", &N);

    if (solve(0))
    {
        printf("Solution Exists:\n");
        printBoard();
    }
    else
    {
        printf("No Solution Exists");
    }

    return 0;
}
