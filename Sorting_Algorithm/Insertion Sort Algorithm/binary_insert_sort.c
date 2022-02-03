#include<stdio.h>
#include<stdlib.h>

int *x; //정렬 대상을 담을 배열의 포인터 변수
int nx; //배열x의 요소의 개수

int SearchBinary(int end, int key){
    int pl = 0; //이진탐색 시작 인덱스
    int pc; //중앙 위치
    int pr = end-1; //이진탐색 종료 인덱스

    do{
        pc=(pl+pr)/2;
        if(x[pc] == key){
            return pc; //key와 중앙값이 같을 경우 중앙 인덱스를 반환
        }else if(x[pc] < key){
            pl = pc+1;
        }else{
            pr = pc-1;
        }
    }while(pl <= pr);

    return pl; //key가 없을 경우 종료 인덱스(반복문 종료 시 pr과 pl의 값이 서로 바뀜) 반환

}

void SortInsert(){
    int temp;
    for(int i = 1; i < nx; i++){
        temp = x[i];
        int j = i;
        int k = SearchBinary(i,temp);
        
        while(j-1 >= k){
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