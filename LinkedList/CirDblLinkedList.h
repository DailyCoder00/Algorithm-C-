//CircleDoubleLinkedList 헤더파일

#ifndef __CircleDoubleLinkedList
#define __CircleDoubleLinkedList

#include "Member.h"

//노드
typedef struct __Dnode{
    Member data; //데이터
    struct __Dnode *prev; //이전 노드
    struct __Dnode *next; //다음 노드
}Dnode;

//노드를 관리하는 리스트
typedef struct __List{
    Dnode *head; //머리노드
    Dnode *crnt; //현재 노드
}List;

//노드가 텅 비었는지 확인
int IsEmpty(List *list);

//노드 초기화(더미노드 생성) -> head가 더미노드를 가르킴
void Initialize(List *list);

//노드 검색
Dnode *search(List *list, Member *newdata, int compare(const Member *x, const Member *y));

//현재 노드 출력(줄바꿈 없음)
void PrintCurrent(List *list);

//현재 노드 출력(줄바꿈)
void PrintLnCurrent(List *list);

//모든 노드 출력
void Print(List *list);

//모든 노드 역순으로 출력
void PrintReverse(List *list);

//현재노드의 다음노드 선택
int Next(List *list);

//현재노드의 이전노드 선택
int Prev(List *list);

//노드 p 다음 노드 추가
void InsertAfter(List *list, Dnode *p, const Member *newdata);

//머리에 노드 추가
void InsertFront(List *list, Member *newdata);

//꼬리에 노드 추가
void InsertRear(List *list, Member *newdata);

//노드 p 삭제
void Remove(List *list, Dnode *p);

//머리노드 삭제
void RemoveFront(List *list);

//꼬리 노드 삭제
void RemoveRear(List *list);

//현재 노드 삭제
void RemoveCurrent(List *list);

//더미노드를 제외한 모든 노드 삭제
void Clear(List *list);

//노드 종료
void Terminate(List *list);

#endif