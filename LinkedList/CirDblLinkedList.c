//CircleDoubleLinkedList 함수 정의 파일

#include<stdio.h>
#include<stdlib.h>
#include "CirDblLinkedList.h"
#include "Member.h"

//새로운 노드 동적할당
static Dnode *AllocNode(){
    return calloc(1,sizeof(Dnode));
}

//새로운 노드에 대한 멤버 값 설정
static void SetNode(Dnode *newNode, const Member *newdata, Dnode *prev, Dnode *next){
    newNode->data = *newdata;
    newNode->next = next;
    newNode->prev = prev;
}

//노드가 텅 비었는지 확인
int IsEmpty(List *list){
    return list->head->next == list->head;
}

//노드 초기화(더미노드 생성) -> head가 더미노드를 가르킴
void Initialize(List *list){
    Dnode *dummyNode = AllocNode();
    list->crnt = list->head = dummyNode;
    dummyNode->prev = dummyNode->next = dummyNode;
}

//노드 검색
Dnode *search(List *list, Member *newdata, int compare(const Member *x, const   Member *y)){
    Dnode *ptr = list->head->next;
    while(ptr != list->head){
        if(compare(newdata, &ptr->data) == 0){ //검색 성공
            list->crnt = ptr; 
            return ptr;
        }
        ptr = ptr->next;
    }

    return NULL; //검색 실패

}

//현재 노드 출력(줄바꿈 없음)
void PrintCurrent(List *list){
    if(IsEmpty(list)){
        printf("노드가 비었습니다.");
    }else{
        PrintMember(&list->crnt->data);
    }
}

//현재 노드 출력(줄바꿈)
void PrintLnCurrent(List *list){
    PrintCurrent(list);
    putchar('\n');
}

//모든 노드 출력
void Print(List *list){
    if(IsEmpty(list)){
        printf("노드가 비었습니다.");
    }else{
        Dnode *ptr = list->head->next;
        while(ptr != list->head){
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }      
}

//모든 노드 역순으로 출력
void PrintReverse(List *list){
    if(IsEmpty(list)){
        printf("출력할 노드가 없습니다.");
    }else{
        Dnode *ptr = list->head->prev;
        while(ptr != list->head){
            PrintLnMember(&ptr->data);
            ptr = ptr->prev;
        }
    }
}

//현재노드의 다음노드 선택
int Next(List *list){
    if(IsEmpty(list) || list->crnt->next == list->crnt){
        return 0;
    }else{
        list->crnt = list->crnt->next;
        return 1;
    }
}

//현재노드의 이전노드 선택
int Prev(List *list){
    if(IsEmpty(list) || list->crnt->prev == list->head){
        return 0;
    }else{
        list->crnt = list->crnt->prev;
        return 1;
    }
}

//노드 p 다음 노드 추가
void InsertAfter(List *list, Dnode *p, const Member *newdata){
    list->crnt = AllocNode();
    p->next->prev = list->crnt;
    SetNode(list->crnt, newdata, p, p->next);
    p->next = list->crnt;
}

//머리에 노드 추가
void InsertFront(List *list, Member *newdata){
    InsertAfter(list, list->head, newdata);
}

//꼬리에 노드 추가
void InsertRear(List *list, Member *newdata){
    InsertAfter(list, list->head->prev, newdata);
}

//노드 p 삭제
void Remove(List *list, Dnode *p){
    
    p->prev->next = p->next;
    p->next->prev = p->prev;
    list->crnt= p->prev;
    free(p);
    if(list->crnt == list->head){
        list->crnt = list->crnt->next;
    }
}

//머리노드 삭제
void RemoveFront(List *list){
    if(!IsEmpty(list)){
        Remove(list, list->head->next);
    }
}

//꼬리 노드 삭제
void RemoveRear(List *list){
    if(!IsEmpty(list)){
        Remove(list, list->head->prev);
    }
}

//현재 노드 삭제
void RemoveCurrent(List *list){
    if(list->crnt != list->head){
        Remove(list, list->crnt);
    }
}

//더미노드를 제외한 모든 노드 삭제
void Clear(List *list){
    Dnode *ptr = list->head->next;
    while (ptr != list->head){
        RemoveFront(list);
        ptr = ptr->next;
    }
    list->crnt = list->head;
}

//노드 종료
void Terminate(List *list){
    Clear(list);
    free(list->head);
}