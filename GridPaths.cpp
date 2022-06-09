#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdbool>
#include <cassert>
using namespace std;
char s[49];
int res = 0;
bool available(int r, int c)
{
    if (r >= 0 && r < 7 && c >= 0 && c < 7)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void getpaths(bool grid[7][7], char s[49], int r, int c, int index, int direc) // direction 1 up 2 right 3 down 4 left
{
    if (r < 0 || r >= 7 || c < 0 || c >= 7 || index > 48)
    {
        return;
    }

    if (grid[r][c])
    {
        //grid [r][c] = false;??????R??????U??????????????????????????LD????D?
        //                    ????????????????????????????????????????????????
        return;
    }
    grid[r][c] = true;
    if (r == 6 && c == 0 && index == 48)
    {
        res++;
        grid[r][c] = false;
        //for (int i=0;i<7;i++) {for (int j=0;j<7;j++) printf("%d", grid[i][j]);}
        return;
    }
    if (r == 6 && c == 0 && index != 48)
    {
        grid[r][c] = false;
        return;
    }
    if (direc == 1 && (!available(r - 1, c) || grid[r - 1][c]) && available(r, c + 1) && available(r, c - 1) && !grid[r][c - 1] && !grid[r][c + 1])
    {
        grid[r][c] = false;
        return;
    }
    if (direc == 2 && (!available(r, c + 1) || grid[r][c + 1]) && available(r - 1, c) && available(r + 1, c) && !grid[r - 1][c] && !grid[r + 1][c])
    {
        grid[r][c] = false;
        return;
    }
    if (direc == 3 && (!available(r + 1, c) || grid[r + 1][c]) && available(r, c - 1) && available(r, c + 1) && !grid[r][c - 1] && !grid[r][c + 1])
    {
        grid[r][c] = false;
        return;
    }
    if (direc == 4 && (!available(r, c - 1) || grid[r][c - 1]) && available(r + 1, c) && !grid[r + 1][c] && available(r - 1, c) && !grid[r - 1][c])
    {
        grid[r][c] = false;
        return;
    }

    if (s[index] == '?')
    {
        getpaths(grid, s, r + 1, c, index + 1, 3);
        getpaths(grid, s, r - 1, c, index + 1, 1);
        getpaths(grid, s, r, c + 1, index + 1, 2);
        getpaths(grid, s, r, c - 1, index + 1, 4);
    }
    if (s[index] == 'R')
    {
        getpaths(grid, s, r, c + 1, index + 1, 2);
    }
    if (s[index] == 'L')
    {
        getpaths(grid, s, r, c - 1, index + 1, 4);
    }
    if (s[index] == 'U')
    {
        getpaths(grid, s, r - 1, c, index + 1, 1);
    }
    if (s[index] == 'D')
    {
        getpaths(grid, s, r + 1, c, index + 1, 3);
    }
    grid[r][c] = false;
}
int main()
{
    scanf("%s", s);
    //printf("%d\n", available(3, 2));
    assert(strlen(s) == 48);
    bool grids[7][7] = {0};
    getpaths(grids, s, 0, 0, 0, 2);

    printf("%d\n", res);
}