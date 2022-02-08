//8queen
//[규칙 3] 퀸은 대각선으로 공격이 가능하다.
//[규칙 2]와 같이 분기한정법 사용(flag_b와 flag_c배열을 통해 중복확인)

//8queen의 모든조건을 만족시키는 알고리즘

#include<stdio.h>

int n = 8;
int pos[8]; //체스를 배치할 배열
int flag_a[8]; //퀸 가로열 중복여부 체크
int flag_b[15]; //퀸 (/)형태 대각선 중복여부 체크
int flag_c[15]; //퀸 (\)형태 대각선 중복여부 체크
int count = 0; //경우의 수 카운트

void set(int i){
	if(i == n){
		for(int temp = 0; temp < 8; temp++){ //모든 규칙을 만족하는 결과 출력
			printf("%d ", pos[temp]);
		}
		printf("\n");
        count++;
	}else{
		for(int temp = 0; temp < 8; temp++){
			if(!flag_a[temp] && !flag_b[i+temp] && !flag_c[7+i-temp]){ //가로열과 대각선의 중복여부 체크
				pos[i] = temp;
				flag_a[temp] = 1;
                flag_b[i+temp] = 1;
                flag_c[7+i-temp] = 1;
				set(i+1);
				flag_a[temp] = 0;
                flag_b[i+temp] = 0;
                flag_c[7+i-temp] = 0;
			}
			
		}
	}
}
int main(){
	set(0); //퀸을 배치하는 함수
    printf("경우의 수:%d\n", count);
}