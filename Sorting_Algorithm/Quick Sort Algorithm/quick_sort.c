#include<stdio.h>
#include<stdlib.h>

int *x; //정렬 대상을 담을 배열의 포인터 변수
int nx; //배열x의 요소의 개수

void Swap(int a, int b){ //배열x의 두 요소의 값을 교환하는 함수
    int temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}

void SortQuick(int left, int right){
    int pl = left;
    int pr = right;
    int pivot = x[rand()%(right-left+1)+left]; //left ~ right사이의 랜덤한 povit 선택
    
    do{
        while(x[pl] < pivot) pl++;
        while(x[pr] > pivot) pr--;
        if(pl <= pr){
            Swap(pl, pr);
            pl++;
            pr--;
        }
    }while(pl<=pr);

    if(pr > left) SortQuick(left,pr);
    if(pl < right) SortQuick(pl,right);
}

int main(){
    printf("요소의 개수:");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(int i = 0; i < nx; i++){
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    SortQuick(0, nx-1);//퀵정렬 실행

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;

}