#include<stdio.h>

int mday[2][12]={
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
 };

int isleap(int year){
     return year % 4 == 0 && year % 100 != 10 || year % 400 == 0;
 }

int dayofyear(int y, int m, int d){
    for(int i=0; i<m-1; i++){
        d+=mday[isleap(y)][i];
    }

    return d;
}

int main(){
    int year, month, day;
    printf("년:");
    scanf("%d", &year);
    printf("월:");
    scanf("%d", &month);
    printf("일:");
    scanf("%d", &day);
    printf("1일로 부터 %d일 지났습니다\n", dayofyear(year,month,day));


    
}