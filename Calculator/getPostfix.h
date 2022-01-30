#ifndef ___GetPostfix
#define ___GetPostfix

typedef struct{
    char *stack; //연산자를 담는 스택
    int max; //스택의 최대 용량
    int ptr; //현재 요소의 개수
}Postfix;

int Initialize(Postfix *p, int size);

int Push(Postfix *p, char operater1);

int Pop(Postfix *p);

char Peek(Postfix *p);

int IsEmpty(Postfix *p);

int GetPostfix(Postfix *p, char *input, char* result);

#endif