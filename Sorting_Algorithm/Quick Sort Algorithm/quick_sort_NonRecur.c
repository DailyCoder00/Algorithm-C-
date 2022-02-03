#include<stdio.h>
#include<stdlib.h>

typedef struct{ //스택을 구현할 구조체
    int max;
    int ptr;
    int *stack;

}IntStack;


int Initialize(IntStack *s, int max){ //스택 초기화
    s->ptr = 0;
    s->stack = calloc(max, sizeof(int));
    if(s == NULL){ //배열 생성 실패시
        s->max = 0; // 스택에 접근을 막기위해 크기를 0으로 설정
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x){ //Push
    if(s->ptr >= s->max){
        return -1;
    }
    s->stack[s->ptr++] = x;
    return 0;
}

int Pop(IntStack *s, int *x){ //Pop
    if(s->ptr <= 0){
        return -1;
    }
    *x = s->stack[--s->ptr];
    return 0;
}

int Peek(IntStack *s, int *x){ //Peek
    if(s->stack <=0 ){
        return -1;
    }
    *x = s->stack[(s->ptr)-1];
    return 0;
}

void Terminate(IntStack *s){ //스택 종료
    if(s->stack != NULL){
        free(s->stack);
    }
    s->max = s->ptr = 0;
}

int IsEmpty(IntStack *s){
    if(s->ptr <= 0){
        return 1;
    }else{
        return 0;
    }
}

//------------------------------------Stack구현------------------------------------

int *x;

void Swap(int a, int b){ //배열x의 두 요소의 값을 교환하는 함수
    int temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}

void NonRecurQuickSort(int left, int right){
    IntStack lstack;
    IntStack rstack;

    Initialize(&lstack, right+1);
    Initialize(&rstack, right+1);

    Push(&lstack, left);
    Push(&rstack, right);

    while(IsEmpty(&lstack) == 0){
        Pop(&lstack, &left);
        Pop(&rstack, &right);
        int pl = left;
        int pr = right;
        int pivot = x[(pl+pr)/2];
        
        do{
            while(x[pl] < pivot) pl++;
            while(x[pr] > pivot) pr--;
            if(pl <= pr){
                Swap(pl, pr);
                pl++;
                pr--;
            }
        }while(pl <= pr);

        if(pr > left){
            Push(&lstack, left);
            Push(&rstack, pr);
        }

        if(pl < right){
            Push(&lstack ,pl);
            Push(&rstack, right);
        }
    }

    Terminate(&lstack);
    Terminate(&rstack);
}

int main(){
    int nx;

    printf("요소의 개수:");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));

    for(int i = 0; i < nx; i++){
        printf("x[%d]:", i);
        scanf("%d", &x[i]);
    }

    NonRecurQuickSort(0,nx-1);

    for(int i = 0; i < nx; i++){
        printf("%d ", x[i]);
    }
    printf("\n");

    free(x);

    return 0;

}