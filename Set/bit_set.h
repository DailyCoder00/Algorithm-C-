#include "bit_set_data.h"

int IsMember(BitSet s, int n);

void Add(BitSet *s, int n);

void Remove(BitSet *s, int n);

int Size(BitSet s);

void Print(BitSet s);

void PrintLn(BitSet s);

int Equal(BitSet s1, BitSet s2);

int Union(BitSet s1, BitSet s2);

int Intersection(BitSet s1, BitSet s2);

int Difference(BitSet s1, BitSet s2);