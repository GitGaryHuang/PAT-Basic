
/*
1004 成绩排名 （20 分）
读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：

每个测试输入包含 1 个测试用例，格式为

第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
  ... ... ...
第 n+1 行：第 n 个学生的姓名 学号 成绩
其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：

对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。
*/
#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char name[1000][20];
	char id[1000][20];
	int grade[1000];
	int max = -1;
	int min = -1;
	int maxmark = -1;
	int minmark = 101;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++)
	{
		scanf("%s %s %d", name[i], id[i], &grade[i]);
		if(maxmark < grade[i])
		{
			maxmark = grade[i];
			max = i;
		}
		if(minmark > grade[i])
		{
			minmark = grade[i];
			min = i;
		}
	}

	printf("%s %s\n%s %s\n", name[max], id[max], name[min], id[min]);

}