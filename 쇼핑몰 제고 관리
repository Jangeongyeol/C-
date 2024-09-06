#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 100

int main()
{
	int type,id;
	int in[SIZE];
	int out[SIZE];
	printf("상품 개수(종류)입력(1~100):");
	scanf("%d", &type);
	if (type < 1 || type > 100)
	{
		printf("1~100까지 입력\n");
	}
	for (int i = 0; i < type; i++)
	{
		printf("상품 %d의 입고수량 입력:", i + 1);
		scanf("%d", &in[i]);
	}
	for (int i = 0; i < type; i++)
	{
		printf("상품 %d의 판매수량 입력:", i + 1);
		scanf("%d", &out[i]);
	}
	printf("확인할 상품ID 입력(1~%d):", type);
	scanf("%d", &id);
	if (id < 1 || id > type)
	{
		printf("1~100까지 입력\n");
	}
	int inventory = in[id - 1] - out[id - 1];
	printf("입력한 ID에 해당하는 제품 제고 수량:%d\n", inventory);
	int total = 0;
	for (int i = 0; i < type; i++)
	{
		total += in[i] - out[i];
	}
	printf("모든 상품의 총 재고 수량:%d\n", total);
	return 0;
}
