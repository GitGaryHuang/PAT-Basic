/*
1035 插入与归并 （25 分）
根据维基百科的定义：

插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。

归并排序进行如下迭代操作：首先将原始序列看成 N 个只包含 1 个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下 1 个有序的序列。

现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？

输入格式：

输入在第一行给出正整数 N (≤100)；随后一行给出原始序列的 N 个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：

首先在第 1 行中输出Insertion Sort表示插入排序、或Merge Sort表示归并排序；然后在第 2 行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行首尾不得有多余空格。
*/
#include<stdio.h>
#include<stdlib.h>//用到qsort函数

int cmp(const void *a, const void *b);//用于qsort比较的函数
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;//升序
}

int main()
{
	int n;
	int A[100000], B[100000];
	scanf("%d", &n);//输入
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &B[i]);
	int i, j, k;

	//判断
	for(i = 0; B[i] <= B[i + 1] && i < n - 1; i++)//这里的等号缺失会导致测试用例4发生段错误
		;
	for(j = i + 1; A[j] == B[j] && j < n; j++)
		;
	if(j == n)//由于前i+1个数是升序，后面的数未动，所以是插入排序
	{
		printf("Insertion Sort\n");
		qsort(A, i + 2, sizeof(A[0]), cmp);
		for(int i = 0; i < n; i++)
		{
			printf("%d", A[i]);
			if(i != n - 1)
				printf(" ");
		}

	}
	else//不是插入排序，即是归并排序。
	{
		printf("Merge Sort\n");
		k = 2;
		int flag = 1;
		while(flag == 1)//找到相应的归并时间点。(循环内只判断 不输出 否则会导致错误。)
		{
			int m;
			for(m = 0; m + k < n; m += k)
			{
				qsort(A + m, k, sizeof(A[0]), cmp);
			}
			qsort(A + m, n - m, sizeof(A[0]), cmp);

			for(i = 0; A[i] == B[i] && i < n; i++)
				;
			if(i == n)
				flag = 0;
			k *= 2;
		}
		//进行下一次归并排序。
		if(k > n)
			qsort(A, n, sizeof(A[0]), cmp);
		else
		{
			int m;
			for(m = 0; m + k < n; m += k)
			{
				qsort(A + m, k, sizeof(A[0]), cmp);
			}
			qsort(A + m, n - m, sizeof(A[0]), cmp);
		}
		//输出
		for(int i = 0; i < n; i++)
		{		
			printf("%d", A[i]);
			if(i != n - 1)
				printf(" ");
		}

	}
}

