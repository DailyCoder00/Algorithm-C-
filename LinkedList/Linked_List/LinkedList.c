#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

//노드 동적 생성
static Node *AllocNode(){ 
    return calloc(1,sizeof(Node));

}

//노드 n의 멤버 초기화
static void SetNode(Node *n, const Member *x, Node *next){
    n->next = next;
    n->data = *x;
}

//head 및 현재 노드 초기화
void Initialize(List *list){
    list->head = NULL;
    list->crnt = NULL;
}

//멤버 선형 검색 함수
Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y)){
    Node *ptr = list->head;
    while(ptr != NULL){
        if(compare(&ptr->data, x) == 0){
            list->crnt = ptr;
            return ptr; //key를 찾음(찾은 노드의 주소 값 반환)
        }
        ptr = ptr->next;
    }
    return NULL; //찾지 못함(NULL값 반환)

}

//머리노트 앞에 새로는 노드 생성
void InsertFront(List *list, const Member *x){
    Node *ptr = list->head; //임시 변수 ptr에 현재 머리노드(Noda A)의 주소를 할당
    list->crnt = AllocNode(); //새로운 노드(Node B)를 동적할당
    list->head = list->crnt; //head가 새로 생성한 노드(Node B)를 가르키도록 설정
    SetNode(list->head, x, ptr); //새로 생성한 노드(Node B)의 멤버 설정
}

//꼬리노드 뒤에 새로운 노드 생성
void InsertRear(List *list, const Member *x){
    if(list->head == NULL){ //노드가 없을 경우
        InsertFront(list, x); //headd에 노드 삽입
    }else{
        Node *ptr = list->head;
        while(ptr->next != NULL){ //꼬리 노드를 찾는 조건문
            ptr = ptr->next;
        }

        list->crnt = AllocNode(); 
        ptr->next = list->crnt;
        SetNode(list->crnt, x, NULL);
    }
}

//머리노드 삭제
void RemoveFront(List *list){
    if(list->head != NULL){
        Node *ptr = list->head->next;
        free(list->head);
        list->crnt = ptr;
        list->head = list->crnt;
    }
}

//꼬리 노드 삭제
void RemoveRear(List *list){
    if(list->head != NULL){
        if(list->head->next == NULL){ //노드가 하나일 경우
            RemoveFront(list);
        }else{ //노드가 2개 이상일 경우
            Node *ptr = list->head; //꼬리노드
            Node *pre; //꼬리 이전 노드
            while(ptr->next != NULL){ //꼬리노드를 찾을 때까지 반복
                pre = ptr; 
                ptr = ptr->next;
            }
            pre->next = NULL;
            free(ptr);
            list->crnt = pre;
        }
    }
}

//현재 노드 삭제
void RemoveCurrent(List *list){
    if(list->head != NULL){
        if(list->crnt == list->head){ 
            RemoveFront(list);
        } 
        else{
            Node *ptr = list->head; //crnt 이전 노드
            while(ptr->next != list->crnt){ //crnt 이전 노드를 찾을 때까지
                ptr = ptr->next; 
            }
            ptr->next = list->crnt->next; //crnt 이전노드가 crnt 다음노드를 가르키도록 설정
            free(list->crnt); //현재 노드 삭제
            list->crnt = ptr; //ptr을 현재노드로 변경
        }
    }
}

//모든 노드 삭제
void Clear(List *list){
    while(list->head != NULL){
        RemoveFront(list); //앞에서 부터 순서대로 삭제
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