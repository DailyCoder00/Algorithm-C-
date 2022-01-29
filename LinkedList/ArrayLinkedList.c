#include<stdio.h>
#include<stdlib.h>
#include "ArrayLinkedList.h"
#include "Member.h"

static Index GetIndex(List *list){
    if(list->deleted == Null){
        return ++(list->max);
    }else{
        Index rec = list->deleted;
        list->deleted = list->n[rec].dnext;
        return rec;
    }
}

static void DeleteIndex(List *list, Index idx)
{
	if (list->deleted == Null) {       /* 삭제할 레코드가 없는 경우 */
		list->deleted = idx;
		list->n[idx].dnext = Null;
	}
	else {
		Index ptr = list->deleted;
		list->deleted = idx;
		list->n[idx].dnext = ptr;
	}
}

static void SetNode(Node *n, const Member *d, Index next){
    n->data = *d;
    n->next = next;
}

void Initialize(List *list, Index size){
    list->n = calloc(size, sizeof(Node));
    list->max = Null;
    list->head = Null;
    list->crnt = Null;
    list->deleted = Null;
}

Index search(List *list, const Member *d, int compare(const Member *x, const Member *y)){
    Index ptr = list->head;
    while(ptr != Null){
        if(compare(&list->n[ptr].data, d) == 0){
            list->crnt = ptr;
            return ptr;
        }
        ptr = list->n[ptr].next;
    }

    return Null;
}

void InsertFront(List *list, const Member *d){
    list->crnt = GetIndex(list);
    SetNode(&list->n[list->crnt], d, list->head);
    list->head = list->crnt;
}

void InsertRear(List *list, const Member *d){
    if(list->head == Null) InsertFront(list, d);
    else{
        Index ptr = list->head;
        while(list->n[ptr].next != Null){
            ptr = list->n[ptr].next;
        }
        list->crnt = GetIndex(list);
        list->n[ptr].next = list->crnt;
        SetNode(&list->n[list->crnt], d, Null);
    }
}

void RemoveFront(List *list){
    if(list->head != Null){
        list->crnt = list->n[list->head].next;
        DeleteIndex(list, list->head);
        list->head = list->crnt;
    }
}

void RemoveRear(List *list){
    if(list->head != Null){
        if(list->n[list->head].next == Null){
            RemoveFront(list);
        }else{
            Index ptr = list->head;
            Index pre;
            while(list->n[ptr].next != Null){
                pre = ptr;
                ptr = list->n[ptr].next;
            }
            list->crnt = pre;
            list->n[list->crnt].next = Null;
            DeleteIndex(list, ptr);
        }
    }
}

void RemoveCurrent(List *list){
    if(list->head != Null){
        if(list->head == list->crnt){
            RemoveFront(list);
        }else{
            Index ptr = list->head;
            while(list->n[ptr].next != list->crnt){
                ptr = list->n[ptr].next;
            }
            list->n[ptr].next = list->n[list->crnt].next;
            DeleteIndex(list, list->crnt);
            list->crnt = ptr;
        }
    }
}

void Clear(List *list){
    while(list->head != Null){
        RemoveFront(list);
    }
    list->crnt = Null;
}

//현재 노드 출력
void PrintCurrent(const List *list){
	if (list->crnt == Null)
		printf("주목노드가 없습니다.");
	else
		PrintMember(&list->n[list->crnt].data);
}

//현재 노드 출력(줄바꿈)
void PrintLnCurrent(const List *list){
	PrintCurrent(list);
	putchar('\n');
}

//모든 노드 출력
void Print(const List *list){
	if (list->head == Null)
		puts("노드가 없습니다.");
	else {
		Index ptr = list->head;
		puts("【 모두 보기 】");
		while (ptr != Null) {
			PrintLnMember(&list->n[ptr].data);
			ptr = list->n[ptr].next;              
		}
	}
}

//노드 종료
void Terminate(List *list){
	Clear(list); 
	free(list->n);
}
