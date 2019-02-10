/*
1014 福尔摩斯的约会 （20 分）
大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：

在一行中输出约会的时间，格式为 DAY HH:MM，其中 DAY 是某星期的 3 字符缩写，即 MON 表示星期一，TUE 表示星期二，WED 表示星期三，THU 表示星期四，FRI 表示星期五，SAT 表示星期六，SUN 表示星期日。题目输入保证每个测试存在唯一解。
*/
#include<stdio.h>
#include <string.h>

int main()
{
	char A1[100], A2[100], B1[100], B2[100];
	int temp = 0;
	char Day;
	int Hour, Minute;
	gets(A1);
	gets(A2);
	gets(B1);
	gets(B2);
	int m, n;
	//m、n保存两对数组的分别最小长度，用来控制比较时的长度。
	m = strlen(A1) > strlen(A2) ? strlen(A2) : strlen(A1);
	n = strlen(B1) > strlen(B2) ? strlen(B2) : strlen(B1);

	for(int i = 0; i < m; i++)
		if(A1[i] == A2[i] && A1[i] >= 'A' && A1[i] <= 'G')
		{
			Day = A1[i];
			temp = i;
			break;
		}
	
	for(int i = temp + 1; i < m; i++)
		if(A1[i] == A2[i] && ((A1[i] >= '0' && A1[i] <='9') || (A1[i] >= 'A' && A1[i] <= 'N')))
		{
			Hour = A1[i];
			break;
		}

	for(int i = 0; i < n; i++)
		if(B1[i] == B2[i] && ((B1[i] >= 'a' && B1[i] <= 'z') || (B1[i] >= 'A' && B1[i] <= 'Z')))
		{
			Minute = i;
			break;
		}
	//输出日期
	if(Day == 'A')
		printf("MON ");
	else if(Day == 'B')
		printf("TUE ");
	else if(Day == 'C')
		printf("WED ");
	else if(Day == 'D')
		printf("THU ");
	else if(Day == 'E')
		printf("FRI ");
	else if(Day == 'F')
		printf("SAT ");
	else if(Day == 'G')
		printf("SUN ");
	if(Hour >= '0' && Hour <= '9')
		printf("%02d:", Hour - 48);
	else
		printf("%d:", Hour - 55);
	printf("%02d", Minute);

	return 0;

}