/*
1042 字符统计 （20 分）
请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：

输入在一行中给出一个长度不超过 1000 的字符串。字符串由 ASCII 码表中任意可见字符及空格组成，至少包含 1 个英文字母，以回车结束（回车不算在内）。

输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
*/
//无难点
#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char s[1005];
	gets(s);
	n = strlen(s);
	int a[26] = {0};
	int max = 0;
	int index = 0;
	for(int i = 0; i < n; i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			a[s[i] - 97]++;
		else if(s[i] >= 'A' && s[i] <= 'Z')
			a[s[i] - 65]++;

	for(int i = 25; i >= 0; i--)
		if(a[i] >= max)
		{
			max = a[i];
			index = i;
		}

	printf("%c %d", index + 97, max);
}
