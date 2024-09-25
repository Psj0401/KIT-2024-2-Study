#include <stdio.h>
#include <stdlib.h>  // 동적 메모리 할당을 위해 필요

#define SIZE 8

int denominations[SIZE] = {50000, 10000, 5000, 1000, 500, 100, 10, 1};  // 화폐 단위

void m(int a) {
    // 동적 메모리 할당 (배열 크기만큼)
    int* count = (int*)malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        count[i] = a / denominations[i];  // 각 화폐 단위에 맞는 개수 계산
        a -= denominations[i] * count[i];  // 남은 금액 계산
    }

    printf("오만원 지폐 : %d장\n", count[0]);
    printf("일만원 지폐 : %d장\n", count[1]);
    printf("오천원 지폐 : %d장\n", count[2]);
    printf("일천원 지폐 : %d장\n", count[3]);
    printf("오백원 동전 : %d개\n", count[4]);
    printf("일백원 동전 : %d개\n", count[5]);
    printf("일십원 동전 : %d개\n", count[6]);
    printf("일원 동전 : %d개\n", count[7]);

    // 메모리 해제
    free(count);
}

int main(void) {
    int a;
    printf(">> ");
    scanf("%d", &a); getchar();  // 입력받은 값을 a에 저장
    m(a);  // 입력받은 값으로 함수 호출
    return 0;
}
