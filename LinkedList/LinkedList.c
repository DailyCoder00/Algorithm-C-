#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"
#include "Member.h"

//새로운 노드에 멤버값 설정
static void SetNode(Node *newNode, Member *data, Node *next){
    newNode->data = *data;
    newNode->next = next;
}

//노드 동적 할당
static Node *AllocNode(){
    return calloc(1,sizeof(Node));
}

//노드 초기화
void Initialize(List *list){
    list->head = NULL;
    list->crnt = NULL;
}

//머리노드 추가
void InsertFront(List *list, Member *d){
    Node *ptr = list->head; //노드 A를 ptr에 담는다
    list->crnt = AllocNode(); //새로운 노드 B 생성
    list->head = list->crnt; //새로운 노드 B를 head에 담는다
    SetNode(list->crnt, d, ptr); //새로운 노드에 멤버값(노드 B, data x) 할당
}

//꼬리노드 추가
void InsertRear(List *list, Member *d){
    if(list->head == NULL) InsertFront(list, d);
    else{
        Node *ptr = list->head;
        while(ptr->next != NULL){ //꼬리노드 찾기
            ptr = ptr->next;
        }
        list->crnt = AllocNode();
        ptr->next = list->crnt;
        SetNode(list->crnt, d, NULL);
    }
}

//임의 위치에 노드 추가
Node *InsertAnywhere(List *list, int key, Member *d){
    if(list->head != NULL){ //노드가 비어있지 않으면
        if(list->head->data.no == key){ //첫번째 노드가 key일 경우
            InsertFront(list,d);
            return list->crnt;
        }else{ //노드가 2개 이상
            Node *ptr = list->head;
            while(ptr != NULL){
                if(ptr->next->data.no == key){
                    list->crnt = AllocNode(); //새로운 노드 생성
                    SetNode(list->crnt,d,ptr->next); //새로운 노드의 멤버 값(d, ptr의 next 포인터) 설정
                    ptr->next = list->crnt; //ptr의 다음 노드를 현재노드로 설정
                    return ptr;
                }
                ptr = ptr->next;
            }
        }
    }

    return NULL; //key가 없거나 노드가 비어있음

}

//머리노드 삭제
void RemoveFront(List *list){
    if(list->head != NULL){
        list->crnt = list->head->next;
        free(list->head);
        list->head = list->crnt;
    }
}

//꼬리노드 삭제
void RemoveRear(List *list){
    if(list->head != NULL){
        if(list->head->next == NULL) RemoveFront(list);
        else{
            Node *ptr = list->head; 
            Node *pre; 
            while(ptr->next != NULL){
                pre = ptr; //꼬리 이전노드
                ptr = ptr->next; //꼬리 노드
            }
            pre->next = NULL;
            free(ptr);
            list->crnt = pre;
        }
    }
}

//현재노드 삭제
void RemoveCurrent(List *list){
    if(list->head != NULL && list->crnt != NULL){
        if(list->head == list->crnt){ //노드가 1개 일 경우
            RemoveFront(list);
        }else{
            Node *ptr = list->head;
            while(ptr->next != list->crnt){
                ptr = ptr->next;
            }
            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;
        }
    }
}

//노드 검색
Node *search(List *list, Member *key, int compare(const Member *x, const Member *y)){
    Node *ptr = list->head;
    while(ptr != NULL){
        if(compare(&ptr->data, key) == 0){
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }    
    return NULL;
}

//노드 삭제
void Clear(List *list){
    while(list->head != NULL){
        RemoveFront(list);
    }
    list->crnt = NULL;
}

//현재 노드 출력
void PrintCurrent(List* list){
    if(list->crnt == NULL){
        printf("선택된 노드가 없습니다");
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
    if(list->head == NULL){
        puts("출력 할 노드가 없습니다");
    }else{
        Node *ptr = list->head;
        while(ptr != NULL){
            PrintLnMember(&ptr->data);
            ptr = ptr->next;
        }
    }
}

//LinkedList 종료
void Terminate(List *list){
    Clear(list);
}
