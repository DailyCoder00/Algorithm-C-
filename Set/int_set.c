#include<stdio.h>
#include<stdlib.h>

typedef struct _IntSet{ //int형 집합 구조체
    int num; //현재 원소 개수
    int max; //최대 원소 개수
    int *set; //원소를 담을 배열
}IntSet;

//집합 구조체 초기화
int Initialize(IntSet *s, int max){ 
    s->num = 0;
    s->set = calloc(max, sizeof(int));
    if(s->set == NULL){ //집합 배열의 동적할당에 실패한 경우
        s->max = 0; //원소를 담을 수 없도록 최대 원소를 0으로 지정
        return -1;
    }

    s->max = max; //동적할당에 성공한 경우 입력받은 max값을 최대 원소 개수로 지정
    return 0;

}

//집합에 해당 원소가 있는가?
int IsMember(IntSet *s, int key){
    for(int i = 0; i < s->num; i++){
        if(s->set[i] == key){
            return 1;
        }
    }

    return -1;
}

//원소 추가
void Add(IntSet *s, int element){
    if(s->num < s->max && IsMember(s, element) == -1){ 
        s->set[s->num++] = element;   
    }
}

//원소 제거
void Remove(IntSet *s, int elemet){
    for(int i = 0; i < s->num; i++){
        if(s->set[i] == elemet){
            s->set[i] = s->set[--s->num];
        }
    }
}

//최대 용량 반환
int Capacity(IntSet *s){
    return s->max;
}

//현재 원소 개수 반환
int Size(IntSet *s){
    return s->num;
}

//집합이 가득 찼는가?
int IsFull(IntSet *s){
    return s->num >= s->max ? 1 : 0;
}

//집합 비우는 함수
void Clear(IntSet *s){
    s->num = 0;
}

//s2에 s1을 복사
void Assign(IntSet *s1, IntSet *s2){
    int size = (s2->num > s1->max) ? s1->max : s2->num;

    for(int i = 0; i < size; i++){
        s1->set[i] = s2->set[i];
    }
    s1->num = size;
}

//s1과 s2가 같은가?
int Equal(IntSet *s1, IntSet *s2){
    if(s1->num == s2->num){
        for(int i = 0; i < s1->num; i++){
            if(IsMember(s2, s1->set[i]) == -1) return 0;
        }
        return 1;
    }
    return 0;
}

//s2와 s3의 합집합을 s1에 대입
IntSet *Union(IntSet *s1, IntSet *s2, IntSet *s3){
    Assign(s1, s2);
    for(int i = 0; i < s3->num; i++){
        Add(s1, s3->set[i]);
    }
    return s1;
}

//s2와 s3의 교집합을 s1에 대입
IntSet *Intersection(IntSet *s1, IntSet *s2, IntSet *s3){
    s1->num = 0;
    for(int i = 0; i < s2->num; i++){
        if(IsMember(s3, s2->set[i]) == 1){
            Add(s1, s2->set[i]);
        }
    }

    return s1;
}

//s2 - s3를 s1에 대입
IntSet *Difference(IntSet *s1, IntSet *s2, IntSet *s3){
    s1->num = 0;
    for(int i = 0; i < s2->num; i++){
        if(IsMember(s3, s2->set[i]) == -1){
            Add(s1, s2->set[i]);
        }
    }

    return s1;
}

//배열의 모든 원소 출력
void Print(IntSet *s){
    printf("{");
    for(int i = 0; i < s->num; i++){
        printf("%d ", s->set[i]);
    }
    printf("}");
}

void PrintLn(IntSet *s){
    Print(s);
    puts(""); 
}

//집합 제거
void Terminate(IntSet *s){
    if(s->set != NULL){
        free(s);
        s->max = s->num = 0;
    }
}

/*
int main(void)
{
	IntSet s1, s2, s3;
	Initialize(&s1, 24);
	Initialize(&s2, 24);
	Initialize(&s3, 24);

	Add(&s1, 10);			
	Add(&s1, 15);			
	Add(&s1, 20);			
	Add(&s1, 25);			

	Assign(&s2, &s1);		
	Add(&s2, 12);
	Remove(&s2, 20);		
	Assign(&s3, &s2);		

	printf("s1 = "); PrintLn(&s1);
	printf("s2 = "); PrintLn(&s2);
	printf("s3 = "); PrintLn(&s3);

	printf("집합 s1에 15가 들어 있%s.\n", IsMember(&s1, 15) > 0 ? "습니다" : "지 않습니다");
	printf("집합 s2에 25가 들어 있%s.\n", IsMember(&s2, 25) > 0 ? "습니다" : "지 않습니다");
	printf("집합 s1과 s2는 서로 같%s.\n", Equal(&s1, &s2) ? "습니다" : "지 않습니다.");
	printf("집합 s2와 s3는 서로 같%s.\n", Equal(&s2, &s3) ? "습니다" : "지 않습니다.");

	Terminate(&s1);
	Terminate(&s2);
	Terminate(&s3);

    return 0;
}
*/

enum { ADD, RMV, SCH };

int scan_data(int sw)
{
	int data;
	
	switch (sw) {
	case ADD: printf("추가할 데이터 : "); break;
	case RMV: printf("삭제할 데이터 : "); break;
	case SCH: printf("검색할 데이터 : "); break;
	}

	scanf("%d", &data);

	return data;
}

int main(void)
{
	IntSet s1, s2, temp;
	
	Initialize(&s1, 512); 
	Initialize(&s2, 512); 
	Initialize(&temp, 512);

	while (1) {
		int m, x, idx;

		printf("s1 = "); PrintLn(&s1);
		printf("s2 = "); PrintLn(&s2);
		printf("(1)s1에 추가 (2) s1에서 삭제 (3) s1에서 검색 (4) s1 <- s2 (5) 여러 연산\n");
        printf("(6)s2에 추가 (7) s2에서 삭제(8) s2에서 검색(9) s2 <- s1 (0) 종료 : ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m) {
		case 1: 
            x = scan_data(ADD); 
            Add(&s1, x); 
            break;

		case 2: 
            x = scan_data(RMV); 
            Remove(&s1, x); 
            break;

		case 3: 
            x = scan_data(SCH); 
            idx = IsMember(&s1, x);
			printf("s1에 들어있%s.\n", idx >= 0 ? "습니다" : "지 않습니다"); 
            break;
            
		case 4: 
            Assign(&s1, &s2); 
            break;

		case 5: 
            printf("s1 == s2 = %s\n", Equal(&s1, &s2) ? "true" : "false");
			printf("s1 & s2 = "); Intersection(&temp, &s1, &s2);
			PrintLn(&temp);
			printf("s1 | s2 = "); Union(&temp, &s1, &s2);
			PrintLn(&temp);
			printf("s1 - s2 = "); Difference(&temp, &s1, &s2);
			PrintLn(&temp);
			break;

		case 6: 
            x = scan_data(ADD); 
            Add(&s2, x); 
            break;

		case 7: 
            x = scan_data(RMV); 
            Remove(&s2, x); 
            break;	

		case 8: 
            x = scan_data(SCH); 
            idx = IsMember(&s2, x);
			printf("s2에 들어있%s.\n", idx >= 0 ? "습니다" : "지 않습니다"); 
            break;

		case 9: 
            Assign(&s2, &s1); 
            break;						
		}
	}

	Terminate(&s1); 
	Terminate(&s2); 
	Terminate(&temp);
	
	return 0;
}