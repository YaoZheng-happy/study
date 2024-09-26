/*Swap two adjacent elements by adjusting only the pointers (and not the data)
a: Singly linked lists*/
struct stru{
	int X;
	stru *Next;
};
#include<stdio.h>
#include<stdlib.h>
typedef stru* List;
typedef stru* Position;
void SwapWithNext(Position BeforeP,List L){
	Position P,AfterP;
	P=P->Next;
	AfterP=P->Next;
	
	P->Next=AfterP->Next;
	BeforeP->Next=AfterP;
	AfterP->Next=P;
}
/*b: Doubly linked lists: P and AfterP are cells to be switched.*/
struct stru2{
	int X;
	stru2 *Next;
	stru2 *prev;
};
typedef stru2* Position2;
typedef stru2* List2;
void SwapWithNext2(Position2 P,List2 L){
	Position2 BeforeP,AfterP;
	BeforeP=P->prev;
	AfterP=P->Next;
	
	P->Next=AfterP->Next;
	AfterP->Next->prev=P;
	BeforeP->Next=AfterP;
	AfterP->prev=BeforeP;
	P->prev=AfterP;
	AfterP->Next=P;
}
