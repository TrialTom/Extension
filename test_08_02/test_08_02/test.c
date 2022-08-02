#define _CRT_SECURE_NO_WARNINGS 

#include "game.h"

void menu()
{
	printf("************************\n");
	printf("******  1.play  ********\n");
	printf("******  0.exit  ********\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };

	char show[ROWS][COLS] = { 0 };

	IntoBoard(mine, ROWS, COLS,'0');
	IntoBoard(show, ROWS, COLS,'*');

	//打印效果图
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	FindMine(mine,show,ROW,COL);

}
void test()
{
	srand((unsigned int)time(NULL));
	int	input = 0;
	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误，重新选择！！");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}