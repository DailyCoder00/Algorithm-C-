#include<stdio.h>
#include<stdlib.h>

void swap(int a1[], int x, int y){ //요소 교환 알고리즘
    int temp = a1[x];
    a1[x] = a1[y]; 
    a1[y] = temp;

}

void ary_reverse(int a[], int n){
    for(int i=0; i<n/2; i++){
        swap(a,i,n-1-i); //i번째 요소와 n-i번째 요소를 교환
    }
}

int main(){
    int nx; //배열 x의 요소의 개수
    printf("요소 개수:");
    scanf("%d", &nx);
    int *x = malloc(sizeof(int)*nx); //배열x 동적할당

    printf("%d개의 요소를 입력\n", nx);
    for(int i=0; i<nx; i++){
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    ary_reverse(x,nx); //배열 역순 정렬
    for(int i=0; i<nx; i++){ //역순을 정렬된 요소 출력
        printf("%d ", x[i]);
    }
    
    

}