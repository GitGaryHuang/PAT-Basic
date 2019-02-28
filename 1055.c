/*
1055 集体照 （25 分）
拍集体照时队形很重要，这里对给定的 N 个人 K 排的队形设计排队规则如下：

每排人数为 N/K（向下取整），多出来的人全部站在最后一排；

后排所有人的个子都不比前排任何人矮；

每排中最高者站中间（中间位置为 m/2+1，其中 m 为该排人数，除法向下取整）；

每排其他人以中间人为轴，按身高非增序，先右后左交替入队站在中间人的两侧（例如5人身高为190、188、186、175、170，则队形为175、188、190、186、170。这里假设你面对拍照者，所以你的左边是中间人的右边）；

若多人身高相同，则按名字的字典序升序排列。这里保证无重名。

现给定一组拍照人，请编写程序输出他们的队形。

输入格式：

每个输入包含 1 个测试用例。每个测试用例第 1 行给出两个正整数 N（≤10
​4
​​ ，总人数）和 K（≤10，总排数）。随后 N 行，每行给出一个人的名字（不包含空格、长度不超过 8 个英文字母）和身高（[30, 300] 区间内的整数）。

输出格式：

输出拍照的队形。即K排人名，其间以空格分隔，行末不得有多余空格。注意：假设你面对拍照者，后排的人输出在上方，前排输出在下方。
*/
//难点在于人物站位的实现，即将人物的排列顺序保存到数组中。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a, const void *b);

typedef struct Member
{
	char name[10];
	int height;
}Member;

int main()
{
	int N, K, m;
	scanf("%d %d", &N, &K);
	Member member[N];
	char name[N][15];
	//录入信息
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d", member[i].name, &member[i].height);
	}
	//排序
	qsort(member, N, sizeof(Member), cmp);
	m = N / K;
	//按要求将姓名存储到name数组中。
	for (int i = 0; i < K; i++)
	{
		if (i == K - 1)
		{
			strcpy(name[i * m + ((N % K) + m) / 2], member[N - 1].name);
			for (int j = 1; j <= ((N % K) + m) / 2; j++)
			{
				if (N - 2 * j >= i * m)
					strcpy(name[i * m + ((N % K) + m) / 2 - j], member[N - 2 * j].name);
				if (N - 1 - 2 * j >= i * m)
					strcpy(name[i * m + ((N % K) + m) / 2 + j], member[N - 1 - 2 * j].name);
			}
		}
		else
		{
			strcpy(name[i * m + m / 2], member[i * m + m - 1].name);
			for (int j = 1; j <= m / 2; j++)
			{
				if (i * m + m - 2 * j >= i * m)
					strcpy(name[i * m + m / 2 - j], member[i * m + m - 2 * j].name);
				if (i * m + m - 2 * j - 1 >= i * m)
					strcpy(name[i * m + m / 2 + j], member[i * m + m - 2 * j - 1].name);
			}
		}

	}
	//先输出第一行即最后一排，再输出余下行
	for (int i = (K - 1) * m; i < N; i++)
		printf("%s%c", name[i], i == N - 1 ? '\n' : ' ');
	for (int i = K - 2; i >= 0; i--)
		for (int j = 0; j < m; j++)
			printf("%s%c", name[i * m + j], j == m - 1 ? '\n' : ' ');

	return 0;

}

//结构体排序方法，先按身高后按字母
int cmp(const void *a, const void *b)
{
	struct Member *m1 = (Member *)a;
	struct Member *m2 = (Member *)b;
	if (m1->height != m2->height)
		return m1->height > m2->height ? 1 : -1;
	else
		return strcmp(m1->name, m2->name) < 0 ? 1 : -1;
}