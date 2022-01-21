#include<stdio.h>

//strcmp 내장함수 구현(s1 == s2 : 0 반환, s1 != s2 : s1 - s2 반환)
int str_cmp(const char *s1, const char *s2){
    while(*s1 == *s2){
        if(*s1 == '\0'){
            return 0;
        }
        s1++;
        s2++;
    }

    return (unsigned char) *s1 - (unsigned char) *s2;
}

int main(){
    char str[64];
    int result;
    int menu;

    puts("\"ABCD\"와 비교합니다");
    while(1){
        puts("(1)문자열 비교 (2) 종료");
        printf("선택:");
        scanf("%d", &menu);

        if(menu != 1){
            puts("프로그램 종료");
            break;
        }else{
            printf("비교할 문자: ");
            scanf("%s", str);
            result = str_cmp("ABCD", str);
            printf("결과 : %d\n", result);
        }
        
        
        
    }

    return 0;
}