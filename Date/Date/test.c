#include "date.h"


int main()
{
	int year = 1992;
	int mother = 1;
	int day = 1;
	printf("请输入年：\n");
	scanf("%d", &year);
	printf("请输入月：\n");
	scanf("%d", &mother);
	printf("请输入日：\n");
	scanf("%d", &day);
	int jude = Judge(year, mother, day);
	if (jude == 0)
	{
		system("pause");
		return 0;
	}
	Result(year,mother,day);
	return 0;
}