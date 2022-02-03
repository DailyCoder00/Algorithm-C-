#include<stdio.h>
#include<stdlib.h>

int *x;
int nx;

void Swap(int a, int b){
    int temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}

void downheap(int root, int right){
    int temp = x[root];
    int big_child; //큰 자식
    int parent = root; //루트를 부모로 초기화

    //부모의 값이 트리의 마지막 부모다 커질 때(자식이 없을 때) 까지 반복
    for(parent = root; parent <= (right-1)/2; parent = big_child){
        int lchild = (parent*2)+1; //왼쪽 자식
        int rchild = (parent*2)+2; //오른쪽 자식

        if(rchild <= right){ //자식이 모두 있는 경우
            big_child = (x[rchild] > x[lchild]) ? rchild:lchild; //두 자식 중 큰 값 선택
        }else{ //왼쪽 자식만 있는 경우
            big_child = lchild; //왼쪽 자식 선택
        }
        
        if(temp >= x[big_child]){ //부모가 더 큰 경우 반복문 종료
            break;
        }
        x[parent] = x[big_child]; //자식노드 값을 부모노드에 복사(삽입 정렬)

    }
    
    x[parent] = temp; //부모노드에 미리 저장해놓은 루트값 저장
}

void HeapSort(){
    int i;
    for(i = (nx-1)/2; i>=0; i--){ //무작위로 입력된 배열을 힙 형태로 정렬
        downheap(i,nx-1);
    }
    Swap(nx-1,0); //  루트값과 가장 마지막 자식의 값을 교환

    for(i = nx-2; i > 0; i--){ 
        downheap(0,i); //0~i까지 힙정렬을 통해 root의 값이 자기자리를 찾아가도록 정렬
        Swap(i,0); //루트값과 가장 마지막 자식의 값을 교환
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

    HeapSort();

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;

}