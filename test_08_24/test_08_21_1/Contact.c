#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void InitContact(struct Contact* ps)
{
	//memset(ps->data, 0, sizeof(ps->data));

	//ps->size = 0;

	ps->data = (struct PeoInfo*)malloc(SIZE * sizeof(struct PeoInfo));
	ps->size = 0;
	ps->capacity = SIZE;
}

void CheckCapacity(struct Contact* ps)
{
	struct PeoInfo* ptr = (struct PeoInfo *)realloc(ps->data, 2 * sizeof(struct PeoInfo)
		+ ps->capacity * sizeof(struct PeoInfo));
	if (ptr != NULL)
	{

		printf("增容成功！！\n");
		ps->data = ptr;
		free(ptr);
		ptr = NULL;
	}
	else
	{
		printf("%s\n", strerror(errno));
		assert(ptr);
	}
}

void AddContact(struct Contact* ps)
{
	//if (ps->size == MAX)
	//{
	//	printf("通讯录已满！！！");
	//	return;
	//}
	//else
	//{
	//	printf("请输入姓名：>\n");
	//	scanf("%s", ps->data[ps->size].name);		
	//	printf("请输入年龄：>\n");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	printf("请输入性别：>\n");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("请输入电话：>\n");
	//	scanf("%s", ps->data[ps->size].tale);
	//	printf("请输入地址：>\n");
	//	scanf("%s", ps->data[ps->size].addr);
	//	ps->size++;
	//}

	//检测当前通讯录的容量
	//1.若满了，增加容量
	// 2.若没满，跳过
	//
	if (ps->capacity <= ps->size)
	{
		CheckCapacity(ps);
	}
	

	//增加数据
	printf("请输入姓名：>\n");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄：>\n");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别：>\n");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入电话：>\n");
	scanf("%s", ps->data[ps->size].tale);
	printf("请输入地址：>\n");
	scanf("%s", ps->data[ps->size].addr);
	ps->size++;
	printf("增加成功！！\n");
}



void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("请先添加！！\n");
		return;
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-4s\n", "姓名", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-13s\t%-4s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tale,
				ps->data[i].addr);
		}
	}
}

static int FindName(char Name[], const struct Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, Name))
			return i;
	}
	return -1;
}

void DelContact(struct Contact* ps)
{
	char Name[NAME_MAX];
	printf("请输入要删除的姓名：>");
	scanf("%s", Name);
	//1.查找要删除的
	//int i = 0;
	//for (i = 0; i < ps->size; i++)
	//{
	//	if (0 == strcmp(ps->data[i].name, name))
	//	{
	//		break;
	//	}
	//}
	int i = FindName(Name, ps);
	if (i == -1)
	{
		printf("需要删除的信息不存在！！\n");
		return;
	}
	//2.删除；
	for (i; i < ps->size -1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
	printf("删除成功！!\n");
}


void SearchContact(const struct Contact* ps)
{
	char Name[NAME_MAX] = { 0 };
	int i = 0;
	printf("请输入所需查找人的姓名：>");
	scanf("%s", Name);
	//for (i = 0; i < ps->size; i++)
	//{
	//	if (0 == strcmp(ps->data[i].name, need))
	//	{
	//		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-4s\n", "姓名", "年龄", "性别", "电话", "地址");

	//		printf("%-20s\t%-4d\t%-5s\t%-13s\t%-4s\n",
	//			ps->data[i].name,
	//			ps->data[i].age,
	//			ps->data[i].sex,
	//			ps->data[i].tale,
	//			ps->data[i].addr);
	//		return;
	//	}
	//与DelContact所需的查找字符串是相似的，并且ModifyContact也需要查找，所以可将查找
	//功能抽离出来，单独封装成一个函数FindName()
	//}
	i = FindName(Name, ps);
	if(i == -1)
		printf("所需查找的人不在通讯录中！！！\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-4s\n", "姓名", "年龄", "性别", "电话", "地址");

		printf("%-20s\t%-4d\t%-5s\t%-13s\t%-4s\n",
					ps->data[i].name,
					ps->data[i].age,
					ps->data[i].sex,
					ps->data[i].tale,
					ps->data[i].addr);
				return;
	}

}

void ModifyContact(struct Contact* ps)
{
	char Name[NAME_MAX];
	printf("请输入要修改人的姓名：>");
	scanf("%s", Name);
	int i = FindName(Name, ps);
	if (i == -1)
		printf("要修改人的信息不存在！！!\n");
	else
	{
		printf("请输入姓名：>\n");
		scanf("%s", ps->data[i].name);
		printf("请输入年龄：>\n");
		scanf("%d", &(ps->data[i].age));
		printf("请输入性别：>\n");
		scanf("%s", ps->data[i].sex);
		printf("请输入电话：>\n");
		scanf("%s", ps->data[i].tale);
		printf("请输入地址：>\n");
		scanf("%s", ps->data[i].addr);

		printf("修改完成！！\n");
	}
}

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}