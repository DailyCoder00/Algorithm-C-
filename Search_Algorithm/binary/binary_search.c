#include<stdio.h>
#include<stdlib.h>

int binary_search(int a[], int na, int key){
    int pl = 0; //시작 위치
    int pc; //중앙 인덱스
    int pr = na-1; //마지막 위치

    do{
        pc=(pl+pr)/2;
        if(a[pc] == key){
            return pc;
        }else if(a[pc] < key){
            pl = pc+1;
        }else{
            pr = pc-1;
        }
    }while(pl <= pr);

    return -1;

}


int main(){
    int *x; //데이터를 입력받을 배열의 포인터
    int idx; //key의 위치
    int nx; //배열 x의 요소 개수
    int ky; //검색할 값

    printf("배열 요소의 개수:");
    scanf("%d", &nx);
    x = calloc(nx+1,sizeof(int));
    
    printf("오름차순으로 입력하시오.\n");
    for(int i=0; i<nx; i++){
        printf("x[%d]:",i);
        scanf("%d", &x[i]);
    }

    printf("검색할 값:");
    scanf("%d", &ky);

    idx = binary_search(x,nx,ky);

    if(idx == -1){
        printf("검색에 실패했습니다.\n");
    }else{
        printf("검색 대상의 위치: %d\n", idx);
    }

    free(x);
    return 0;
    
}