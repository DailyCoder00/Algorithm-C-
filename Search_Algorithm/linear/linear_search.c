//선형 검색 알고리즘(Linear search Algorithm)
//순차 검색 알고리즘(Sequential search Algorithm)
#include<stdio.h>
#include<stdlib.h>

int linear_search(int a[], int na){
    int i;
    for(i = 0; i<=na; i++){
        if(a[i] == a[na]){
            break;
        }
    }

    return i==na ? -1:i; //찾는 값은 없으면 -1, 있으면 인덱스 위치 반환
}

int main(){
    int *x; //데이터를 입력받을 배열의 포인터
    int idx; //key의 위치
    int nx; //배열 x의 요소 개수
    int ky; //검색할 값

    printf("배열 요소의 개수:");
    scanf("%d", &nx);
    x = calloc(nx+1,sizeof(int));
    
    for(int i=0; i<nx; i++){
        printf("x[%d]:",i);
        scanf("%d", &x[i]);
    }

    printf("검색할 값:");
    scanf("%d", &ky);
    x[nx] = ky; //보초법 이용

    idx = linear_search(x,nx);

    if(idx == -1){
        printf("검색에 실패하였습니다.\n");
    }else{
        printf("검색 대상의 위치:%d\n", idx);
    }
    
    free(x);
    return 0;

}