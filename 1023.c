#include<stdio.h>

int main()
{
	int count[10];
	for(int i = 0; i < 10; i++)
		scanf("%d", &count[i]);

	for(int i = 1; i < 10; i++)
		if(count[i] > 0)
		{
			printf("%d", i);
			count[i]--;
			break;
		}
		
	for(int i = 0; i < 10; i++)
		for(int j = count[i]; j > 0 ; j--)
			printf("%d", i);

}
/*审题错误，以下代码为输入50个不同的0-9的数字，将其排列成最小数并输出（首尾不为0）
int main()
{
	char number[50];
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//各数字个数统计
	int n = 0;//总数字个数
	//int tag = 0;//标记是否已输出第一个非0数
	//输入部分，并将输入的数字保存到count中；
	do
	{
		scanf("%c", &number[n]);
		if(number[n] != ' ')
			n++; 	
	}while(number[n-1] != '\n');
	n--;
	for(int i = 0; i < n; i++)
	{
		number[i] -= 48;
		count[(int)number[i]]++;
		//printf("%d:%d\n", i, number[i]);
	}

	//for(int i = 0; i < 10; i++)
	//	printf("count  %d:%d\n", i, count[i]);

	for(int i = 1; i < 10; i++)
		if(count[i] > 0)
		{
			printf("%d", i);
			count[i]--;
			break;
		}
	//printf("now\n");
	for(int i = 0; i < 10; i++)
		for(int j = count[i]; j > 0 ; j--)
			printf("%d", i);
}
*/