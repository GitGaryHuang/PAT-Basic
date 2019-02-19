/*
1019 数字黑洞 （20 分）
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。
输入格式：

输入给出一个 (0,10
​4
​​ ) 区间内的正整数 N。

输出格式：

如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。注意每个数字按 4 位数格式输出。
*/
//无难点，解题思路：给入数字对其进行升序和降序排序，并相减，while循环控制直到出现6174；
#include<stdio.h>
#include<stdlib.h>

int cmpDown(const void *a, const void *b);
int Up(int number);
int Down(int number);

int main()
{
	int number;
	scanf("%d", &number);
	if(number / 1000 == number % 1000 / 100 && number / 1000 == number % 10 && number / 1000 == number % 100 / 10)
	{
		printf("%04d - %04d = 0000", number, number);
		return 0;
	}
	int result = 0;
	while(result != 6174)
	{
		int big = Up(number);
		int small = Down(number);
		result = big - small;
		printf("%04d - %04d = %04d\n", big, small, result);
		number = result;
	}

	return 0;	
}

int cmpDown(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int Up(int number)
{
	int temp[4] = {0};
	int result = 0;
	temp[0] = number / 1000;
	temp[1] = number % 1000 / 100;
	temp[2] = number % 100 / 10;
	temp[3] = number % 10;

	qsort(temp, 4, sizeof(int), cmpDown);

	result = temp[3] * 1000 + temp[2] * 100 + temp[1] * 10 + temp[0];

	return result;
}
int Down(int number)
{
	int temp[4] = {0};
	int result = 0;
	temp[0] = number / 1000;
	temp[1] = number % 1000 / 100;
	temp[2] = number % 100 / 10;
	temp[3] = number % 10;

	qsort(temp, 4, sizeof(int), cmpDown);

	result = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];

	return result;
}
