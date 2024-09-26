#include<stdio.h>
#include<stdlib.h>
struct BSTNode{
	int Element;
	BSTNode *rchild;
	BSTNode *lchild;
};
typedef BSTNode* BiTree;
//�����������ķǵݹ�����㷨
BSTNode *BST_Search(BiTree T,int key){
	while(T->Element!=key&&T!=NULL){
		if(key<T->Element) T=T->lchild;
		else T=T->rchild;
	}
	return T;
}

//��������������������㷨����
int BST_Insert(BiTree T,int k){
	if(T==NULL){
		T=(BiTree)malloc(sizeof(struct BSTNode));
		T->Element=k;
		T->lchild=T->rchild=NULL;
		return 1;//����1����ʾ����ɹ�
	}else if(k==T->Element) return 0;//���д�����ͬ�ؼ��ֵĽ�㣬����ʧ��
	else if(k<T->Element) BST_Insert(T->lchild,k);
	else BST_Insert(T->rchild,k);
}

//������������㷨
void Creat_BST(BiTree T,int str[],int n){
	T=NULL;//��ʼʱTΪ����
	int i = 0;
	while(i<n){//���ν�ÿ���ؼ��ֲ������������
		BST_Insert(T,str[i]);
		i++;
	}
}
