/*
1060 爱丁顿数 （25 分）
英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。

现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 E（≤N）。

输入格式：

输入第一行给出一个正整数 N (≤10
​5
​​ )，即连续骑车的天数；第二行给出 N 个非负整数，代表每天的骑车距离。

输出格式：

在一行中给出 N 天的爱丁顿数。
*/
//难点在于思路而非代码。
#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b);

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//将每天骑行的里程数升序排列，
	qsort(a, n, sizeof(int), cmp);

	int count = 1;
	int i = n - 1;
	//从最后往前找，每找一次count+1，即找到某天count >= a[i]时，则有count - 1天骑行超过count - 1距离。，
	while(count < a[i])
	{
		count++;
		i--;
	}

	printf("%d", --count);

	return 0;

}