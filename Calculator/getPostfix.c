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