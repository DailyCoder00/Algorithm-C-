#include<stdio.h>
#include<stdlib.h>

int *x; //정렬 대상을 담을 배열의 포인터 변수
int nx; //배열x의 요소의 개수

void SortInsert(){
    int temp;
    for(int i = 1; i < nx; i++){
        temp = x[i];
        int j = i;
        while(x[j-1] > temp && j > 0){
            x[j] = x[j-1]; 
            j--;
        }
        x[j] = temp;
    }
}

int main(){
    printf("요소의 개수:");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(int i = 0; i < nx; i++){
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    SortInsert();//삽입정렬 실행

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;
}