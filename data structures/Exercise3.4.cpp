/*Given two sorted lists L1 and L2 , write a procedure to compute L1 �� L2,
using only the basic list operations
����������������A��B��������A������B������Ԫ�ع��ɵļ��ϣ�����A��B�Ľ�����*/
struct List{
	int X;
	struct List *Next;
};
#include<stdio.h>
#include<stdlib.h>
List intersection(List *L1,List *L2){//����
	List *L;
//	L=malloc(sizeof(struct List));//���Ϊʲô���ˣ�
	
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


