/* 후위표기법(Postfix) 알고리즘
후위표기법은 중위표기법과 다르게 연산자들이 피연산자 뒤에 모여있는 형태다.
컴파일러는 중위표기법을 이해못하기때문에 중위표기법을 후위표기법으로 변환하여 계산한다.

후위표기법을 나타내기 위한 조건
1. 피연산자는 아무조건 없이 출력한다
2. '('는 스택에 Push한다
3. '+,-,*,/'는 스택에 아무것도 없으면 Push,
    다른 연산자가 존재하면 자신보다 우선순위가 높거나 같은 연산자는 모두 출력한다.
    연산자 우선순위 - '()' > '*, /' > '+, -'

4. ')'괄호가 나오면 '('괄호가 나올 때까지 Pop한다.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "getPostfix.h"

int Initialize(Postfix *p, int size){
    p->ptr = 0;
    p->stack = calloc(size, sizeof(Postfix));
    if(p->stack != NULL){
        p->max = size;
        return 1;
    }else{
        return 0;
    }
}

int Push(Postfix *p, char operater1){
    if(p->ptr < p->max){
        p->stack[p->ptr++] = operater1;
        return 1;
    }else{
        return 0;
    }
}

int Pop(Postfix *p){
    if(p->ptr > 0){
        p->ptr--;
        return 1;
    }else{
        return 0;
    }
}

char Peek(Postfix *p){
    return p->stack[((p->ptr)-1)];
}

int IsEmpty(Postfix *p){
    return p->ptr <= 0;
}


int GetPostfix(Postfix *p, char *input, char* result){
    int i = 0; //input의 index
    int r = 0; //result의 index
    int inputSize = strlen(input);
    

    while(i < inputSize){
        if(input[i] >= 65 && input[i] <= 90){
            result[r++] = input[i++];

        }else if(input[i] == '('){
            if(!Push(p, input[i++])) return -1;

        }else if(input[i] == '*' || input[i] == '/'){
            while(!IsEmpty(p) && (Peek(p) == '*' || Peek(p) == '/')){
                result[r++] = Peek(p);
                Pop(p);
            }
            Push(p, input[i++]);
        }else if(input[i] == '+' || input[i] == '-'){
            while(!IsEmpty(p) && Peek(p) != '('){
                result[r++] = Peek(p);
                if(Pop(p) == 0) return -1;
            }
            Push(p,input[i++]);

        }else if(input[i] == ')'){
            while(!IsEmpty(p) && Peek(p) != '('){
                result[r++] = Peek(p);
                if(Pop(p) == 0) return -1;
            }
            if(Pop(p) == 0) return -1;
            i++;
        }
    }

    
    while(!IsEmpty(p)){
        result[r++] = Peek(p);
        if(Pop(p) == 0) return -1;
    }
    result[r] = '\0';

    return 1;
}