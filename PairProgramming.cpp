// PairProgramming.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define EMPTY  -1
#define OBS  -2

enum { RIGHT=0,DOWN,LEFT,UP};

void traverse(int *maze, int row, int col)
{
	int cur_dir = RIGHT;
	int cur_x=-1, cur_y=0,cur_val = 0;

	while(true)
	{
		int i;
		for (i = 0; i < 4; i++)
		{
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

			if (next_x >= col || next_y >= row || maze[col*next_y + next_x]!=EMPTY)
			{
				cur_dir = (cur_dir + 1) % 4;
			}
			else
			{
				cur_x = next_x;
				cur_y = next_y;
				maze[col*cur_y + cur_x] = cur_val++;
				break;
			}
		} /*for*/

		if (i == 4)
			break;
	} /*while*/
}

int main()
{
	int row,col;
	int obs_num;
	int *maze;

	cin >> row >> col;

	maze = new int[row*col];
	for (int i = 0; i < row*col; i++)
		maze[i] = EMPTY;

	cin >> obs_num;

	int x, y;
	for (int i=0; i < obs_num; i++)
	{
		cin >> x >> y;
				
		maze[col*y + x] = OBS;
	}


	traverse(maze, row, col);

	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			int val = maze[col*y + x];
			if (val == EMPTY)
			{
				cout << "\t" << "-";
			}
			else if (val == OBS)
			{
				cout << "\t" << "x";
			}
			else {
				cout << "\t" << val;
			}
		}
		cout << "\n";
	}

	delete[] maze;

    return 0;
}

