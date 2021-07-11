#include <stdio.h>
#include <stdbool.h>

struct element {
    int num;        // 1~9: valid, 0: don't have value yet
    bool can_modify;       // true: white area in the figure, false: gray area in the figure
};

void solve(struct element (*grid_p)[9]);
void print_grid(struct element (*grid_p)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%d ", grid_p[i][j].num);
        }
        printf("\n");
    }
}

int main(void) {
    struct element grid[9][9];
    char ch;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf(" %c", &ch);
            if (ch == '.') {    // can_modify assign true, num assign 0
                grid[i][j].num = 0;
                grid[i][j].can_modify = true;
            }
            else {      // value gotten from input, so we can't change this
                grid[i][j].num = ch - '0';
                grid[i][j].can_modify = false;
            }
        }
    }
    solve(grid);
    print_grid(grid);
    return 0;
}
// Your code goes here
int is_row_col_repeat(int x, int y, int z, struct element (*grid_p)[9]) {
    for (int i=0;i<9;i++)
        if (grid_p[x][i].num==z || grid_p[i][y].num==z)
            return 1;
    
    return 0;
}

int is_block_repeat(int x, int y, int z, struct element (*grid_p)[9]) {
    int sx=(x/3)*3, sy=(y/3)*3;

    for (int i=sx;i<sx+3;i++)
        for (int j=sy;j<sy+3;j++)
            if (z==grid_p[i][j].num)
                return 1;

    return 0;
}

int dfs(int x, int y, struct element (*grid_p)[9]) {
    if (x>8) return 1;
    
    if (!grid_p[x][y].num) {
        for (int i=1;i<=9;i++) {
            if (!is_block_repeat(x, y, i, grid_p) && !is_row_col_repeat(x, y, i, grid_p)) {
                grid_p[x][y].num=i;
                
                 if (dfs(x+(y+1)/9, (y<8 ? y+1 : 0), grid_p))
                    return 1; 

                grid_p[x][y].num=0;
            }
        }
    }
    
    if (grid_p[x][y].num && dfs(x+(y+1)/9, (y<8 ? y+1 : 0), grid_p))
        return 1;
    
    return 0; 
}

void solve(struct element (*grid_p)[9]) {
    dfs(0, 0, grid_p);
}