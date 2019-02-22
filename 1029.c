/*
1029 旧键盘 （20 分）
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：

输入在 2 行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过 80 个字符的串，由字母 A-Z（包括大、小写）、数字 0-9、以及下划线 _（代表空格）组成。题目保证 2 个字符串均非空。

输出格式：

按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有 1 个坏键。
*/
//无难点 
#include<stdio.h>
#include<string.h>

int main()
{
	char a[100];
	char b[100];
	gets(a);
	gets(b);
	int na = strlen(a);
	int nb = strlen(b);
	int aflag[100] = {0};//对第一组字符串中出现的字符进行标记。
 	int bi[100] = {0};//统计第二组字符串中的字符 对应下标0-9：0-9 A-Z：10-35 a-z：36-61 _：62
 	char result[100];//保存结果
 	int count = 0;
	for(int i = 0; i < nb; i++)
	{
		if(b[i] >= '0' && b[i] <= '9')
			bi[b[i] - 48]++;
		if(b[i] >= 'A' && b[i] <= 'Z')
			bi[b[i] - 55]++;
		if(b[i] >= 'a' && b[i] <= 'z')
			bi[b[i] - 87]++;
		if(b[i] == '_')
			bi[36]++;
	}
	//printf("_:%d\n", bi[36]);

	for(int i = 0; i < na; i++)
	{
		if(a[i] >= '0' && a[i] <= '9' && aflag[a[i] - 48] == 0)
		{
			aflag[a[i] - 48]++;
			result[count++] = a[i];
		}
		if(a[i] >= 'A' && a[i] <= 'Z' && aflag[a[i] - 55] == 0)
		{
			aflag[a[i] -55]++;
			result[count++] = a[i];
		}
		if(a[i] >= 'a' && a[i] <= 'z' && aflag[a[i] - 87] == 0)
		{
			aflag[a[i] - 87]++;
			result[count++] = a[i];
		}
		if(a[i] == '_' && aflag[36] == 0)
		{
			aflag[36]++;
			result[count++] = a[i];
		}
	}

	//printf("_:%d\n", aflag[36]);

	for(int i = 0; i < count; i++)
	{
		if(result[i] >= '0' && result[i] <= '9' && bi[result[i] - 48] == 0)
		{
			printf("%c", result[i]);
		}
		if(result[i] >= 'A' && result[i] <= 'Z' && bi[result[i] - 55] == 0)
		{
			printf("%c", result[i]);
		}
		if(result[i] >= 'a' && result[i] <= 'z' && bi[result[i] - 87] == 0)
		{
			printf("%c", result[i] - 32);
		}
		if(result[i] == '_' && bi[36] == 0)
		{
			printf("_");
		}
	}



}