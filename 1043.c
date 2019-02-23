/*
1043 输出PATest （20 分）
给定一个长度不超过 10
​4
​​  的、仅由英文字母构成的字符串。请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过 10
​4
​​  的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。
*/
//无难点但要注意方法。
#include<stdio.h>
#include<string.h>

int main()
{
	char s[10005];
	char result[6] = {'P', 'A', 'T', 'e', 's', 't'};
	gets(s);
	int n;
	n = strlen(s);
	int a[128] = {0};
	//将PATest按顺序统计于数组a中
	for(int i = 0; i < n; i++)
		a[s[i]]++;

	while(a[80] != 0 || a[65] != 0 || a[84] != 0 || a[101] != 0 || a[115] != 0 || a[116] != 0)
	{
		for(int i = 0; i <= 5; i++)
			if(a[result[i]] > 0)
			{
				printf("%c", result[i]);
				a[result[i]]--;
			}
	}

	return 0;

}