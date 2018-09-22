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

using Point = pair<int, int>;

class SpiralMatrix
{
  private:
    int cur_val_ = 0;
    int col_, row_;
    vector<vector<int>> maze_;

    bool IsBlocked(int x, int y)
    {
        return x < 0 || x >= col_ || y < 0 || y >= row_ || EMPTY != maze_[y][x];
    }

    Point MoveNext(int cur_x, int cur_y, int cur_dir)
    {
        switch (cur_dir)
        {
        case RIGHT:
            cur_x++;
            break;
        case DOWN:
            cur_y++;
            break;
        case LEFT:
            cur_x--;
            break;
        case UP:
            cur_y--;
            break;
        }
        return {cur_x, cur_y};
    }

  public:
    SpiralMatrix(int col, int row, const vector<pair<int, int>> &obstacle) : maze_(row, vector<int>(col, EMPTY)),
                                                                             col_(col), row_(row)
    {
        for (const auto &[x, y] : obstacle)
        {
            maze_[y][x] = OBS;
        }
    }

    void Traverse(int cur_x, int cur_y, int cur_dir)
    {
        while (true)
        {
            int i;
            for (i = 0; i < MAXTRY; i++)
            {
                int next_x, next_y;
                tie(next_x, next_y) = MoveNext(cur_x, cur_y, cur_dir);
                if (IsBlocked(next_x, next_y))
                {
                    cur_dir = (cur_dir + 1) % MAXDIR;
                }
                else
                {
                    cur_x = next_x;
                    cur_y = next_y;
                    maze_[cur_y][cur_x] = ++cur_val_;
                    break;
                }
            } /*for*/

            if (i == MAXDIR)
                break;
        } /*while*/
    }

    friend ostream &operator<<(ostream &os, const SpiralMatrix &smat);
};

ostream &operator<<(ostream &os, const SpiralMatrix &s)
{
    for (int y = 0; y < s.row_; y++)
    {
        for (int x = 0; x < s.col_; x++)
        {
            int val = s.maze_[y][x];
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
    return os;
}

int main()
{
    int row, col;
    int obs_num;

    cin >> col >> row;
    cin >> obs_num;

    vector<Point> obstacle;

    for (int i = 0; i < obs_num; i++)
    {
        int x, y;
        cin >> x >> y;

        obstacle.emplace_back(x, y);
    }

    SpiralMatrix smat(col, row, obstacle);

    cout << smat;
    smat.Traverse(-1, 0, RIGHT);
    cout << smat;

    return 0;
}
