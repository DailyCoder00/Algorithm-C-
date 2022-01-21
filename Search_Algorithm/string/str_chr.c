#include<stdio.h>

//strchr 내장함수 구현(찾는 문자에 대한 포인터 반환, 찾는 문자가 없으면 NULL 반환)
char* str_chr(char *str, int c){
    char key = (int)c;
    while(*str != '\0'){
        if(*str == key){
            return str;
        }

        str++;
    }

    if(*str == key) return str; //key가 NULL일 경우
    else return NULL;

}

int main(){
    char str[64];
    char temp[64];

    printf("문자열 입력:");
    scanf("%s", str);

    printf("찾을 문자 입력:");
    scanf("%s", temp);
    int key = *temp;

    printf("입력한 문자열의 주소: %p\n", str);

    char* cptr = str_chr(str, key);
    if(cptr != NULL){
        printf("포인터 주소 : %p\n", cptr);
    }else{
        printf("찾는 값이 없음\n");
    }

    return 0;

}
