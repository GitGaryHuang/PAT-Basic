/*
1032 挖掘机技术哪家强 （20 分）
为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：

输入在第 1 行给出不超过 10
​5
​​  的正整数 N，即参赛人数。随后 N 行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从 1 开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：

在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。
*/
//无难点
#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	int maxid = 0;
	int maxscore = 0;
	int resultid = 0;
	int result[100050];
	memset(result, 0, sizeof(result));
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		int id, mark;
		scanf("%d %d", &id, &mark);
		if(id > maxid)
			maxid = id;
		result[id] += mark;
	}
	for(int i = 1; i <= maxid; i++)
	{
		if(result[i] > maxscore)
		{
			resultid = i;
			maxscore = result[i];
		}
	}

	printf("%d %d", resultid, maxscore);

	return 0;

}