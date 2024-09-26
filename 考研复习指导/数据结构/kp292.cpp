#include<stdio.h>
#include<stdlib.h>
struct BSTNode{
	int Element;
	BSTNode *rchild;
	BSTNode *lchild;
};
typedef BSTNode* BiTree;
//二叉排序树的非递归查找算法
BSTNode *BST_Search(BiTree T,int key){
	while(T->Element!=key&&T!=NULL){
		if(key<T->Element) T=T->lchild;
		else T=T->rchild;
	}
	return T;
}

//二叉排序树插入操作的算法描述
int BST_Insert(BiTree T,int k){
	if(T==NULL){
		T=(BiTree)malloc(sizeof(struct BSTNode));
		T->Element=k;
		T->lchild=T->rchild=NULL;
		return 1;//返回1，表示插入成功
	}else if(k==T->Element) return 0;//树中存在相同关键字的结点，插入失败
	else if(k<T->Element) BST_Insert(T->lchild,k);
	else BST_Insert(T->rchild,k);
}

//构造二叉树的算法
void Creat_BST(BiTree T,int str[],int n){
	T=NULL;//初始时T为空树
	int i = 0;
	while(i<n){//依次将每个关键字插入二叉排序树
		BST_Insert(T,str[i]);
		i++;
	}
}
