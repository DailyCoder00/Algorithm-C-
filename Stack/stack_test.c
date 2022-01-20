#include<stdio.h>
#include "stack.h"

int main(){
    IntStack s;
    int max;
    printf("스택의 용량 입력:");
    scanf("%d", &max);
    if(Initialize(&s, max) == -1){
        printf("스택 생성에 실패하였습니다.\n");
        return 0;
    }

    while(1){
        int menu, x;
        printf("현재 데이터 수:%d/%d\n", Size(&s), Capacity(&s));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료:");
        scanf("%d",&menu);

        switch (menu)
        {
        case 1:
            printf("데이터:");
            scanf("%d", &x);
            if(Push(&s, x) == -1)
                printf("푸시 실패\n");
            else
                printf("푸시 성공\n");
            break;
        
        case 2:
            if(Pop(&s, &x) == -1)
                printf("팝 실패\n");
            else
                printf("팝 데이터: %d\n", x);
            break;
        case 3:
            if(Peek(&s, &x) == -1)
                printf("피크 실패\n");
            else
                printf("피크 데이터:%d\n", x);
            break;
        case 4:
            Print(&s);
            break;
        case 0:
            Terminate(&s);
            return 0;
        default:
            break;
        }
    }
}