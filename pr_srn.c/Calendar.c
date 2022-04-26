#include<stdio.h>
#include<stdlib.h>


int days_months[] = { 0,31,28,31,30,31,30,31,30,31,31,30,31 };


const char* months[] = {
	" ",
	"\n\nJanuary",
	"\n\nFerbruary",
	"\n\nMarch",
	"\n\nApril",
	"\n\nMay",
	"\n\nJune",
	"\n\nJuly",
	"\n\nAugusut",
	"\n\nSeptember",
	"\n\nOctomber",
	"\n\nNovember",
	"\n\nDecember",
};
int Enter()
{
	int year;
	printf("Enter year : ");
	scanf_s("%d", &year);
	return year;
}

int found(int year)
{
	int days;
	int d1, d2, d3;
	d1 = (year - 1) / 4;
	d2 = (year - 1) / 100;
	d3 = (year - 1) / 400;
	days = (year + d1 - d2 + d3) % 7;
	return days;
}

int Ddays(int year)
{
	if (year % 4 == false && year % 100 != false || year % 400 == false)
	{
		days_months[2] = 29;
		return true;
	}
	else
	{
		days_months[2] = 28;
		return false;
	}

}
void calendar(int year, int Ddays)
{
	int month, day;
	for (month = 1; month <= 12; month++)
	{
		printf(" %s ", months[month]);

		printf("\n\n Sum Man Tue Wed Tue Fri Sat\n");
		for (day = 1; day <=1+ Ddays * 5; day++)
		{
			printf(" ");
		}

		for (day = 1; day < days_months[month] ; day++)
		{
			printf("%2d", day);
			if ((day + Ddays) % 7 > 0)
				printf(" ");
			else
				printf("\n ");
		}

		Ddays = (Ddays + days_months[month]) % 7;
	}
}

int main(void)
{
	int month;
	int year;
	year = Enter();
	month=found(year);
	Ddays(month);
	calendar(year, month);
	printf("\n");

}
