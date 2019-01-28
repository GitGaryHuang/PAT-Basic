#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	int count = 0;
	int last = 1;
	int now = 1;
	scanf("%d", &n);
	int IsPrime(int n);
	for(int i = 2; i <= n; i++)
	{
		int tag = 0;
		tag = IsPrime(i);
		if(tag == 0)
		{
			last = now;
			now = i;
			if(now - last == 2)
				count++;
		}
	}

	printf("%d", count);
}

int IsPrime(int n)
{
	for(int i = 2; i <= (sqrt(n)); i++)
		if(n % i == 0)
			return 1;
	return 0;
}