#ifndef __ArrayLinkedList
#define __ArrayLinkedList

#include "Member.h"
typedef int Index;
#define Null -1


typedef struct{
    Member data; //데이터
    Index next; //다음 노드
    Index dnext; //프리 리스트의 다음노드
}Node;

typedef struct{
    Node *n; //리스트 배열
    Index head; //head
    Index crnt; //현재노드
    Index max; //꼬리 레코드
    Index deleted; //프리 리스트의 head
}List;

void Initialize(List *list, Index size);

Index search(List *list, const Member *d, int compare(const Member *x, const Member *y));

void InsertFront(List *list, const Member *d);

void InsertRear(List *list, const Member *d);

void RemoveFront(List *list);

void RemoveRear(List *list);

void RemoveCurrent(List *list);

void Clear(List *list);

//현재 노드 출력
void PrintCurrent(const List *list);

//현재 노드 출력(줄바꿈)
void PrintLnCurrent(const List *list);

//모든 노드 출력
void Print(const List *list);

//노드 종료
void Terminate(List *list);

#endif