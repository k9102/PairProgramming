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
#define MAXTRY 4

enum
{
    RIGHT = 0,
    DOWN,
    LEFT,
    UP,
    MAXDIR
};

class SpiralMatrix
{
  private:
    int cur_val_ = 0;
    int col_, row_;
    vector<vector<int>> maze_;

  public:
    SpiralMatrix(int col, int row, const vector<pair<int, int>> &obstacle) : maze_(row, vector<int>(col, EMPTY)),
                                                                             col_(col), row_(row)
    {
        for (auto [x, y] : obstacle)
        {
            maze_[y][x] = OBS;
        }
    }
    void Print()
    {
        for (int y = 0; y < row_; y++)
        {
            for (int x = 0; x < col_; x++)
            {
                int val = maze_[y][x];
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
    }
    void Traverse(int cur_x, int cur_y, int cur_dir, int trial_num)
    {
        if (MAXTRY <= trial_num)
            return;

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
            next_x < 0 || next_x >= col_ ||
            next_y < 0 || next_y >= row_ ||
            maze_[next_y][next_x] != EMPTY)
        {

            Traverse(cur_x, cur_y, (cur_dir + 1) % MAXDIR, trial_num + 1);
        }
        else
        {
            maze_[next_y][next_x] = cur_val_++;
            Traverse(next_x, next_y, cur_dir, 0);
        }
    }
};

int main()
{
    int row, col;
    int obs_num;
    vector<pair<int, int>> obstacle;

    cin >> col >> row;
    cin >> obs_num;

    int x, y;
    for (int i = 0; i < obs_num; i++)
    {
        cin >> x >> y;

        obstacle.emplace_back(x, y);
    }

    SpiralMatrix smat(col, row, obstacle);
    smat.Print();
    smat.Traverse(-1, 0, RIGHT, 0);

    smat.Print();

    return 0;
}
