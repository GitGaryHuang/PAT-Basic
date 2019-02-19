/*
1024 科学计数法 （20 分）
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：

每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指数的绝对值不超过 9999。

输出格式：

对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。
*/
//本题思路为：将科学计数法E进行格式化分解处理，第一个符号位判断正负号，第二个符号位判断小数点左移还是右移（可以考虑开数组来进行左移右移处理，但操作量较大），并根据相应规律输出小数点和0即可。
#include<stdio.h>
#include<string.h>

int ctoi(char word[100500]);//字符串转数字 用于将E后面的字符串改成数字
void printNumber(char head[100500], int last, int n, int flag1, int flag2);//输出结果

int main()
{
	char snumber[100500];//科学计数法记录的数字保存于数组
	gets(snumber);
	int wl = strlen(snumber);//科学计数法数组总厂
	int flag1 = 1;//E前符号标签
	int flag2 = 1;//E后符号标签
	char word[100500];
	char head[100500];//E前数字保存于数组
	int last;//E后数字保存为整形
	int n1 = 0;//E前字符串长度
	//对前后两个符号进行保存。
	if(snumber[0] == '-')
		flag1 = -1;
	for(int i = 1; i < wl; i++)
	{
		if(snumber[i] == 'E')
		{
			if(snumber[i + 1] == '-')
				flag2 = -1;
			n1 = i;
			break;
		}
		else 
			continue;
	}
	//数组保存E前的数字
	for(int i = 1, j = 0; i < n1; i++, j++)
	{
		if(snumber[i] == '.')
			j--;
		else
		{
			head[j] = snumber[i];
		}
		
	}
	//记录E后数字
	for(int i = n1 + 2, count = 0; i < strlen(snumber); i++, count++)
		word[count] = snumber[i];
	last = ctoi(word);

	printNumber(head, last, n1, flag1, flag2);
}

int ctoi(char word[10000])//字符串转数字
{
	int length = strlen(word);
	int result = 0;

	for(int i = 0; i < length; i++)
	{
		int temp = word[i] - 48;
		result = result * 10 + temp;
	}

	return result;
}

void printNumber(char head[100500], int last, int n, int flag1, int flag2)//输出结果
{
	int t = n - 3;//E前小数点后的位数

	//格式化输出
	if(flag1 == -1)//输出第一个符号位
		printf("-");
	if(flag2 == -1)
	{
		printf("0.");
		for(int i = 0; i < last - 1; i++)
			printf("0");
		for(int i = 0; i < strlen(head); i++)
			printf("%c", head[i]);
	}
	else if(flag2 == 1)
	{
		if(t <= last)
		{
			for(int i = 0; i < strlen(head); i++)
				printf("%c", head[i]);
			for(int i = 0; i < last - t; i++)
				printf("0");
		}
		else 
		{
			for(int i = 0; i < strlen(head); i++)
			{
				printf("%c", head[i]);
				if(i == last)
					printf(".");
			}
		}
	}

}