#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

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

void Clear(IntStack *s){ //스택 비우기
    s->ptr = 0;
}

int Capacity(IntStack *s){ //최대용량
    return s->max;
}

int Size(IntStack *s){ //스택 내 저장된 데이터 개수
    return s->ptr;
}

int IsEmpty(IntStack *s){ //스택 비어있는가?
    return s->ptr <= 0;
}

int IsFull(IntStack *s){ //스택이 가득 찼는가?
    if(s->ptr >= s->max){
        return 0;
    }
    return -1;
}

int Search(IntStack *s, int x){ //스택 내 데이터 검색
    for(int i=0; i<s->ptr; i++){
        if(s->stack[i] == x){
            return i;
            
        }
    }
    return -1;
}

void Print(IntStack *s){ //스택 내 데이터 모두 출력
    for(int i=0; i<s->ptr; i++){
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

void Terminate(IntStack *s){ //스택 종료
    if(s->stack != NULL){
        free(s->stack);
    }
    s->max = s->ptr = 0;
}

