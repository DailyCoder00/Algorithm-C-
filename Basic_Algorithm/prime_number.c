#include<stdio.h>
#include<math.h>

int main(){
    int prime[500];
    int ptr = 0;
    int flag = 0;
    prime[ptr++] = 2;
    prime[ptr++] = 3;
    
    for(int n=5; n<=1000; n=n+2){
        for(int i=2; i<=(int)sqrt(n); i++){
            flag = 0;
            if(n%i == 0){
                flag = 1;
                break;
            }
        }
        if(!flag){
            prime[ptr++] = n;
        }
    }

    for(int i = 0; i<ptr; i++){
        printf("%d\n", prime[i]);
    }

}