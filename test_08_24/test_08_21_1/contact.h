#define _CRT_SECURE_NO_WARNINGS
// #define Max 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TALE_MAX 12
#define ADDR_MAX 30
#define SIZE 3

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tale[TALE_MAX];
	char addr[ADDR_MAX];
};

struct Contact
{
	struct PeoInfo* data;
	int size;//��¼��ǰ���е�Ԫ�ظ���
	int capacity;//��ǰͨѶ¼���������
};
//��ʼ��
void InitContact(struct Contact* ps);
//��ɾ���
void AddContact(struct Contact* ps);

void ShowContact(const struct Contact* ps);

void DelContact(struct Contact* ps);

void SearchContact(const struct Contact* ps);
//�޸�
void ModifyContact(struct Contact* ps);

void DestroyContact(struct Contact* ps);