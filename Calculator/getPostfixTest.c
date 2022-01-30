#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "getPostfix.h"

int main(){
    Postfix p;
    char *result;
    char input[256];

    puts("문자열 입력");
    scanf("%s", input);

    if(!Initialize(&p, strlen(input))){
        printf("계산에 실패했습니다.\n");
        printf("원인 : 후위표기법 구조체 생성 실패\n");
    }
    result = calloc(strlen(input), sizeof(char));
    
    if(GetPostfix(&p, input, result) == 1){
        printf("후위표기 결과 : %s\n", result);
    }else{
        printf("계산에 실패했습니다.\n");
        printf("원인 : 계산식 형태 수정필요");
    }

    return 0;
}