// PairProgramming.cpp : Defines the entry point for the console application.
//

#if defined(_MSC_VER)
#include "stdafx.h"
#endif

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define EMPTY -1
#define OBS -2
#define MAXDIR 4

enum
{
    RIGHT = 0,
    DOWN,
    LEFT,
    UP
};

int cur_val = 0;
void traverse(vector<vector<int>> &maze, int cur_x, int cur_y, int cur_dir, int try_num)
{
    int row = maze.size();
    int col = maze[0].size();

    if(MAXDIR <= try_num) return;

    int next_x = cur_x, next_y = cur_y;
    switch (cur_dir)
    {
    case RIGHT:
        next_x++;
        break;
    case DOWN:
        next_y++;
        break;
    case LEFT:
        next_x--;
        break;
    case UP:
        next_y--;
        break;
    }

    if (
        next_x < 0 || next_x >= col ||
        next_y < 0 || next_y >= row ||
        maze[next_y][next_x] != EMPTY)
    {
 
        traverse(maze, cur_x, cur_y, (cur_dir + 1) % MAXDIR, try_num+1);
    
    }
    else
    {
        maze[next_y][next_x] = cur_val++;
        traverse(maze, next_x, next_y, cur_dir,0);
    }
}

int main()
{
    int row, col;
    int obs_num;

    cin >> col >> row;

    vector<vector<int>> maze(row, vector<int>(col, EMPTY));

    cin >> obs_num;

    int x, y;
    for (int i = 0; i < obs_num; i++)
    {
        cin >> x >> y;

        maze[y][x] = OBS;
    }

    traverse(maze, -1, 0, RIGHT,0);

    for (int y = 0; y < row; y++)
    {
        for (int x = 0; x < col; x++)
        {
            int val = maze[y][x];
            if (val == EMPTY)
            {
                cout << "\t"
                     << "-";
            }
            else if (val == OBS)
            {
                cout << "\t"
                     << "x";
            }
            else
            {
                cout << "\t" << val;
            }
        }
        cout << "\n";
    }

    return 0;
}
