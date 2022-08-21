#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}


void AddContact(struct Contact* ps)
{
	if (ps->size == Max)
	{
		printf("ͨѶ¼����������");
		return;
	}
	else
	{
		printf("������������>\n");
		scanf("%s", ps->data[ps->size].name);		
		printf("���������䣺>\n");
		scanf("%d", &(ps->data[ps->size].age));
		printf("�������Ա�>\n");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��>\n");
		scanf("%s", ps->data[ps->size].tale);
		printf("�������ַ��>\n");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
	}
}


void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("������ӣ���\n");
		return;
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-4s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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

void DelContact(struct Contact* ps)
{
	char Name[NAME_MAX];
	printf("������Ҫɾ����������>");
	scanf("%s", Name);
	//1.����Ҫɾ����
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
		printf("��Ҫɾ������Ϣ�����ڣ���\n");
		return;
	}
	//2.ɾ����
	for (i; i < ps->size -1; i++)
	{
		ps->data[i] = ps->data[i + 1];
	}
	ps->size--;
	printf("ɾ���ɹ���!\n");
}


void SearchContact(const struct Contact* ps)
{
	char Name[NAME_MAX] = { 0 };
	int i = 0;
	printf("��������������˵�������>");
	scanf("%s", Name);
	//for (i = 0; i < ps->size; i++)
	//{
	//	if (0 == strcmp(ps->data[i].name, need))
	//	{
	//		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-4s\n", "����", "����", "�Ա�", "�绰", "��ַ");

	//		printf("%-20s\t%-4d\t%-5s\t%-13s\t%-4s\n",
	//			ps->data[i].name,
	//			ps->data[i].age,
	//			ps->data[i].sex,
	//			ps->data[i].tale,
	//			ps->data[i].addr);
	//		return;
	//	}
	//��DelContact����Ĳ����ַ��������Ƶģ�����ModifyContactҲ��Ҫ���ң����Կɽ�����
	//���ܳ��������������װ��һ������FindName()
	//}
	i = FindName(Name, ps);
	if(i == -1)
		printf("������ҵ��˲���ͨѶ¼�У�����\n");
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-4s\n", "����", "����", "�Ա�", "�绰", "��ַ");

		printf("%-20s\t%-4d\t%-5s\t%-13s\t%-4s\n",
					ps->data[i].name,
					ps->data[i].age,
					ps->data[i].sex,
					ps->data[i].tale,
					ps->data[i].addr);
				return;
	}

}

static int FindName(char Name[],const struct Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, Name))
			return i;
	}
	return -1;
}

void ModifyContact(struct Contact* ps)
{
	char Name[NAME_MAX];
	printf("������Ҫ�޸��˵�������>");
	scanf("%s", Name);
	int i = FindName(Name, ps);
	if (i == -1)
		printf("Ҫ�޸��˵���Ϣ�����ڣ���!\n");
	else
	{
		printf("������������>\n");
		scanf("%s", ps->data[i].name);
		printf("���������䣺>\n");
		scanf("%d", &(ps->data[i].age));
		printf("�������Ա�>\n");
		scanf("%s", ps->data[i].sex);
		printf("������绰��>\n");
		scanf("%s", ps->data[i].tale);
		printf("�������ַ��>\n");
		scanf("%s", ps->data[i].addr);

		printf("�޸���ɣ���\n");
	}
}