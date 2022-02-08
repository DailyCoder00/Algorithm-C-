#include<stdio.h>

int count=0;

void hanoi(int n, char start, char temp, char goal){
    if(n == 1){
        printf("1 원반 %c -> %c\n", start, goal);
        count++;
    }else{
        hanoi(n-1,start,goal,temp);
        printf("%d 원반 %c -> %c\n",n, start, goal);
        count++;
        hanoi(n-1, temp,start,goal);
    }
}

int main(){
    int n;
    printf("원반 수:");
    scanf("%d", &n);
    hanoi(n,'a','b','c');
    printf("원판 이동 횟수:%d", count);
}