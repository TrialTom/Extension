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
	struct Contact con;//con就是通讯录，包含data指针，size，capacity
	InitContact(&con);
	do
	{
		menu();
		printf("请选择：>");
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
			//排序
		case SORT:
			break;
		case EXIT:
			//销毁通讯录
			//释放动态内存；
			DestroyContact(&con);
			
			break;
		default:
			printf("选择错误，请重新选择：\n");
			break;
		}
	} while (input);
	printf("退出！！\n");
	return 0;
}