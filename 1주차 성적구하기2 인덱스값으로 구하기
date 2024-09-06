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
		total += number[i];
	}
	avg = (float)/*실수 취급(형 변환)*/total / SIZE;
	max = 0;
	min = 0;
	for (int i = 1; i < SIZE; i++)
	{
		if (number[i] > number[max])
		{
			max = i;
		}
		if (number[i] < number[min])
		{
			min = i;
		}
	}
	printf("ang=%f, max=%d -> %d, min=%d -> %d", avg, max+1, number[max], min + 1, number[min]);
	return 0;
}
