#include<stdio.h>
#include<stdlib.h>
/*Figure 4.37 kp120 Node declaration for AVL trees*/
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(int X,AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(int X,AvlTree T);
AvlTree Delete(int X,AvlTree T);
int Retrieve(Position P);
int Max(int a, int b);
static Position SingleRotateWithLeft(Position K2);
static Position SingleRotateWithRight(Position K2);
static Position DoubleRotateWithLeft(Position K3);

/*Place in the implementation file*/
struct AvlNode{
	int Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

/*Figure 4.38 Function to compute height of an AVL node*/
static int Height(Position P){
	if(P==NULL) return -1;
	else return P->Height;
}

/*Figure 4.39 Insertion into an AVL tree*/
AvlTree Insert(int X,AvlTree T){
	if(T==NULL){
		/*Create and return a one-node tree*/
		T=(AvlNode*)malloc(sizeof(struct AvlNode));
		if(T==NULL) printf("Out of space.\n");
		else {
			T->Element=X;
			T->Left=T->Right=NULL;
		}
	}else if(X<T->Element){
		T->Left=Insert(X,T->Left);
		if(Height(T->Left)-Height(T->Right)==2){
			if(X<T->Left->Element) T=SingleRotateWithLeft(T);
			else T=DoubleRotateWithLeft(T);
		}
	}else if(X>T->Element){
		T->Right=Insert(X,T->Right);
		if(Height(T->Right)-Height(T->Left)==2){
			if(X>T->Right->Element) T=SingleRotateWithLeft(T);
			else T=DoubleRotateWithLeft(T);
		}
	}
	/*Else X is in the tree already: we'll do nothing*/
	T->Height=Max(Height(T->Left),Height(T->Right));
	return T;
}

/*This function can be called only if K2 has a left child.
Perform a rotate between a node(K2) and its left child
Update heights, then return new root.*/
static Position SingleRotateWithLeft(Position K2){
		Position K1;
		K1=K2->Left;
		K2->Left=K1->Right;
		K1->Right=K2;
		
		K2->Height=Max(Height(K2->Left),Height(K2->Right));
		K2->Height=Max(Height(K1->Left),Height(K1->Right));
		
		return K1;//return new root.
}
/*This function can be called only if K2 has a right child.
Perform a rotate between a node(K2) and its right child
Update heights, then return new root.*/
static Position SingleRotateWithRight(Position K2){
	Position K1=K2->Right;
	
	K2->Right=K1->Left;
	K1->Left=K2;
	K2->Height=Max(Height(K2->Left),Height(K2->Right));
	K1->Height=Max(Height(K1->Left),Height(K1->Right));
	
	return K1;//return the root;
}

/*This function can be called only if K3 has a left
child and K3's left child has a right child
Do the left-right double rotation
update heights,then return new root*/
static Position DoubleRotateWithLeft(Position K3){
	K3->Left=SingleRotateWithRight(K3->Left);
	return SingleRotateWithLeft(K3);
}

int Max(int a,int b){
	return a>b? a:b;//ÈýÔªÔËËã·û£»
}

/*Figure 4.56 kp132 Routine to print a binary search tree in order*/
void PrintTree(AvlTree T){
	if(T!=NULL){
		PrintTree(T->Left);
		printf("%d",T->Element);
		PrintTree(T->Right);
	}
}
int Height1(AvlTree T){
	if(T==NULL) return -1;
	else return 1+Max(Height(T->Left),Height(T->Right));
}
