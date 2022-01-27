#include <stdio.h>   
#include "LinkedList.h"

//메뉴
typedef enum {
	TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
	RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

//메뉴 선택 함수
Menu SelectMenu(void)
{
	int ch;
	
	do{
	printf("(1)머리에 노드 삽입  (2)꼬리에 노드를 삽입  (3)머리 노드를 삭제\n");
	printf("(4)꼬리 노드를 삭제  (5)선택한 노드를 출력  (6)선택한 노드를 삭제\n");
	printf("(7)번호로 검색       (8)이름으로 검색       (9)모든 노드를 출력\n");
	printf("(10)모든 노드를 삭제 (0) 종료 : ");
	scanf("%d", &ch);
	}while(ch < 0 || ch > 10);

	return (Menu)ch;
}


int main(void)
{
	Menu menu; //열거형 메뉴
	List list; //LinkedList
	Initialize(&list); //선형 리스트를 초기화

	do {
		Member x; //회원 데이터
		menu = SelectMenu(); //메뉴 선택

		switch (menu) {
		case INS_FRONT: //머리에 노드 삽입
			x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertFront(&list, &x);
			break;
		
		case INS_REAR: //꼬리에 노드 삽입
			x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
			InsertRear(&list, &x);
			break;

		case RMV_FRONT: //머리 노드를 삭제
			RemoveFront(&list);
			break;

		case RMV_REAR: //꼬리 노드를 삭제
			RemoveRear(&list);
			break;

		case PRINT_CRNT: //선택한 노드의 데이터를 출력
			PrintCurrent(&list);
			break;

		case RMV_CRNT: //선택한 노드를 삭제
			RemoveCurrent(&list);
			break;

		case SRCH_NO: //번호로 검색
			x = ScanMember("검색", MEMBER_NO);
			if (search(&list, &x, MemberNoCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 번호의 데이터가 없습니다.");
			break;
		
		case SRCH_NAME: //이름으로 검색
			x = ScanMember("검색", MEMBER_NAME);
			if (search(&list, &x, MemberNameCmp) != NULL)
				PrintLnCurrent(&list);
			else
				puts("그 이름의 데이터가 없습니다.");
			break;
		
		case PRINT_ALL: //모든 노드의 데이터를 출력
			Print(&list);
			break;

		case CLEAR: //모든 노드를 삭제 
			Clear(&list);
			break;

		case TERMINATE: //노드 종료
			Terminate(&list);
			break;
		}

		printf("\n----------------------------------------------------------\n\n");

	} while (menu != TERMINATE);
	
	return 0;
}