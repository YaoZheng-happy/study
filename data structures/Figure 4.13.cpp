/*Figure 4.13 (kp97) Binary tree node declarations*/
#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;
struct TreeNode{
	int X;
	Tree Left;
	Tree Right;
};
