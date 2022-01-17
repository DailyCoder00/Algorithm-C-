#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int a[], int n){
    int rn;
    int temp;
    for(int i=0; i<n-1; i++){
        rn = (i+1)+rand()%(n-i-1);
        temp = a[i];
        a[i] = a[rn];
        a[rn]= temp;
    }
}

int main(){
    int arg;
    int temp;
    printf("요소의 개수 입력:");
    scanf("%d", &arg);
    int *arr = malloc(sizeof(int)*arg);
    for(int i=0; i<arg; i++){
        printf("%d번째 인덱스 값 입력:", i+1);
        scanf("%d", &temp);
        arr[i] = temp;
    }

    shuffle(arr,arg);

    for(int i=0; i<arg; i++){
        printf("%d ", arr[i]);
    }
    
    free(arr);
}