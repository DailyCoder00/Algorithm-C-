//분할정렬 알고리즘

#include<stdio.h>
#include<stdlib.h>

int *a; //정렬대상을 담을 배열 포인터
int na;
int *buffer; //임시공간 : 정렬된 요소들을 담는 배열 포인터

void SortMerge(int left, int right){
    if(left >= right) return; // 분할 종료조건 : 배열 요소가 1개 이하일 경우 

    int center = (left+right)/2; //분할할 위치

    //분할
    SortMerge(left, center); 
    SortMerge(center+1, right);

    int pl = left;
    int bn = left;
    int temp = center+1;
    
    //정렬과정
    while(pl <= center && temp <= right){
        if(a[pl] <= a[temp]){
            buffer[bn++] = a[pl++];
        }else{
            buffer[bn++] = a[temp++];
        }
    }

    //남은 요소들 복사
    while(pl <= center){
        buffer[bn++] = a[pl++];
    }
    while(temp <= right){
        buffer[bn++] = a[temp++];
    }

    //임시공간 -> 원래배열 복사
    for(int i = left; i <= right; i++){
        a[i] = buffer[i];
    }
    
}


int main(){
    printf("배열a 요소 개수:");
    scanf("%d", &na);

    a = malloc(sizeof(int)*na);
    buffer = malloc(sizeof(int)*na);

    for(int i = 0; i < na; i++){
        printf("a[%d]:", i);
        scanf("%d", &a[i]);
    }

    SortMerge(0,na-1);

    for(int i = 0; i < na; i++){
        printf("%d ", a[i]);
    }
    puts("");

    free(a);
    free(buffer);

    return 0;

}