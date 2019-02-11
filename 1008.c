#include<stdio.h>

int main()
{
	int number[100];
	int n;
	int move;
	scanf("%d %d", &n, &move);
	for(int i = 0; i < n; i++)
		scanf("%d", &number[i]);
	for(int i = n - move; i < n; i++)
	{
		printf("%d ", number[i]);
	}
	for(int i = 0; i < n - move -1; i++)
		printf("%d ", number[i]);
	printf("%d", number[n - move - 1]);
}