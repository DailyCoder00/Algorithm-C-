#ifndef __BIT_SET_DATA
#define __BIT_SET_DATA

typedef unsigned long BitSet;

#define BitSetNULL (BitSet)0
#define BitSetBits 32
#define SetOf(no) ((BitSet)1 << (no))

#endif