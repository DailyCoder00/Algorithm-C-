#ifndef __LinkedList
#define __LinkedList

#include "Member.h"

//Node
typedef struct __Node{
    Member data; //노드 데이터
    struct __Node *next; //다음 노드
}Node;

//List
typedef struct __List{
    Node *head; //head 노드
    Node *crnt; //현재 노드
    int max;
}List;

//새로운 노드에 멤버값 설정
static void SetNode(Node *newNode, Member *data, Node *next);

//노드 동적 할당
static Node *AllocNode();

//노드 초기화
void Initialize(List *list);

//머리노드 추가
void InsertFront(List *list, Member *d);

//꼬리노드 추가
void InsertRear(List *list, Member *d);

//임의 위치에 노드 추가
Node *InsertAnywhere(List *list, int key, Member *d);

//머리노드 삭제
void RemoveFront(List *list);

//꼬리노드 삭제
void RemoveRear(List *list);

//현재노드 삭제
void RemoveCurrent(List *list);

//노드 검색
Node *search(List *list, Member *key, int compare(const Member *x, const Member *y));

//노드 삭제
void Clear(List *list);

//현재 노드 출력
void PrintCurrent(List* list);

 //현재 노드 출력(줄바꿈)
void PrintLnCurrent(List *list);

//모든 노드 출력
void Print(List *list);

//포인터 형태로 출력
void PrintPointer(List *list);

//LinkedList 종료
void Terminate(List *list);

#endif