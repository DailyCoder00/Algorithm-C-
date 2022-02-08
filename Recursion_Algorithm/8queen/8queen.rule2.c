//8queen
//[규칙 2] 각 행에 퀸을 1개만 배치한다.
//퀸 배치의 중복을 막기위해 분기한정법 사용(flag배열을 통해 중복여부 체크)

#include<stdio.h>

int n = 8;
int pos[8]; //체스를 배치할 배열
int flag[8]; //퀸 가로열 중복체크

void set(int i){
	if(i == n){
		for(int temp = 0; temp < 8; temp++){ //규칙 1과 2를 모두 만족하는 결과 출력
			printf("%d ", pos[temp]);
		}
		printf("\n");
	}else{
		for(int temp = 0; temp < 8; temp++){ 
			if(!flag[temp]){ //놓을려는 가로열에 다른 퀸이 있는지 확인
				pos[i] = temp;
				flag[temp] = 1; //가로줄에 퀸을 놓았으므로 참으로 변경
				set(i+1);
				flag[temp] = 0; //이에 해당하는 경우를 출력했으므로 거짓으로 변경
			}
			
		}
	}
}
int main(){
	set(0); //퀸을 배치하는 함수
}