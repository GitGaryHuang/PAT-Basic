/*
1054 求平均值 （20 分）
本题的基本要求非常简单：给定 N 个实数，计算它们的平均值。但复杂的是有些输入数据可能是非法的。一个“合法”的输入是 [−1000,1000] 区间内的实数，并且最多精确到小数点后 2 位。当你计算平均值的时候，不能把那些非法的数据算在内。

输入格式：

输入第一行给出正整数 N（≤100）。随后一行给出 N 个实数，数字间以一个空格分隔。

输出格式：

对每个非法输入，在一行中输出 ERROR: X is not a legal number，其中 X 是输入。最后在一行中输出结果：The average of K numbers is Y，其中 K 是合法输入的个数，Y 是它们的平均值，精确到小数点后 2 位。如果平均值无法计算，则用 Undefined 替换 Y。如果 K 为 1，则输出 The average of 1 number is Y。

输入样例 1：
*/
//先判断是否是数字：第一位为负号或数字、其他位有非小数点和数字外负号、小数点个数大于1、类似-0等数、小数点与负号相邻-.
//**************************123.为正确数字 这点要额外注意（最后一个测试点参考https://blog.csdn.net/bawangtu/article/details/81331054）

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int IsNumber(char temp[100], int length);//检查是否为精度最多到小数点后2位的数字
//double ctod(char temp[100], int length);//字符串转浮点数 已由stdlib.h库中的atof函数代替。
void Error(char temp[100], int length);//输出错误

int main()
{
	int n;
	char c;
	double sum = 0;
	int count = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		char temp[100] = { '0' };
		int j = 0;
		while ((c = getchar()) != ' ' && c != '\n')
		{
			temp[j] = c;
			j++;
		}
		if (IsNumber(temp, j) == 1)
		{
			double p = 0;
			//p = ctod(temp, j);
			p = atof(temp);
			if (p <= 1000 && p >= -1000)
			{
				count++;
				sum += p;
			}
			else
				Error(temp, j);
		}
		else
			Error(temp, j);
	}

	if (count == 0)
		printf("The average of 0 numbers is Undefined");
	else if(count == 1)
		printf("The average of 1 number is %.2f", sum);
	else 
		printf("The average of %d numbers is %.2f", count, sum / count);

	return 0;


}

int IsNumber(char temp[100], int length)
{
	int countdot = 0;
	int dot = -1;
	if(temp[0] != '-' && (temp[0] < '0' || temp[0] > '9'))//第一位是负号或数字 否则不是数字
		return -1;


	for (int i = 0; i < length; i++)
	{
		if (temp[i] == '.')
		{
			countdot++;
			dot = i;
		}
		else if ((temp[i] == '-' && i == 0) || (temp[i] >= '0' && temp[i] <= '9'))//有除标点和数字外其他字符，不是数字
			continue;
		else
			return -1;
	}

	if(temp[0] == '-')
	{
		int count0 = 0;
		for(int i = 1; i < length; i++)
			if(temp[i] == '0')
				count0++;

		if(length == count0 + countdot + 1)
			return -1;
	}

	if (countdot > 1 || (temp[0] == '-' && temp[1] == '.')  || (countdot == 1 &&  (length - dot) > 3))//多于1个点或点在符号右边或精度问题
		return -1;
	else
		return 1;
}

void Error(char temp[100], int length)
{
	printf("ERROR: ");
	for (int i = 0; i < length; i++)
		printf("%c", temp[i]);
	printf(" is not a legal number\n");
}

/*由atof函数代替
double ctod(char temp[100], int length)
{
	double sum = 0;
	int dot = 0;
	int flag = 1;
	for (int i = 0; i < length; i++)
		if (temp[i] == '.')
		{
			dot = i;
			break;
		}
	if (temp[0] == '-')
		flag = -1;
	if (dot == 0)
	{
		for (int i = 0; i < length; i++)
			if (temp[i] >= '0' && temp[i] <= '9')
				sum = sum * 10 + temp[i] - 48;
	}
	else if (dot != 0)
	{
		double little = 0;
		for (int i = 0; i < dot; i++)
			if (temp[i] >= '0' && temp[i] <= '9')
				sum = sum * 10 + temp[i] - 48;
		for (int i = length - 1; i > dot; i--)
			if (temp[i] >= '0' && temp[i] <= '9')
				little = little / 10 + temp[i] - 48;
		sum = sum + little / 10;
	}

	if (flag == 1)
		return sum;
	else return -sum;



}
*/