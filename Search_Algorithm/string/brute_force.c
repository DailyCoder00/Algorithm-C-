#include<stdio.h>

int brute_force(const char *text, const char *pat){
    int tp = 0; //텍스트 커서
    int pp = 0; //패턴 커서

    while(text[tp] != '\0' && pat[pp] != '\0'){
        if(text[tp] == pat[pp]){
            tp++;
            pp++;

        }else{
            tp = tp - pp + 1;
            pp = 0;
        }
    }

    if(pat[pp] == '\0') return tp - pp + 1;
    else return -1;

}

int main(){
    char s1[256]; //텍스트
    char s2[256]; //패턴
    puts("Search by Brute Fore");
    printf("텍스트:");
    scanf("%s", s1);
    printf("패턴:");
    scanf("%s", s2);

    int idx = brute_force(s1, s2);
    
    if(idx == -1){
        puts("패턴이 없습니다");
    }else{
        printf("%d번째 위치 부터 패턴과 일치합니다.\n", idx);
    }

    return 0;


}