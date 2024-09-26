#include<stdlib.h>
#include<stdio.h>
/*Figure 4.3 Node declarations for trees*/
typedef struct TreeNode *PtrToNode;
struct TreeNode{
	int Element;
	PtrToNode FirstChild;
	PtrToNode NextSibling;
};

/*Figure 4.6 Routine to list a directory in a hierarchical file system*/
typedef int DirectoryOrFile;
static void ListDir(DirectoryOrFile D,int Depth){
	if(D is a legitimate entry){
		
	}
}
