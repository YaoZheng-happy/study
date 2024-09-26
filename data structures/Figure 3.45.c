#include<stdio.h>
#include<stdlib.h>
/*Figure 3.45 Stack declarations-array implementation*/
struct StackRecord;
typedef struct StackRecord *Stack;//结构指针

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X,Stack S);
int Top(Stack S);
void Pop(Stack S);
int TopAndPop(Stack S);

/*Place in implementation file
Stack implementation is a dynamically allocated array*/
#define EmptyTOS -1
#define MinStackSize 5
struct StackRecord{
	int Capacity;
	int TopOfStack;
	int *Array;
};

/*Figure 3.36 Stack creation-array implementation*/
Stack CreateStack(int MaxElements){
	Stack S;
	if(MaxElements<MinStackSize){
		printf("Stack size is too small.\n");
		return NULL;
	}
	S=malloc(sizeof(struct StackRecord));
	if(S==NULL){
		printf("Out of space.\n");
		return NULL;
	}
	S->Array=malloc(sizeof(int)*MaxElements);
	if(S->Array==NULL){
		printf("Out of space.\n");
		return NULL;
	}
	S->Capacity=MaxElements;
	MakeEmpty(S);
	return S;
}

/*Figure 3.47 Routine for freeing stack-array implementation*/
void DisposeStack(Stack S){
	if(S!=NULL){
		free(S->Array);
		free(S);
	}
}

/*Figure 3.48 Routine to test whether a stack is empty-array implementation*/
int IsEmpty(Stack S){
	return S->TopOfStack==EmptyTOS;//-1
}

/*Figure 3.49 Routine to create an empty stack-array implementation*/
void MakeEmpty(Stack S){
	S->TopOfStack=EmptyTOS;
}

/*Figure 3.50 Routine to push onto a stack-array implementation*/
void Push(int X,Stack S){
	if(IsFull) {
		printf("Full stack.\n");
	} else{
		S->Array[++S->TopOfStack]=X;//顶部先自增，后赋值。
	}
}

/*Figure 3.51 Routine to return top of stack-array implementation*/
int Top(Stack S){
	if(!IsEmpty(S)) return S->Array[S->TopOfStack];
	else{
		printf("Empty stack.\n");
		return 0;}
}

/*Figure 3.52 Routine to pop from a stack-array implementation*/
void Pop(Stack S){
	if(!IsEmpty(S)) S->TopOfStack--;
	else printf("Empty stack.\n");
}

/*Figure 3.53 Routine to give top element and pop a stack-array implementation*/
int TopAndPop(Stack S){
	if(!IsEmpty(S)) return S->Array[S->TopOfStack--];
	else printf("Empty stack.\n");
	return 0;
}
