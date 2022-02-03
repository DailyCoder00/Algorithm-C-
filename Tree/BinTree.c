#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

//노드 생성
BinNode *AllocBinNode(){
    return calloc(1, sizeof(BinNode));
}

//노드 멤버값 설정
void SetBinNode(BinNode *newNode, const Data *d, BinNode *left_child, BinNode *right_child){
    newNode->data = *d;
    newNode->left = left_child;
    newNode->left = right_child;
}

Data ScanMember(const char *message, int sw){
	Data temp;
	printf("%s하는 데이터를 입력하세요.\n", message);
	if (sw & MEMBER_NO) { printf("번호 : "); scanf("%d", &temp.num); }
	if (sw & MEMBER_NAME) { printf("이름 : "); scanf("%s", temp.name); }
	return temp;
}

//멤버 번호 비교
int CompareMember(const Data *x, const Data *y){
    return (x->num) - (y->num);
}

//멤버 검색
BinNode *Search(BinNode *parent, const Data *d){
    int cmp;
    if(parent == NULL){
        printf("%d와 같은 값이 존재하지 않습니다", d->num);
        return NULL;
    }else if((cmp = CompareMember(d, &parent->data)) == 0){
        return parent;
    }else if(cmp > 0){
        return Search(parent->right, d);
    }else{
        return Search(parent->left, d);
    }
}

//가장작은 멤버 반환
BinNode *SearchMin(BinNode *parent){
    BinNode *minNode = parent;
    while(minNode->left != NULL){
        minNode = minNode->left;
    }

    return minNode;
    
}

//노드 추가
BinNode *Add(BinNode *parent, const Data *d){
    int cmp;
    if(parent == NULL){
        parent = AllocBinNode();
        SetBinNode(parent, d, NULL, NULL);
    }else if((cmp = CompareMember(d, &parent->data)) == 0){
        printf("%d와 같은 값을 가진 노드가 존재합니다.\n", d->num);
    }else if(cmp > 0){
        parent->right = Add(parent->right, d);
    }else{
        parent->left = Add(parent->left, d);
    }

    return parent;
}

//노드 삭제
BinNode *Remove(BinNode *parent, const Data *d){
    int cmp;
    BinNode *nextNode;
    
    //삭제 대상을 찾는 부분
    if(parent == NULL){
        printf("%d와 같은 값이 존재하지 않습니다", d->num);
        return parent;

    }else if((cmp = CompareMember(d, &parent->data)) > 0){
        parent->right = Remove(parent->right, d);

    }else if(cmp < 0){
        parent->left = Remove(parent->left, d);

    }else{
        //삭제 대상을 삭제하는 부분
        if(parent->left != NULL && parent->right != NULL){
            nextNode = SearchMin(parent->right);
            parent->data = nextNode->data;
            parent->right = Remove(parent->right, &nextNode->data);

        }else if(parent->left == NULL){
            nextNode = parent->right;
            free(parent);
            return nextNode;

        }else{
            nextNode = parent->left;
            free(parent);
            return nextNode;
        }
        
    }

    return parent;
}

//멤버 출력
void PrintMember(BinNode *node){
    printf("[%d] %s", node->data.num, node->data.name);
}

//멤버 출력(줄바꿈)
void PrintLnMember(BinNode *node){
    PrintMember(node);
    putchar('\n');
}

//모든 노드 출력
void PrintTree(BinNode *root){
    if(root != NULL){
        PrintTree(root->left);
        PrintLnMember(root);
        PrintTree(root->right);
    }
}

//모든 노드 삭제
void Terminate(BinNode *root){
    if(root != NULL){
        Terminate(root->left);
        Terminate(root->right);
        free(root);
    }
}