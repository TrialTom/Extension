#include "date.h"


int main()
{
	int year = 1992;
	int mother = 1;
	int day = 1;
	printf("�������꣺\n");
	scanf("%d", &year);
	printf("�������£�\n");
	scanf("%d", &mother);
	printf("�������գ�\n");
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