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

	//��ӡЧ��ͼ
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show, ROW, COL);

	//������
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
		printf("��ѡ��>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ���������ѡ�񣡣�");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}