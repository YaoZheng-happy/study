#include<stdio.h>
#include<stdlib.h>
/*Figure 3.39 Type declaration for linked list implementation of the stack*/
struct Node;
typedef struct Node *PtrTode;
typedef PtrTode Stack;//结构指针

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X,Stack S);
int Top(Stack S);
void Pop(Stack S);

/*Place in implementation file
Stack implementation is a linked list with a header*/
struct Node{
	int Element;
	PtrTode Next;
};

/*Figure 3.40 Routine to test whether a stack is empty linked list implement*/
int IsEmpty(Stack S){
	return S->Next==NULL;//with a header.
}

/*Figure 3.41 Routine to create an empty stack-linked list implemtatino*/
Stack CreatStack(void){
	Stack S;
	S=malloc(sizeof(struct Node));
	if(S==NULL)printf("Out of space.\n");
	MakeEmpty(S);
	return S;
}

/*Figure 3.42 Routine to push onto a stack-linked list implementation*/
void Pust(int X,Stack S){
	PtrTode TmpCell;
	TmpCell=malloc(sizeof(struct Node));
	if(TmpCell==NULL) printf("Out of space.\n");
	else{//把TmpCell插到S前
		TmpCell->Element=X;
		TmpCell->Next=S->Next;
		S->Next=TmpCell;
	}
}

/*Figure 3.43 Routine to return top element in a stack-linked list implementation*/
int Top(Stack S){
	if(!IsEmpty(S)) return S->Next->Element;//有header
	else printf("Empty stack.\n");
	return 0;//return value used to avoid warning.
}

/*Figure Routine to pop from a stack-linked list implementation*/
void Pop(Stack S){
	PtrTode FirCell;
	if(IsEmpty(S)) printf("Empty stack");
	else {
		FirCell=S->Next;
		S->Next=FirCell->Next;
		free(FirCell);
	}
}

