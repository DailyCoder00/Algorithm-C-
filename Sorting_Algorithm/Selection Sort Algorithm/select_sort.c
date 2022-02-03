//선택정렬
//i ~ n-1번째 요소들 중에 가장 작은 값을 찾아 i번째 요소와 교환하는 알고리즘

#include<stdio.h>
#include<stdlib.h>

int *x; //정렬 대상을 담는 배열의 주소를 할당할 변수
int nx; //배열x의 요소의 개수

void Swap(int a, int b){ //배열x의 두 요소의 값을 교환하는 함수
    int temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}

int SearchMin(int a, int b){ //i ~ n-1번째 요소들 중 최솟값을 가진 요소의 인덱스를 반환
    int min = x[a]; //최솟값
    int idx = a; //최솟값을 가진 요소의 인덱스
    for(int i = a+1; i <= b; i++){
        if(x[i] < min){
            min = x[i];
            idx = i;
        }
    }

    return idx;
}

void SortSelection(){ //선택정렬을 구현한 함수
    int minIdx;
    for(int i = 0; i < nx-1; i++){
        Swap(SearchMin(i, nx-1), i); //최솟값을 가진 요소와 i번째 요소를 교환
    }
}

int main(){
    printf("요소의 개수:");
    scanf("%d", &nx);

    x = calloc(nx,sizeof(int)); //배열x 동적할당

    for(int i = 0; i < nx; i++){
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    SortSelection(); //선택정렬 실행

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }

    printf("\n");

    free(x);

    return 0;
}