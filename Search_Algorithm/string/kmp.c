#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void SkipTable(const char* pattern, int *skip){
    int patternSize = strlen(pattern);
    int pa = 0;
    for(int pb = 1; pb < patternSize; pb++){
        while(pa > 0 && pattern[pa] != pattern[pb]){ 
            pa = skip[pa-1];
        }

        if(pattern[pa] == pattern[pb]){
            skip[pb] = ++pa;
        }
    }
}

int KMP(const char* text, const char* pattern){
    int *skip = calloc(0, sizeof(pattern));
    SkipTable(pattern, skip);
    
    int textSize = strlen(text);
    int patternSize = strlen(pattern);
    int pp = 0;

    for(int tp = 0; tp < textSize; tp++){
        while(pp > 0 && text[tp] != pattern[pp]){
            pp = skip[pp-1];
        }

        if(text[tp] == pattern[pp]){
            if(pp == patternSize - 1) return tp - pp + 1;
            else pp++;
        }
    }

    return -1;
}

int main(){
    char txt[256]; //텍스트
    char pat[256]; //패턴
    
    puts("Search by KMP");
    printf("텍스트:");
    scanf("%s", txt);
    printf("패턴:");
    scanf("%s", pat);

    KMP(txt, pat);

    int idx = KMP(txt, pat);
    
    if(idx == -1){
        puts("패턴이 없습니다");
    }else{
        printf("%d번째 위치 부터 패턴과 일치합니다.\n", idx);
    }

    return 0;

}
