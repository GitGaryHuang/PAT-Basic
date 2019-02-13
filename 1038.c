/*
1038 统计同成绩学生 （20 分）
本题要求读入 N 名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：

输入在第 1 行给出不超过 10
​5
​​  的正整数 N，即学生总人数。随后一行给出 N 名学生的百分制整数成绩，中间以空格分隔。最后一行给出要查询的分数个数 K（不超过 N 的正整数），随后是 K 个分数，中间以空格分隔。

输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
*/
//使用了memset函数对数组进行初始化，以成绩为下标，将人数保存到对应成绩的数组中，可以少开空间及减少循环次数。其他无难点。
#include<stdio.h>
#include<string.h>

int main()
{
	int grade[101000];//grade保存各成绩人数
	memset(grade, 0, sizeof(grade));//初始化数组
	int n;//总共需要录入的成绩数
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		grade[temp]++;
	}


	int m;//需要查询的成绩数
	int tgrade[101000];
	scanf("%d", &m);
	for(int i = 0; i < m; i++)
	{
		scanf("%d", &tgrade[i]);
		//printf("%d%c", grade[tgrade[i]], i == m - 1 ? '\n' : ' ');
	}
	for(int i = 0; i < m; i++)
		printf("%d%c", grade[tgrade[i]], i == m - 1 ? '\n' : ' ');


}