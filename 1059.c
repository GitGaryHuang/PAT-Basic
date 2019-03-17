/*
1059 C语言竞赛 （20 分）
C 语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

0、冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
1、排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
2、其他人将得到巧克力。
给定比赛的最终排名以及一系列参赛者的 ID，你要给出这些参赛者应该获得的奖品。

输入格式：

输入第一行给出一个正整数 N（≤10
​4
​​ ），是参赛者人数。随后 N 行给出最终排名，每行按排名顺序给出一位参赛者的 ID（4 位数字组成）。接下来给出一个正整数 K 以及 K 个需要查询的 ID。

输出格式：

对每个要查询的 ID，在一行中输出 ID: 奖品，其中奖品或者是 Mystery Award（神秘大奖）、或者是 Minion（小黄人）、或者是 Chocolate（巧克力）。如果所查 ID 根本不在排名里，打印 Are you kidding?（耍我呢？）。如果该 ID 已经查过了（即奖品已经领过了），打印 ID: Checked（不能多吃多占）。
*/
//无难点
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int IsPrime(int n);//素数判断

int main()
{
	int N, K;
	scanf("%d", &N);
	int grade[10050][2] = { 0 };//一维下标为ID 二维0存放奖项 1存放是否已领奖标记
	char reward[5][100] = { "Are you kidding?", "Mystery Award", "Minion", "Chocolate","Checked" };
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (i == 0)
			grade[temp][0] = 1;
		else if (IsPrime(i + 1) == 1)
			grade[temp][0] = 2;
		else
			grade[temp][0] = 3;
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (grade[temp][1] == 0 && grade[temp][0] != 0)
		{
			if (grade[temp][0] == 1)
				printf("%04d: %s\n", temp, reward[1]);
			else if (grade[temp][0] == 2)
				printf("%04d: %s\n", temp, reward[2]);
			else if (grade[temp][0] == 3)
				printf("%04d: %s\n", temp, reward[3]);
			else if(grade[temp][0] == 0)
				printf("%04d: %s\n", temp, reward[0]);
			grade[temp][1] = 1;
		}
		else if(grade[temp][0] == 0)
			printf("%04d: %s\n", temp, reward[0]);
		else 
			printf("%04d: %s\n", temp, reward[4]);

	}

	return 0;
}

int IsPrime(int n)
{
	if (n == 2)
		return 1;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return -1;

	return 1;
}