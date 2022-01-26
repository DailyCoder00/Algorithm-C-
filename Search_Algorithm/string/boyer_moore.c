#include<stdio.h>
#include<string.h>
#define ASCII 256

int Max(int a, int b){
    if(a > b) return a;
    else return b;
}

void SkipTable(const char* pattern, int *skip){
    int patternSize = strlen(pattern);
    for(int sp = 0; sp < ASCII; sp++){
        skip[sp] = patternSize;
    }
    
    for(int pp = 0; pp < patternSize-1; pp++){
        skip[(int)pattern[pp]] = patternSize - 1 - pp;
    }
}

int Boyer_Moore(const char* text, const char* pattern){
    int skip[ASCII];
    SkipTable(pattern, skip);
    int patternSize = strlen(pattern);
    int textSize = strlen(text);
    int tp = patternSize - 1;
    int pp = patternSize - 1;

    while(tp < textSize){
        if(text[tp] == pattern[pp]){
            if(pp == 0){ //패턴을 찾았을 경우
                return tp;
            }else{
                tp--; pp--;
            }
        }else{
            tp += Max(skip[text[tp]], patternSize - pp); //Reverse 방지
            pp = patternSize - 1;
        }
    }

    return -1;
}

int main(){
    char s1[256]; //텍스트
    char s2[256]; //패턴
    puts("Search by Boyer-moore");
    printf("텍스트:");
    scanf("%s", s1);
    printf("패턴:");
    scanf("%s", s2);

    int idx = Boyer_Moore(s1, s2);
    
    if(idx == -1){
        puts("패턴이 없습니다");
    }else{
        printf("%d번째 위치 부터 패턴과 일치합니다.\n", idx);
    }

    return 0;
}