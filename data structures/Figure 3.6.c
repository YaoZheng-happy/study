#include<stdio.h>
#include<stdlib.h>
/*Figure 3.6 Type declarations for linked lists*/
#define _List_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;//List和Position都是Node结构指针，只是名字不同。
typedef PtrToNode Position;
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P,List L);
Position Find(int X,List L);
void Delete(int X,List L);
Position FindPrevious(int X,List L);
void Insert(int X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position Advance(Position P);
int Retrieve(Position P);

/*Place in the implementation file*/
struct Node{
	int Element;
	Position next;
};

/*Figure 3.8 Function to test whether a linked list is empty.
Return true if L is empty*/
int IsEmpty(List L){
	return L->next==NULL;
}

/*Figure 3.9 Function to test whether current position is the last in a linked list.
Return true if P is the last position in List L;
Parameter L is unused in this implementation*/
int IsLast(Position P,List L){
	return P->next==NULL;
}

/*Figure 3.10 Find routine
Return Position of X in L;NULL if not Found*/
Position Founs(int X,List L){
	Position P;
	P=L->next;
	while(P!=NULL&&P->Element!=X){
		P=P->next;
	}
	return P;
}

/*Figure 3.11 Delete routine for linked lists.
Delete first occurrence of X from a list.Assum use of a header node.*/
void Delete(int X,List L){
	Position P,tmpCell;
	P=FindPrevious(X,L);
	if(!IsLast(P,L)){//Assumption of header use;
		tmpCell=P->next;
		P->next=tmpCell->next;//Bypass deleted cell;
		free(tmpCell);
	}
}

/*Figure 3.12 FindPrivious--the Find routine for use with Delete:Find程序用于Delete
If X is not found,the Next field of returned Position is NULL.Assumed a header*/
Position FindPrevious(int X,List L){
	Position P;
	P=L;
	while(P->next!=NULL&&P->next->Element!=X){
		P=P->next;
	}
	return P;
}

/*Figure 3.13 Insertion routine for linked lists
Insert (after legal position P)
Header implementation assumed
Parameter L is unused in this implement*/
void Insertion(int X,List L,Position P){
	Position tmpCell;
	tmpCell=malloc(sizeof(struct Node));
	if(tmpCell==NULL) printf("Out of space!");
	tmpCell->Element=X;
	tmpCell->next=P->next;
	P->next=tmpCell;//This function knows tha P is not NULL,so the routne is OK.
}

/*Figure 3.14(kp 50) Incorrect way to delete a list
Incorrect DeleteList algorithm*/
void DeleteList(List L){
	Position P;
	P=L->next;//Header assumed
	L->next=NULL;
	while(P!=NULL){
		free(P);
		P=P->next;
	}
}
//我不会delete a list!!!!!看不懂
/*Figure 3.15 Correct way to delete a list
Correct DeleteList algorithm*/
void DeliteList(List L){
	Position P,Tmp;
	P=L->next;//Header assumed;
	while(P!=NULL){
		Tmp=P->next;
		free(P);
		P=Tmp;
	}
}
