#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#define SIZE 100

void in_void(int in[], int *type, char name[][SIZE], int price[]) {
    int id;
    printf("상품 개수(종류) 입력 (1~5): ");
    scanf("%d", type);
    if (*type < 6) {
        for (int i = 0; i < *type; i++) {
            printf("상품 ID입력(숫자): ");
            scanf("%d", &id);
            printf("\n");
            printf("상품명 입력(문자): ");
            scanf("%s", name[i]);
            printf("\n");
            printf("상품 %d의 입고수량 입력: ", i + 1);
            scanf("%d", &in[i]);
            printf("\n");
            printf("판매 가격입력: ");
            scanf("%d", &price[i]);
            printf("\n");
        }
    } else {
        printf("상품의 갯수는 최대 5개로 합니다\n");
    }
}

void out_void(int out[], int *type) {
    int id;
    printf("상품 ID 입력: ");
    scanf("%d", &id);
    if (id == 0) {
        printf("상품의 ID가 없습니다\n");
    }
    if (id >= 1 && id <= *type) {
        printf("해당 상품의 판매 수량 입력: ");
        scanf("%d", &out[id - 1]);
    }
}

void ind_stat_void(int in[], int out[], int *type, char name[][SIZE], int price[]) {
    int id;
    printf("확인할 상품 ID 입력 (1~5): ");
    scanf("%d", &id);
   
    if (id >= 1 && id <= *type) {
        printf("상품명: %s\n", name[id - 1]);
        printf("가격: %d\n", price[id - 1]);
        int inventory = in[id - 1] - out[id - 1];
        printf("입력한 ID에 해당하는 제품 재고 수량: %d", inventory);
        if (inventory <= 2) {
            printf(" (재고 부족)\n");
        }
        printf("판매량: %d (판매율: %.2f%%)\n", out[id - 1], ((float)out[id - 1] / in[id - 1]) * 100);
    } else {
        printf("잘못된 ID입니다.\n");
    }
    printf("\n");
}

void all_stat_void(int in[], int out[], char name[][SIZE], int price[], int *type) {
    int max_out_id = 0, min_out_id = 0;
    for (int i = 1; i < *type; i++) {
        if (out[i] > out[max_out_id]) {
            max_out_id = i;
        }
        if (out[i] < out[min_out_id]) {
            min_out_id = i;
        }
    }

    int total_in = 0, total_out = 0;
    for (int i = 0; i < *type; i++) {
        total_out += out[i];
        total_in += in[i];
    }

    if (total_in > 0) {
        float total_percent = ((float)total_out / total_in) * 100;
        for (int i = 0; i < *type; i++) {
            printf("ID %d %s 판매량: %d (판매율: %.2f%%)\n", i + 1, name[i], out[i], ((float)out[i] / in[i]) * 100);
        }
    }
    printf("가장 많이 판매된 상품 ID: %d, 상품명: %s, 판매량: %d\n", max_out_id + 1, name[max_out_id], out[max_out_id]);
    printf("가장 적게 판매된 상품 ID: %d, 상품명: %s, 판매량: %d\n", min_out_id + 1, name[min_out_id], out[min_out_id]);

    for (int i = 0; i < *type; i++) {
        int inventory = in[i] - out[i];
        if (inventory <= 2) {
            printf("상품 ID %d: 상품명: %s 재고 부족 (%d)\n", i + 1, name[i], inventory);
        }
    }
}

int main() {
    int type = 0;
    int in[SIZE] = {0};
    int out[SIZE] = {0};
    int price[SIZE] = {0};
    int menu;
    char name[SIZE][SIZE];

    while (1) {
        printf("원하는 메뉴를 선택하세요 (1. 입고, 2. 판매, 3. 개별현황, 4. 전체현황 5. 종료): ");
        scanf("%d", &menu);

        if (menu == 1) {
            in_void(in, &type, name, price);
        } else if (menu == 2) {
            out_void(out, &type);
        } else if (menu == 3) {
            ind_stat_void(in, out, &type, name, price);
        } else if (menu == 4) {
            all_stat_void(in, out, name, price, &type);
        } else if (menu == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}
