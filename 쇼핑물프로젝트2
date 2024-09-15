#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 100

int main()
{
    int type, id;
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
    int inventory = in[id - 1] - out[id - 1]; //제고수량
    printf("입력한 ID에 해당하는 제품 제고 수량:%d\n", inventory);
    printf("제고수량: ");
    for (int i = 0; i < type; i++)
    {
        printf("%d\t", in[i] - out[i]);
    }
    printf("\n");

    int max_out_id = 0, min_out_id = 0;
    for (int i = 1; i < type; i++) // 1부터 시작
    {
        if (out[i] > out[max_out_id])
        {
            max_out_id = i;
        }
        if (out[i] < out[min_out_id])
        {
            min_out_id = i;
        }
    }

    int total_in = 0;
    int total_out = 0;
    for (int i = 0; i < type; i++)
    {
        total_out += out[i]; //전체 판매
        total_in += in[i]; //전체 입고
    }
    float total_persent = ((float)total_out / total_in) * 100; //총 판매율
    printf("총 판매량 %d(판매율 %.2f%%)\n", total_out, total_persent);
    printf("가장 많이 판매된 상품 ID %d 판매량 %d\n", max_out_id + 1, out[max_out_id]);
    printf("가장 적게 판매된 상품 ID %d 판매량 %d\n", min_out_id + 1, out[min_out_id]);
    for (int i = 0; i < type; i++)
    {
        int inventory = in[i] - out[i];
        if (inventory <= 2)
        {
            printf("상품 ID %d: 재고부족(%d)\n", i + 1, inventory);
        }
    }

    return 0;
}
