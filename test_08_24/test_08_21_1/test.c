#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contact.h"

void menu()
{
	printf("*******************************************************\n");
	printf("**************1,add       2.del        ****************\n");
	printf("**************3.search    4.modify     ****************\n");
	printf("**************5,show      6.sort       ****************\n");
	printf("**************0.exit                   ****************\n");
	printf("*******************************************************\n");
}
int main()
{
	int input = 0;
	struct Contact con;//con����ͨѶ¼������dataָ�룬size��capacity
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			system("cls");
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
			//����
		case SORT:
			break;
		case EXIT:
			//����ͨѶ¼
			//�ͷŶ�̬�ڴ棻
			DestroyContact(&con);
			
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	printf("�˳�����\n");
	return 0;
}