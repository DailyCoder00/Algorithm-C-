//8queen
//[규칙 1] 각 열에 퀸을 1개만 배치한다.
//8*8*8*8*8*8*8*8개의 경우의 수가 있다.

#include<stdio.h>

int n = 8;
int pos[8]; //체스를 배치할 배열

void set(int i){
	if(i == n){
		for(int temp = 0; temp < 8; temp++){ //규칙 1을 만족하는 결과 모두 출력
			printf("%d ", pos[temp]);
		}
		printf("\n");
	}else{
		for(int temp = 0; temp < 8; temp++){ //규칙1에 따라 8^8의 경우의수를 구함
                pos[i] = temp;
				set(i+1);
		}	
	}
	
}

int main(){
	set(0); //퀸을 배치하는 함수
}