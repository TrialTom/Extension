#define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

void IntoBoard(char board[ROWS][COLS], int rows, int cols, char ch)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		
		printf("%-2d", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%-2d", i);
		for (j = 1; j <= col; j++)
		{
			printf("%-2c", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
		
	}
	
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void extension(char mine[ ROWS ][COLS], int row, int col)
{

}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while (win < row*col - EASY_COUNT)
	{
		printf("请输入坐标：>\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("游戏结束！！\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				 count = get_mine_count(mine, x, y);
				show[x][y] = count +'0';
				extension(mine,row,col);
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("输入非法，请重新输入！！\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("恭喜你排雷成功！！/n");
	}
}