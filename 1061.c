/*
1061 判断题 （15 分）
判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。

输入格式：

输入在第一行给出两个不超过 100 的正整数 N 和 M，分别是学生人数和判断题数量。第二行给出 M 个不超过 5 的正整数，是每道题的满分值。第三行给出每道题对应的正确答案，0 代表“非”，1 代表“是”。随后 N 行，每行给出一个学生的解答。数字间均以空格分隔。

输出格式：

按照输入的顺序输出每个学生的得分，每个分数占一行。
*/
//无难点。
#include<stdio.h>
#include<string.h>

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int a[M][2];//保存分数和答案
	int grade[100] = {0};

	for(int i = 0; i < M; i++)
		scanf("%d", &a[i][0]);
	for(int i = 0; i < M; i++)
		scanf("%d", &a[i][1]);

	for(int i = 0; i < N; i++)
	{
		int temp;
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &temp);
			if(temp == a[j][1])
				grade[i] += a[j][0];
			else 
				continue;
		}
	}
	for(int i = 0; i < N; i++)
		printf("%d\n", grade[i]);

	return 0;
}