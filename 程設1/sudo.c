#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void)
{
    int grid[NUM][NUM]; // sudoku puzzle
    for (int i = 0; i < NUM; ++i)
    {
        for (int j = 0; j < NUM; ++j)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
void check_sudoku(int (*grid_p)[NUM])
{
    int check_row[9], check_col[9], check_cell[9], is_invalid[9][9] = {0};
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            check_row[i] = 0;
        }
        for (int k = 0; k < 9; k++)
        {
            check_row[grid_p[j][k] - 1]++;
        }
        for (int l = 0; l < 9; l++)
        {
            if (check_row[grid_p[j][l] - 1] >= 2)
            {
                for (int n = 0; n < 9; n++)
                {
                    if (grid_p[j][n] == grid_p[j][l])
                    {
                        is_invalid[j][n] = 1;
                    }
                }
            }
        }
    }
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            check_col[i] = 0;
        }
        for (int k = 0; k < 9; k++)
        {
            check_col[grid_p[k][j] - 1]++;
        }
        for (int l = 0; l < 9; l++)
        {
            if (check_col[grid_p[l][j] - 1] >= 2)
            {
                for (int n = 0; n < 9; n++)
                {
                    if (grid_p[n][j] == grid_p[l][j])
                    {
                        is_invalid[n][j] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int row = i / 3 * 3;
            int col = j / 3 * 3;
            for (int k = 0; k < 9; k++)
            {
                check_cell[k] = 0;
            }
            for (int l = 0; l < 3; l++)
            {
                for (int m = 0; m < 3; m++)
                {
                    check_cell[grid_p[row + l][col + m] - 1]++;
                }
            }
            for (int n = 0; n < 3; n++)
            {
                for (int q = 0; q < 3; q++)
                {
                    if (check_cell[grid_p[row + n][col + q] - 1] >= 2)
                    {
                        for (int o = 0; o < 3; o++)
                        {
                            for (int p = 0; p < 3; p++)
                            {
                                if (grid_p[row + o][col + p] == grid_p[row+n][col+q])
                                {
                                    is_invalid[row + o][col + p] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (is_invalid[i][j] == 1)
            {
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}

