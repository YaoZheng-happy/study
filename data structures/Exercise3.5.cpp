/*Given two sorted lists L1 and L2 , write a procedure to compute L1 并 L2,
using only the basic list operations
对于两个给定集合A、B，由两个集合所有元素构成的集合，叫做A和B的并集。*/
struct List{
	int X;
	struct List *Next;
};
#include<stdio.h>
#include<stdlib.h>
List intersection(List *L1,List *L2){
	List *L,*ret;
//	L=malloc(sizeof(struct List));//为什么错？
	ret=L;
	while(L1!=NULL||L2!=NULL){//只要有一个true，就会继续循环。
		if(L1==NULL&&L2!=NULL){
			L->Next=L1;
			break;
		}else if(L1!=NULL&&L2==NULL){
			L->Next=L2;
			break;
		}
		if(L1->X<L2->X){
			L->X=L1->X;
			L=L->Next;
			L1=L1->Next;
		}else if(L1->X>L2->X){
			L->X=L2->X;
			L=L->Next;	
			L2=L2->Next;		
		}else if(L1->X==L2->X){
			L->X=L1->X;
			L=L->Next;
			L1=L1->Next;
			L2=L2->Next;
		}
	}
//	return ret;//之后要free(L);
}
