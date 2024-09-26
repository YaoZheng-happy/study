#include<stdio.h>
#include<stdlib.h>
/*Figure 4.16 Binary search tree declaration*/
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X , SearchTree T);
SearchTree Delete(int X,SearchTree T);
int Retrieve(Position P);

/*Place in the implementation file*/
struct TreeNode{
	int Element;
	SearchTree Left;
	SearchTree Right;
};

/*Figure 4.17 Routine to make an empty tree*/
SearchTree MakeEmpty(SearchTree T){
	if(T!=NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return T;
}

/*Figure 4.18 Find operation for binary search trees*/
Position Find(int X,SearchTree T){
	if(T==NULL) return NULL;
	else if(X<T->Element) return Find(X,T->Left);
	else if(X>T->Element) return Find(X,T->Right);
	else return T;
}

/*Figure 4.19 Recursive implementation of FingMin for binary search trees*/
Position FindMin(SearchTree T){
	if(T==NULL) return NULL;
	else if(T->Left!=NULL) FindMin(T->Left);//T=T->Left;
	else if(T->Left==NULL) return T;
}

/*Figure 4.20 Nonrecursive implementation of FindMax for binary search trees*/
Position FindMax(SearchTree T){
	if(T!=NULL){
		while(T->Right!=NULL){
			T=T->Right;
		}
	} 
	return T;
}

/*Figure 4.22 Insertion into a binary search tree.*/
SearchTree Insert(int X,SearchTree T){
	if(T==NULL){
		/*Create and return a one-node tree*/
//		T=malloc(sizeof(struct TreeNode));//这里错误，不知道咋办
//		if(T==NULL) printf("Out of space.\n");
//		else{
//			T->Element=X;
//			T->Left=T->Right=NULL;
//		}
	}else if(X<T->Element){
		T->Left=Insert(X,T->Left);
	}else if(X>T->Element){
		T->Right=Insert(X,T->Right);
	}
	/*Else X is in the tree already: we'll do nothing*/
	return T;
}

/*Figure 4.25 Deletion routine for binary search trees*/
SearchTree Deletion(int X,SearchTree T){
	Position TmpCell;
	if(T==NULL) printf("Element not found.\n");
	else if(X<T->Element) T->Left=Deletion(X,T->Left);
	else if(X>T->Element) T->Right=Deletion(X,T->Right);
	else//Found element to be deleted
	if(T->Left&&T->Right)//two children
	{
		//Replace with smallest in right subtree;
		TmpCell=FindMin(T->Right);
		T->Element=TmpCell->Element;
		T->Right=Deletion(T->Element,T->Right);
	}
	else{//one or zero children;
		TmpCell=T;
		if(T->Left==NULL) T=T->Right;//also handles 0 children
		else if(T->Right==NULL) T=T->Left;
		free(TmpCell);
	}
	return T;
}
