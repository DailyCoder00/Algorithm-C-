//버블정렬
//x[j]와 x[j-1]를 비교하여 작은 값을 왼쪽으로 보내는 알고리즘

#include<stdio.h>
#include<stdlib.h>

int *x; //정렬 대상을 담을 요소
int nx; //배열x의 요소의 개수
int lastSwap; //가장 마지막으로 swap한 위치

void Swap(int a, int b){ //배열x의 두 요소의 값을 교환하는 함수
    int temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}

void SortBubble(){ //버블정렬을 구현한 함수
    int i = 0;
    while(i < nx-1){
        lastSwap = nx-1; //무한루프 방지
        for(int j = nx-1; j>i; j--){
            if(x[j-1] > x[j]){ //왼쪽값이 오른쪽 값보다 크면
                Swap(j-1, j); //Swap함수로 두 값을 교환
                lastSwap = j; //마지막으로 교환한 인덱스 수정
            }
        }
        i = lastSwap; //마지막으로 교환한 인덱스로 i값 수정
        
    }
}

int main(){
    printf("요소의 개수:");
    scanf("%d", &nx);

    x = calloc(nx,sizeof(int));

    for(int i = 0; i < nx; i++){
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    SortBubble(); //버블정렬 실행

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;
}