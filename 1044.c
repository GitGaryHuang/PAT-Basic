/*
1044 火星数字 （20 分）
火星人是以 13 进制计数的：

地球人的 0 被火星人称为 tret。
地球人数字 1 到 12 的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
火星人将进位以后的 12 个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。
例如地球人的数字 29 翻译成火星文就是 hel mar；而火星文 elo nov 对应地球数字 115。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数 N（<100），随后 N 行，每行给出一个 [0, 169) 区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
*/

//暴力运作，无难点，运用到strstr函数（返回子串首字母在主串中的地址）、etom函数将
#include<stdio.h>
#include<string.h>

int ctoi(char word[10000]);//字符串转数字
char* etom(int i);//数字转火星语
int mtoe(char word[10000]);//火星语转数字

int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	char word[10000];
	int iresult;//保存读入字符串得到的数字
	char cresult[10000];
	int result;//火星文转化得到的数字

	for(int i = 0; i < n; i++)
	{
		iresult = 0;
		result = 0;
		strcpy(word, "");
		gets(word);
		if(word[0] >= '0' && word[0] <= '9')
		{
			iresult = ctoi(word);
			//printf("%d\n", iresult);
			strcpy(cresult,etom(iresult));
			printf("%s\n", cresult);
		}
		else
		{
			result = mtoe(word);
			printf("%d\n", result);
		}
	}
}

char* etom(int i)//数字转火星语
{
	static char result[10000];
	strcpy(result, "");
	int p = 0;
	int q = 0;
	p = i / 13;
	q = i % 13;
	if(p == 0 && q == 0)
	{
		strcpy(result, "tret");
		return result;
	}

	if(p == 1)
		strcpy(result, "tam");
	else if(p == 2) 
		strcpy(result, "hel");
	else if(p == 3)
		strcpy(result, "maa");
	else if(p == 4)
		strcpy(result, "huh");
	else if(p == 5)
		strcpy(result, "tou");
	else if(p == 6) 
		strcpy(result, "kes");
	else if(p == 7)
		strcpy(result, "hei");
	else if(p == 8)
		strcpy(result, "elo");
	else if(p == 9)
		strcpy(result, "syy");
	else if(p == 10) 
		strcpy(result, "lok");
	else if(p == 11)
		strcpy(result, "mer");
	else if(p == 12)
		strcpy(result, "jou");

	//printf("%s", result);
	if(q == 0)
		return result;
	else if(q == 1)
	{
		if(p == 0)
			strcat(result, "jan");
		else
			strcat(result, " jan");
	}
	else if(q == 2)
	{
		if(p == 0)
			strcat(result, "feb");
		else
			strcat(result, " feb");
	}
	else if(q == 3)
	{
		if(p == 0)
			strcat(result, "mar");
		else
			strcat(result, " mar");
	}
	else if(q == 4)
	{
		if(p == 0)
			strcat(result, "apr");
		else
			strcat(result, " apr");
	}
	else if(q == 5)
	{
		if(p == 0)
			strcat(result, "may");
		else
			strcat(result, " may");
	}
	else if(q == 6)
	{
		if(p == 0)
			strcat(result, "jun");
		else
			strcat(result, " jun");
	}
	else if(q == 7)
	{
		if(p == 0)
			strcat(result, "jly");
		else
			strcat(result, " jly");
	}
	else if(q == 8)
	{
		if(p == 0)
			strcat(result, "aug");
		else
			strcat(result, " aug");
	}
	else if(q == 9)
	{
		if(p == 0)
			strcat(result, "sep");
		else
			strcat(result, " sep");
	}
	else if(q == 10)
	{
		if(p == 0)
			strcat(result, "oct");
		else
			strcat(result, " oct");
	}
	else if(q == 11)
	{
		if(p == 0)
			strcat(result, "nov");
		else
			strcat(result, " nov");
	}
	else if(q == 12)
	{
		if(p == 0)
			strcat(result, "dec");
		else
			strcat(result, " dec");
	}

	return result;
}

int ctoi(char word[10000])//字符串转数字
{
	int length = strlen(word);
	int result = 0;
	//printf("ctoiing:\n");
	for(int i = 0; i < length; i++)
	{
		int temp = word[i] - 48;
		result = result * 10 + temp;
	//	printf("%c to %d ", word[i], temp);
	}
	//printf("ctoi result: %d\n", result);

	return result;
}

int mtoe(char word[10000])//火星语转数字
{

	int result = 0;
	if(strstr(word, "jan") != NULL)
		result += 1;
	else if(strstr(word, "feb") != NULL)
		result += 2;
	else if(strstr(word, "mar") != NULL)
		result += 3;
	else if(strstr(word, "apr") != NULL)
		result += 4;
	else if(strstr(word, "may") != NULL)
		result += 5;
	else if(strstr(word, "jun") != NULL)
		result += 6;
	else if(strstr(word, "jly") != NULL)
		result += 7;
	else if(strstr(word, "aug") != NULL)
		result += 8;
	else if(strstr(word, "sep") != NULL)
		result += 9;
	else if(strstr(word, "oct") != NULL)
		result += 10;
	else if(strstr(word, "nov") != NULL)
		result += 11;
	else if(strstr(word, "dec") != NULL)
		result += 12;
		
	if(strstr(word, "tam") != NULL)
		result += 13;
	else if(strstr(word, "hel") != NULL)
		result += 26;
	else if(strstr(word, "maa") != NULL)
		result += 39;
	else if(strstr(word, "huh") != NULL)
		result += 52;
	else if(strstr(word, "tou") != NULL)
		result += 65;
	else if(strstr(word, "kes") != NULL)
		result += 78;
	else if(strstr(word, "hei") != NULL)
		result += 91;
	else if(strstr(word, "elo") != NULL)
		result += 104;
	else if(strstr(word, "syy") != NULL)
		result += 117;
	else if(strstr(word, "lok") != NULL)
		result += 130;
	else if(strstr(word, "mer") != NULL)
		result += 143;
	else if(strstr(word, "jou") != NULL)
		result += 156;
	//printf("")
	return result;
}
