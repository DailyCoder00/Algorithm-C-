//기수변환(convert cardinal number)
#include<stdio.h>

int card_convr(unsigned x, int n, char d[]){
    int digits = 0; //자리 수
    char dchar[]= {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; //2~36진수까지의 표현
    while(x){ //각 자리마다의 값을 구함
        d[digits++] = dchar[x%n];
        x = x/n;
    }
    return digits;
    
}

int main(){
    unsigned no; //변환하는 정수
    int cd; //기수
    int dno; //변환 후 자릿수
    char cno[512]; //변환한 값의 각 자리수를 담는 문자배열
    printf("10진수를 기수 변환합니다.\n");
    printf("변환할 자연수:");
    scanf("%u", &no);
    printf("변환할 진수(2~36):");
    scanf("%d", &cd);
    dno = card_convr(no, cd, cno);
    printf("%d진수:",cd);
    for(int i = dno-1; i>=0; i--){ //문자배열에 담긴 각 자리수를 역순으로 출력
        printf("%c", cno[i]);
    }
    printf("\n");


}