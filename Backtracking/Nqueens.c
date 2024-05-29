#include <stdio.h>
#include <stdbool.h>

int n;
void print(char arr[][n])
{

    printf("\n Possible Solution is :  \n ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(char board[n][n], int row, int col)
{
    int i = row, j = col;

    // check col;

    for (int j = col; j >= 0; i--)
    {
        if (board[row][j--] == 'Q')
            return false;
    }
    i = row, j = col;
    // check upper left diagonal

    while (i >= 0 && j >= 0)
    {
        if (board[i--][j--] == 'Q')
            return false;
    }

    // check lower diagonal

    i = row, j = col;

    while (i <n && j >=0)
    {
        if (board[i][j] == 'Q')
            return false;

        i++;
        j--;
    }

    return true;
}

void solve(char board[n][n], int col, int n)
{
    if (col >= n)
    {
        print(board);
        return;
    }

    for (int row= 0; row < n; row++)
    {
        if (isSafe(board, row, col) == true)
        {
            board[row][col] = 'Q';
            solve(board, col + 1, n);
            board[row][col] = '-'; // backtrack
        }
    }
}
int main()
{

    printf("Enter the Number of elements :");
    scanf("%d", &n);
    char board[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '-';
        }
    }

    solve(board, 0, n );

    return 0;
}