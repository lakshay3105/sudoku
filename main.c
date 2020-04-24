#include <stdio.h>
#define n 9
int a[9][9];
//function to print sudoku
void print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("________________________\n");
        }
        if(i==3||i==6)
            printf("|-------|-------|-------|\n");
        for(j=0;j<n;j++)
        {
            if(j==0||j==3||j==6)
                printf("| ");
            printf("%d ",a[i][j]);
            if(j==8)
                printf("|");
        }
        printf("\n");
        if(i==8)
            printf("_________________________\n");
    }
}

//function to check if all cells are assigned or not
//if there is any unassigned cell
//then this function will change the values of
//row and col accordingly
int check_empty(int *row, int *col)
{
    int num = 0;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            //cell is empty
            if(a[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                num = 1;
                return num;
            }
        }
    }
    return num;
}

//function to check if the number can be placed
int is_safe(int q, int r, int c)
{
    int i,j;
    //checking in row
    for(i=0;i<n;i++)
    {
        //there is a cell with same value
        if(a[r][i] == q)
            return 0;
    }
    //checking column
    for(i=0;i<n;i++)
    {
        //there is a cell with the value equal to i
        if(a[i][c] == q)
            return 0;
    }
    //checking sub matrix
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(a[i][j]==q)
                return 0;
        }
    }
    return 1;
}

//function to solve sudoku
//using backtracking
int solve()
{
    int r;
    int c;
    //check whether their is any empty or 0 initialized place
    if(check_empty(&r, &c) == 0)
    {
        return 1;
    }
    int i;
    for(i=1;i<=n;i++)
    {
        //check whether the number can be placed
        if(is_safe(i, r, c))
        {
            a[r][c] = i;
            //backtracking
            if(solve())
            {
                return 1;
            }
            //if it fails then we again set the initial value
            a[r][c]=0;
        }
    }
    return 0;
}

int main()
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    if (solve())
        print();
    else
        printf("No solution\n");
    return 0;
}
