#include<stdio.h>
#include<string.h>

typedef struct people
{
	char name[10];
	int year;
	int month;
	int day;
}people;

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	struct people people[n];
	int count = 0;
	struct people max = {"", 1814, 9, 5};
	struct people min = {"", 2014, 9, 7};
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d/%d/%d", people[i].name, &people[i].year, &people[i].month, &people[i].day);
		count++;
		if(people[i].year < 1814 || (people[i].year == 1814 && people[i].month < 9) || ( people[i].year == 1814 && people[i].month == 9 && people[i].day < 6)|| people[i].year > 2014 || (people[i].year == 2014 && people[i].month > 9) || (people[i].year == 2014 && people[i].month == 9 && people[i].day > 6))
		{
			count--;
			continue;
		}
		if((people[i].year > max.year) || (people[i].year == max.year && people[i].month > max.month) || (people[i].year == max.year && people[i].month == max.month && people[i].day > max.day))
			max = people[i];
		if((people[i].year < min.year) || (people[i].year == min.year && people[i].month < min.month) || (people[i].year == min.year && people[i].month == min.month && people[i].day < min.day))
			min = people[i];
	}
	if(count == 0)
		printf("0");
	else 
		printf("%d %s %s", count, min.name, max.name);
}