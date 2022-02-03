#include<stdio.h>
#include<stdlib.h>

int *x;
int nx;

void CountingSort(max){
    int *f = calloc(max+1, sizeof(int));
    int *s = calloc(nx, sizeof(int));
    for(int i = 0; i < nx; i++) f[x[i]]++; //도수분포표 제작
    for(int i = 1; i <= max; i++) f[i] += f[i-1]; //누적 도수분표표 제작
    for(int i = nx-1; i >= 0; i--) s[--f[x[i]]] = x[i]; //목적배열에 오름차순으로 정렬
    for(int i = 0; i < nx; i++) x[i] = s[i]; //복사

    free(f);
    free(s);
}

int main(){
    int max = 100;
    printf("요소의 개수:");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(int i = 0; i < nx; i++){
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    CountingSort(max);    

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;

}