#include<stdio.h>
#include<stdlib.h>
/*Figure 5.7 kp154 Type declaration for separate chaining hash table*/
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(int Key,HashTable H);
void Insert(int Key,HashTable H);
int Retrieve(Position P);
/*Routine such as Delete and MakeEmpty are omitted*/

struct ListNode{
	int Element;
	Position Next;//Ω·ππ÷∏’Î
};
typedef Position List;

/*List *TheList will be an array of lists,allocated later
The lists use headers(for simplicity)
though this wasts space*/
struct HashTbl{
	int TableSize;
	List *TheLists;
};

/*Figure 5.8 Initialization routine for separate chaining hash table*/
#define MinTableSize 100
HashTable InitializeTable(int TableSize){
	HashTable H;
	int i;
	
	if(TableSize<MinTableSize){
		printf("Table size too small.\n");
		return NULL;
	}
	/*Allocate table*/
	H=(HashTable)malloc(sizeof(struct HashTbl));
	if(H==NULL) printf("Out of space.\n");
	H->TableSize=TableSize;
	
	/*Allocate array of lists*/
	H->TheLists=(List*)malloc(sizeof(List));
	if(H->TheLists==NULL) printf("Out of space!\n");
	/*Allocate list headers*/
	for(i=0;i<H->TableSize;i++){
		H->TheLists[i]=(ListNode*)malloc(sizeof(ListNode));
		if(H->TheLists[i]==NULL) printf("Out of space.\n");
		else H->TheLists[i]->Next=NULL;
	}
}
