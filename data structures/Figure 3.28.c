#include<stdio.h>
#include<stdlib.h>
#define SpaceSize 10
/*Figure 3.28 Declarations for cuisor implementation of linked lists*/
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List MakeEmpty(List L);
int IsEmpty(const List L);
int IsLast(const Position P,const List L);
Position Find(int X,const List L);
void Delete(int X,List L);
Position FindPrevious(int X,const List L);
void Insert(int X,List L,Position P);
void DeleteList(List L);
Position Header(const List L);
Position First(const List L);
Position Advance(const Position P);
int Retrieve(const Position P);

/*Place int the implementation file*/
struct Node{
	int Element;
	Position Next;
};
struct Node CursorSpace[SpaceSize];//结构数组

/*Figure 3.30 Routines: CuisorAlloc and CursorFree
不懂什么意思？*/
static Position CursorAlloc(void){
	Position P;
	P=CursorSpace[0].Next;
	CursorSpace[0].Next=CursorSpace[P].Next;
	return P;
}
static void CursorFree(Position P){
	CursorSpace[P].Next=CursorSpace[0].Next;
	CursorSpace[0].Next=P;
}

/*Figure 3.32 Function to test whether a linked list is empty-cursor implementation
Return true if L is empty*/
int IsEmpty(List L){
	return CursorSpace[L].Next==0;
}

/*Figure 3.33 Function to test whether P is last in a linked list-cursor implementation
return true if P is the last position in List L
Parameter L is unused in this implementation*/
int IsLast(Position P,List L){
	return CursorSpace[P].Next==0;
}

/*Figure 3.34 Find routine-cuisor implementation
Return Position of X in L; 0 if not found
Uses a header node*/
Position Find(int X,List L){
	Position P;
	P=CursorSpace[0].Next;//Uses a header node，这句让P成为第一个元素；
	while(P&&CursorSpace[P].Element==X){//while(P)的意思是：当P不为0时，等价于不等于NULL
		P=CursorSpace[P].Next;
	}
	return P;//当没找到时，P=0;
}

/*Figure 3.35 Deletion roution for linked lists-cursor implemention
Delete first occurrence of X from a list
Assume use of a header node*/
void Delete(int X,List L){
	Position P,TmpCell;
	P=FindPrevious(X,L);
	if(!IsLast(P,L)){//Assumption of header use
		TmpCell=CursorSpace[P].Next;
		CursorSpace[P].Next=CursorSpace[TmpCell].Next;
		CuisorFree(TmpCell);
	}
}

/*Figure 3.36 Insertion routine for linked lists-cursor implementation
Insert(after legal position P)
Header implementation assumed
Parameter L is unused in this implementetion*/
void Insertion(int X,List L,Position P){
	Position TmpCell;
	TmpCell=CursorAlloc();
	if(TmpCell==0) printf("Out of Space.\n");
	CursorSpace[TmpCell].Element=X;
	CursorSpace[TmpCell].Next=CursorSpace[P].Next;
	CursorSpace[P].Next=TmpCell;
}


