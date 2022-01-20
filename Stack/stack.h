#include "stack_data.h"

int Initialize(IntStack *s, int max);

int Push(IntStack *s, int x);

int Pop(IntStack *s, int *x);

int Peek(IntStack *s, int *x);

void Clear(IntStack *s);

int Capacity(IntStack *s);

int Size(IntStack *s);

int IsEmpty(IntStack *s);

int IsFull(IntStack *s);

int Search(IntStack *s, int x);

void Print(IntStack *s);

void Terminate(IntStack *s);