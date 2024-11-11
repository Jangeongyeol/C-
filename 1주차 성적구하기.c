#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

int main()
{
	int number[SIZE];
	int total = 0;
	int max, min;
	float avg = 0.0;
	srand(time(NULL)); //현재 시간값을 시드값으로 지정
	for (int i = 0; i < SIZE; i++)
	{
		number[i] = (rand() % 100) + 1; //0부터100까지(나머지)
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		total += number[i]; //0부터100까지(나머지)
	}
	avg = (float)/*실수 취급(형 변환)*/total / SIZE;
	max = number[0];
	min = number[0];
	for (int i = 0; i < SIZE; i++)
	{
		if (max < number[i])
		{
			max = number[i];
		}
		if (max < number[i])
		{
			max = number[i];
		}
	}
	printf("ang=%f, max=%d, min=%d", avg,max,min);
	return 0;
}
