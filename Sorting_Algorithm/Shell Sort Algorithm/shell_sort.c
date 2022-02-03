#include<stdio.h>
#include<stdlib.h>

int *x; //정렬 대상을 담을 배열의 포인터 변수
int nx; //배열x의 요소의 개수

void SortShell(){
    int temp;
    int j;
    for(int h = nx/2; h>0; h /= 2){
        for(int i = h; i<nx; i++){
            temp = x[i];
            for(j = i-h; x[j]>temp && j>=0; j-= h){ //wh
                x[j+h] = x[j];
            }
            x[j+h] = temp; //반복만이 끝나면 j = j - h 상태이므로 j+h 인덱스에 temp값 저장
        }
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

    SortShell();//삽입정렬 실행

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;

}