/*Given two sorted lists L1 and L2 , write a procedure to compute L1 交 L2,
using only the basic list operations
对于两个给定集合A、B，由属于A又属于B的所有元素构成的集合，叫做A和B的交集。*/
struct List{
	int X;
	struct List *Next;
};
#include<stdio.h>
#include<stdlib.h>
List intersection(List *L1,List *L2){//交集
	List *L;
//	L=malloc(sizeof(struct List));//这句为什么错了？
	
	while(L1!=NULL&&L2!=NULL){
		if(L1->X<L2->X) L1=L1->Next;
		else if(L1->X > L2->X) L2=L2->Next;
		else if(L1->X==L2->X){
			L->X=L1->X;
			L=L->Next;
			L1=L1->Next;
			L2=L2->Next;
		}
	}
}


