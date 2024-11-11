#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int number[10];
	srand(time(NULL)); //현재 시간값을 시드값으로 지정
	for (int i = 0; i < 10; i++)
	{
		number[i] = (rand() % 100) + 1; //0부터100까지(나머지)
	}
	for(int i = 0; i < 10; i++)
	{
		printf("number = %d\n", number[i]);
	}
	return 0;
}
