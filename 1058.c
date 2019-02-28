	#define _CRT_SECURE_NO_WARNINGS
	#include<stdio.h>
	#include<string.h>

		int question[1005][2];//保存问题的分值和选项个数
		int wrong[1005] = { 0 };
		char answer[1005][6];//保存问题的答案。
		int stmarks[1005] = { 0 };
		char response[1005][1005][6];

	int main()
	{
		int N, M;
		scanf("%d %d", &N, &M);

		for (int i = 0; i < M; i++)
		{
			char c;
			int count = 0;
			int temp;
			char tempc[100];
			scanf("%d", &question[i][0]);
			scanf("%d", &temp);
			scanf("%d", &question[i][1]);
			
			while (count != question[i][1])
			{
				c = getchar();
				if (c >= 'a' && c <= 'z')
					answer[i][count++] = c;
			}

		}
		for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				int count = 0;
				char c;
				while ((c = getchar()) != ')')
					if (c >= 'a' && c <= 'z')
						response[i][j][count++] = c;
				if (strcmp(response[i][j], answer[j]))
					wrong[j]++;
				else
					stmarks[i] += question[j][0];
			}
		for(int i = 0; i < N; i++)
			printf("%d\n", stmarks[i]);
		int max = 0;
		for(int i = 0; i < M; i++)
			if(wrong[i] > max)
				max = wrong[i];
		printf("%d", max);
		for(int i = 0; i < M; i++)
			if(max == wrong[i])
				printf(" %d", i + 1);
	}