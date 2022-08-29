#include "date.h"

//1582年10月4日之后直接跳到10，中间被忽略了十天
int Judge(int year, int mother, int day)
{
	
	if (year < 1582)
	{
		printf("不在查找范围内！！请重新输入····\n");
		return 0;
	}
	else
	{
		if (mother > 12|| mother < 0)
		{
			printf("输入的月份有误，请重新输入！！！\n");
			if (day < 0 && day >31)
			{
				printf("输入的日有误，请重新输入！！！\n");
			}
			return 0;
		}
		else
		{
			if (day < 0 && day >31)
			{
				printf("输入的日有误，请重新输入！！！\n");
				return 0;
			}
		}
	}
	return;
}

int Statistical(int year, int mother, int day)
{
	int sum = 0;
	int i = 0;
	int Big = 0;
	int Small = 0;
	int Spe = 0;
	//计算闰年
	if (year >= 1990)
	{
		for (i = 1990; i < year; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
			{
				sum++;
			}
		}
		for (i = 1; i <= mother; i++)
		{
			if (i == 2 || i == 4 || i == 6 || i == 8 || i == 9 || i == 11)
				Big++;
			else if (i == 5 || i == 7 || i == 10 || i == 12)
				Small++;
			else if (i > 2)
				Spe++;
		}
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			return sum * 366 + (year - 1990-sum) * 365  + Spe * 28 + Big * 31 + Small * 30;
		}
		else
		{
			return sum * 366 + (year - 1990 -sum) * 365  + Spe * 27 + Big * 31 + Small * 30;
		}
		
	}
}
void Print(int ret, int year, int mother,int day)
{
	int week = (ret +1) % 7 ;
	int line = 0;
	int i = 0;
	int M = 0;
	if (mother == 1 || mother == 3 || mother == 5 || mother == 7 || mother == 8 || mother == 10 || mother == 12)
	{
		M = 31;
	}
	else if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) && mother == 2)
	{
		M = 28;
	}
	else if (mother == 2)
	{
		M = 27;
	}
	else
	{
		M = 30;
	}
	printf("星期一\t星期二\t星期三\t星期四\t星期五\t星期六\t星期天\n");
		for (i = 0; i < week; i++)
		{
			printf("   \t");
		}
	for (line = 1; line <= M;line++)
	{
		printf("%-3d\t", line);
		if ((i + line)%7 == 0)
			printf("\n");
	}
	
}
void Result(int year, int mother, int day)
{
	//1990.1.1是星期一
	//统计输入日期到这一天的差值
	int ret = Statistical(year,mother,day);
	//printf("%d\n", ret);
	
	//实现输出到stdout
	Print(ret,year,mother,day);

}