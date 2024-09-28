#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 100

void in_void(int in[], int* type) {
    int cho_in, id;
    printf("1. 전체 상품 입고수량 2. 개별 상품 입고수량: ");
    scanf("%d", &cho_in);

    if (cho_in == 1) {
        printf("상품 개수(종류) 입력 (1~100): ");
        scanf("%d", type);
        for (int i = 0; i < *type; i++) {
            printf("상품 %d의 입고수량 입력: ", i + 1);
            scanf("%d", &in[i]);
        }
    } else if (cho_in == 2) {
        printf("상품 ID 입력: ");
        scanf("%d", &id);
        if (id >= 1 && id <= *type) {
            printf("해당 상품의 입고 수량 입력: ");
            scanf("%d", &in[id - 1]);
        }
    }
}

void out_void(int out[], int type) {
    int cho_out, id;
    printf("1. 전체 상품 판매수량 2. 개별 상품 판매수량: ");
    scanf("%d", &cho_out);

    if (cho_out == 1) {
        for (int i = 0; i < type; i++) {
            printf("상품 %d의 판매수량 입력: ", i + 1);
            scanf("%d", &out[i]);
        }
    } else if (cho_out == 2) {
        printf("상품 ID 입력: ");
        scanf("%d", &id);
        if (id >= 1 && id <= type) {
            printf("해당 상품의 판매 수량 입력: ");
            scanf("%d", &out[id - 1]);
        }
    }
}

void cho_void(char name[][SIZE], int* type)
{
        if (*type == 0)
    {
        printf("입력하신 입고 상품이 없습니다 입고에서 상품개수를 입력하시고 다시 해보십시오.\n");
    }
    for(int i = 0; i < *type; i++)
    {
        printf("id %d 상품명: ", i + 1);
        scanf("%s", name[i]);
        printf("\n");
    }
}

void stat_void(int in[], int out[], int type, char name[][SIZE]) {
    int id;
    printf("확인할 상품 ID 입력 (1~%d): ", type);
    scanf("%d", &id);
    if (id >= 1 && id <= type) {
        int inventory = in[id - 1] - out[id - 1];
        printf("입력한 ID에 해당하는 제품 재고 수량: %d\n", inventory);
    }

    printf("재고수량: ");
    for (int i = 0; i < type; i++) {
        printf("%d ", in[i] - out[i]);
    }
    printf("\n");

    int max_out_id = 0, min_out_id = 0;
    for (int i = 1; i < type; i++) {
        if (out[i] > out[max_out_id]) {
            max_out_id = i;
        }
        if (out[i] < out[min_out_id]) {
            min_out_id = i;
        }
    }
    
    int total_in = 0, total_out = 0;
    for (int i = 0; i < type; i++) {
        total_out += out[i];
        total_in += in[i];
    }

    if (total_in > 0) {
        float total_percent = ((float)total_out / total_in) * 100;
        printf("총 판매량: %d (판매율: %.2f%%)\n", total_out, total_percent);
    }

    printf("가장 많이 판매된 상품 ID: %d, 상품명: %s, 판매량: %d\n", max_out_id + 1, name[max_out_id], out[max_out_id]);
    printf("가장 적게 판매된 상품 ID: %d, 상품명: %s, 판매량: %d\n", min_out_id + 1,  name[min_out_id], out[min_out_id]);

    for (int i = 0; i < type; i++) {
        int inventory = in[i] - out[i];
        if (inventory <= 2) {
            printf("상품 ID %d: 상품명: %s 재고 부족 (%d)\n", i + 1, name[i] , inventory);
        }
    }
}

int main() {
    int type = 0;
    int in[SIZE] = {0}; //배열 초기화
    int out[SIZE] = {0};
    int menu;
    char name[SIZE][SIZE];

    while (1) {
        printf("원하는 메뉴를 선택하세요 (1. 입고, 2. 판매, 3. 상품현황, 4. 상품명 입력 5. 종료): ");
        scanf("%d", &menu);

        if (menu == 1)
        {
            in_void(in, &type);
        }
        else if (menu == 2)
        {
            out_void(out, type);
        }
        else if (menu == 3)
        {
            stat_void(in, out, type, name);
        }
        else if (menu == 4)
        {
            cho_void(name, &type);
        }
        else if (menu == 5)
        {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else
        {
            printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}
