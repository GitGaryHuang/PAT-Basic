/*
1050 螺旋矩阵 （25 分）
本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：

输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10
​4
​​ ，相邻数字以空格分隔。

输出格式：

输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。
*/
//先以sqrt(N)为界，求出m n， 输入整数并降序排序，然后进行螺旋保存。参考https://blog.csdn.net/qq_34677945/article/details/78638411
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int N;
	scanf("%d", &N);
	getchar();
	int number[100] = {0};//number用于保存输入的整数

	//确定m n
	int min[10000][3];
	int count = 0;//计数器
	int m, n;
	int sqrtn = (int)sqrt(N);
	for(int i = 1; i <= sqrtn; i++)
	{
		if(N % i == 0)
		{
			min[count][0] = N / i;
			min[count][1] = i;
			min[count][2] = min[count][0] - min[count][1];
			count++;
		}
	}
	for(int i = 0, minn = min[0][2]; i < count; i++)
	{
		if(min[i][2] <= minn)
		{
			minn = min[i][2];
			m = min[i][0];
			n = min[i][1];
		}
	}

	//输入整数存于number数组中并对其进行排序
	for(int i = 0; i < N; i++)
		scanf("%d", &number[i]);
	qsort(number, N, sizeof(number[0]), cmp);

	//开m * n大小的二维数组并初始化。
	int square[m][n];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			square[i][j] = 0;

	//计数并螺旋保存数值
	count = 0;
	int i = 0, j = 0;
	while(count < N)
	{
		while(square[i][j] == 0 && j < n)//向右
			square[i][j++] = number[count++];
		j--;//补偿
		i++;//调整位置
		while(square[i][j] == 0 && i <m)//向下
			square[i++][j] = number[count++];
		i--;//补偿
		j--;//调整位置
		while(square[i][j] == 0 && j >= 0)//向左
			square[i][j--] = number[count++];
		j++;//补偿
		i--;//调整位置
		while(square[i][j] == 0 && i >= 0)//向上
			square[i--][j] = number[count++];
		i++;//补偿
		j++;//调整位置
	}

	//输出
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			printf("%d%c", square[i][j], j == n - 1 ? '\n' : ' ');

	return 0;
}