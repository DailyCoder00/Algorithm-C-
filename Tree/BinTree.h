#ifndef __BinTree
#define __BinTree

#define MEMBER_NO 		1 	/* 번호를 나타내는 정수 값 */
#define MEMBER_NAME 	2 	/* 이름을 나타내는 상수 값 */

typedef struct{
    int num;
    char name[100];
}Data;


typedef struct __BinNode{
    Data data;
    struct __BinNode *left;
    struct __BinNode *right;
}BinNode;

//노드 생성
BinNode *AllocBinNode();

//노드 멤버값 설정
void SetBinNode(BinNode *newNode, const Data *d, BinNode *left_child, BinNode *right_child);

//멤버 번호 비교
int CompareMember(const Data *x, const Data *y);

Data ScanMember(const char *message, int sw);

//멤버 검색
BinNode *Search(BinNode *parent, const Data *d);

//가장작은 멤버 반환
BinNode *SearchMin(BinNode *parent);

//노드 추가
BinNode *Add(BinNode *parent, const Data *d);

//노드 삭제
BinNode *Remove(BinNode *parent, const Data *d);

//멤버 출력
void PrintMember(BinNode *node);

//멤버 출력(줄바꿈)
void PrintLnMember(BinNode *node);

//모든 노드 출력
void PrintTree(BinNode *root);

//모든 노드 삭제
void Terminate(BinNode *root);

#endif