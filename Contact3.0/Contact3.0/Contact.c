#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = (struct PeoInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("success\n");

		}
		else
		{
			printf("fail\n");
		}
	}
}
void Loadcontact(struct Contact* ps)
{
	struct PeoInfo tem = { 0 };
	FILE* pfRead = fopen("E:\\CLass Work\\extension\\Contact3.0\\Contact3.0\\contact.dat", "rb");
	if (pfRead == NULL)
	{
		printf("%s\n", strerror(errno));
		return;

	}
	else 
	{
		while (fread(&(tem), sizeof(struct PeoInfo), 1, pfRead))
		{
			ps->data[ps->size] = tem;
			ps->size++;
		}
		fclose(pfRead);
		pfRead = NULL;
	}
}

void InitContact(struct Contact* ps)
{
	//memset(ps->data, 0, sizeof(ps->data));

	//ps->size = 0;

	ps->data = (struct PeoInfo*)malloc(SIZE * sizeof(struct PeoInfo));
	ps->size = 0;
	ps->capacity = SIZE;

	//���ļ����Ѿ������ͨѶ¼�е���Ϣ���ص�ͨѶ¼��
	Loadcontact(ps);
}


void AddContact(struct Contact* ps)
{
	//if (ps->size == MAX)
	//{
	//	printf("ͨѶ¼����������");
	//	return;
	//}
	//else
	//{
	//	printf("������������>\n");
	//	scanf("%s", ps->data[ps->size].name);		
	//	printf("���������䣺>\n");
	//	scanf("%d", &(ps->data[ps->size].age));
	//	printf("�������Ա�>\n");
	//	scanf("%s", ps->data[ps->size].sex);
	//	printf("������绰��>\n");
	//	scanf("%s", ps->data[ps->size].tale);
	//	printf("�������ַ��>\n");
	//	scanf("%s", ps->data[ps->size].addr);
	//	ps->size++;
	//}

	//��⵱ǰͨѶ¼������
	//1.�����ˣ���������
	// 2.��û��������
	//
	if (ps->capacity <= ps->size)
	{
		CheckCapacity(ps);
	}
	

	//��������
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
	printf("���ӳɹ�����\n");
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
void SaveContact(struct Contact* ps)
{
	FILE* pf = fopen("E:\\CLass Work\\extension\\Contact3.0\\Contact3.0\\contact.dat", "wb");
	if (pf == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]), sizeof(struct PeoInfo), 1, pf);
	}

	fclose(pf);
	pf = NULL;
}

void DestroyContact(struct Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

