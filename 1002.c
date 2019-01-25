/*
1002 写出这个数 （20 分）
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：

每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10
​100
​​ 。

输出格式：

在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
*/


#include<stdio.h>
#include<string.h>

int main()
{
	char num[1000];//num字符串保存大数值 
	int sum = 0;//sum计算该值各位之和
	int temp = 0;//temp保存num[i]的整数值
	gets(num);
	int length = strlen(num);//length保存num长度
	int result[1000];//保存
	int i = 0;//

	for(int i = 0; i < length; i++)
		{
			temp = (int)num[i] - 48;
			sum += temp;
		}

	if(sum == 0)
	{
	  printf("ling");
	  return 0;
	}
	  

	while(sum != 0)
	{
		temp = sum % 10;
		result[i++] = sum % 10;
		sum /= 10;
	}
	i--;

	for(int index = i; index >=0; index--)
		{
			if(index != i)
				printf(" ");
			if(result[index] == 1)
				printf("yi");
			else if(result[index] == 2)
				printf("er");
			else if(result[index] == 3)
				printf("san");
			else if(result[index] == 4)
				printf("si");
			else if(result[index] == 5)
				printf("wu");
			else if(result[index] == 6)
				printf("liu");
			else if(result[index] == 7)
				printf("qi");
			else if(result[index] == 8)
				printf("ba");
			else if(result[index] == 9)
				printf("jiu");
			else if(result[index] == 0)
				printf("ling");
		}

	return 0;
}