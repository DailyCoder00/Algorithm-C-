#include<stdio.h>
#include "bit_set.h"

int IsMember(BitSet s, int n){
    return s & SetOf(n);
}

void Add(BitSet *s, int n){
    *s |= SetOf(n);
}

void Remove(BitSet *s, int n){
    *s &= ~SetOf(n);
}

int Size(BitSet s){
    int n = 0;;
    for(; s != BitSetNULL; n++){
        s &= s - 1;
    }

    return n;
}

void Print(BitSet s){
    printf("{");
    for(int i = 0; i < BitSetBits; i++){
        if(IsMember(s,i)){
            printf("%d ",i);
        }
    }
    printf("}");
}

void PrintLn(BitSet s){
    Print(s);
    putchar('\n');
}

int Equal(BitSet s1, BitSet s2){
    return s1 == s2;
}

int Union(BitSet s1, BitSet s2){
    return s1 | s2;
}

int Intersection(BitSet s1, BitSet s2){
    return s1 & s2;
}

int Difference(BitSet s1, BitSet s2){
    return s1 & (~s2);
}


