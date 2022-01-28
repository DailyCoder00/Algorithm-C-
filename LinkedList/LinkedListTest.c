#include <stdio.h>   
#include "LinkedList.h"
#include "Member.h"

//메뉴

//메뉴 선택 함수
int SelectMenu(void)
{
	int mainMenu;
    int subMenu = 0;

    do{
        puts("[LinkedList 자료구조]");
        printf("(1) 노드 삽입 (2) 노드 삭제 (3) 노드 출력 (4) 검색 (0) 종료 : ");
        scanf("%d", &mainMenu);
        
    }while(mainMenu < 0 || mainMenu > 4); //잘못 입력한 경우 반복

    switch (mainMenu){
    case 1: //노드 추가
        do{
            printf("(1) 머리 (2) 꼬리 (3) 임의 지정 : ");
            scanf("%d", &subMenu);
        }while(subMenu < 1 || subMenu > 3); //잘못 입력한 경우 반복
        break;

    case 2: //노드 삭제
        do{
            printf("(1) 머리 (2) 꼬리 (3) 현재 노드 (4) 모든 노드: ");
            scanf("%d", &subMenu);
        }while(subMenu < 1 || subMenu > 4); //잘못 입력한 경우 반복
        break;

    case 3: //노드 출력
        do{
            printf("(1) 현재 노드 (2) 모든 노드 : ");
            scanf("%d", &subMenu);
        }while(subMenu < 1 || subMenu > 2); //잘못 입력한 경우 반복
        break;

    case 4: //노드 검색
        do{
            printf("(1) 번호 입력 (2) 이름 입력 : ");
            scanf("%d", &subMenu);
        }while(subMenu < 1 || subMenu > 2); //잘못 입력한 경우 반복
        break;

    default:
        break;

    }

    return (mainMenu*10)+subMenu;
}


int main(void){
    int menu;
	List list; //LinkedList
	Initialize(&list); //선형 리스트를 초기화

	do {
		Member x; //회원 데이터
		menu = SelectMenu(); //메뉴 선택
        int key;

		switch (menu) {
		case 11: //머리에 노드 삽입
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		
		case 12: //꼬리에 노드 삽입
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

        case 13:
            printf("입력된 번호 앞에 노드가 삽입됩니다.\n");
            printf("번호 입력 : ");
            scanf("%d", &key);
            x = ScanMember("임의위치에 삽입", MEMBER_NO | MEMBER_NAME);
            if(InsertAnywhere(&list,key,&x) == NULL){
                printf("삽입에 실패했습니다.\n");
            }
            break;

		case 21: //머리 노드를 삭제
			RemoveFront(&list);
			break;

		case 22: //꼬리 노드를 삭제
			RemoveRear(&list);
			break;

		case 23: //현재 노드를 삭제
			RemoveCurrent(&list);
			break;
        
        case 24: //모든 노드를 삭제 
			Clear(&list);
			break;

		case 31: //선택한 노드의 데이터를 출력
			PrintCurrent(&list);
			break;

        case 32: //모든 노드의 데이터를 출력
			Print(&list);
			break;

		case 41: //번호로 검색
			x = ScanMember("검색", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;
		
		case 42: //이름으로 검색
			x = ScanMember("검색", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;
		
		case 0: //노드 종료
			Terminate(&list);
			break;
		}

		printf("\n");

	} while (menu != 0);
	
	return 0;
}