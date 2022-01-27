#ifndef __LinkedList
#define __LinkedList
#include "Member.h"

//노드
typedef struct __Node
{
    struct __Node *next; //다음 노드
    Member data; //데이터
}Node;

//리스트
typedef struct 
{
    Node *head; //머리노드에 대한 포인터
    Node *crnt; //현재 노드
}List;

//head 및 현재 노드 초기화
void Initialize(List *list);

//멤버 선형 검색 함수
Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y));

//머리노트 앞에 새로는 노드 생성
void InsertFront(List *list, const Member *x);

//꼬리노드 뒤에 새로운 노드 생성
void InsertRear(List *list, const Member *x);

//머리노드 삭제
void RemoveFront(List *list);

//꼬리 노드 삭제
void RemoveRear(List *list);

//현재 노드 삭제
void RemoveCurrent(List *list);

//모든 노드 삭제
void Clear(List *list);

//현재 노드 출력
void PrintCurrent(List* list);

 //현재 노드 출력(줄바꿈)
void PrintLnCurrent(List *list);

//모든 노드 출력
void Print(List *list);

//LinkedList 종료
void Terminate(List *list);

#endif

