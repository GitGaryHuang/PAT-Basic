/*
1033 旧键盘打字 （20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

输入格式：

输入在 2 行中分别给出坏掉的那些键、以及应该输入的文字。其中对应英文字母的坏键以大写给出；每段文字是不超过 10
​5
​​  个字符的串。可用的字符包括字母 [a-z, A-Z]、数字 0-9、以及下划线 _（代表空格）、,、.、-、+（代表上档键）。题目保证第 2 行输入的文字串非空。

注意：如果上档键坏掉了，那么大写的英文字母无法被打出。

输出格式：

在一行中输出能够被打出的结果文字。如果没有一个字符能被打出，则输出空行。
*/
//无难点
#include<stdio.h>
#include<string.h>

int main()
{
	char a[100];
	char b[100050];

	gets(a);
	gets(b);
	
	int na = strlen(a);
	int nb = strlen(b);
	int flag = 0;
	int count = 0;

	for(int i = 0; i < na; i++)
	{
		if(a[i] == '+')
		{
			flag = 1;
			continue;
		}
		else if(a[i] >= 'A' && a[i] <= 'Z')
			for(int j = 0; j < nb; j++)
			{
				if(b[j] == a[i] || b[j] == a[i] + 32)//坏键用*替换
				{
					b[j] = '*';
					count++;
				}
				else 
					continue;
			}
		else if(a[i] == ',' || a[i] == '.' || a[i] == '-' || a[i] == '_' || (a[i] >= '0' && a[i] <= '9'))
			for(int j = 0; j < nb; j++)
			{
				if(b[j] == a[i])
				{
					b[j] = '*';
					count++;
				}
				else
					continue;
			}
	}
	if(flag == 1)
		for(int i = 0; i < nb; i++)
			if(b[i] >= 'A' && b[i] <= 'Z' )
			{
				b[i] = '*';
				count++;
			}
	if(count == nb)
		printf("\n");
	else
		for(int i = 0; i < nb; i++)
			if(b[i] != '*')
				printf("%c", b[i]);

	return 0;
}