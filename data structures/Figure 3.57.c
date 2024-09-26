#include<stdio.h>
#include<stdlib.h>
struct QueueRecord;
typedef struct QueueRecord *Queue;//结构指针
int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(int X,Queue Q);
int Front(Queue Q);
void Dequeue(Queue Q);
int FrontAndDequeue(Queue Q);

/*Place in implementation file
Queue implementation is a dynamically allocated array*/
#define MinQueueSize 5
struct QueueRecord{
	int Capacity;//数组大小，定义数组后就不变了
	int Front;
	int Rear;
	int Size;//实际元素个数，变化的
	int *Array;
};

/*Figure 3.58 Routine to test whether a queue is empty-array implementation*/
int IsEmpty(Queue Q){
	return Q->Size==0;
}

/*Figure 3.59 Routine to make an empty queue-array implementation*/
void MakeEmpty(Queue Q){
	Q->Size=0;
	Q->Front=1;
	Q->Rear=0;
}

/*Figure 3.60 Routine to enqueue-array implementation*/
static int Succ(int Value, Queue Q){
	if(++Value==Q->Capacity) Value=0;
	return Value;
}
void Enqueue(int X,Queue Q){
	if(IsFull(Q)) printf("Full queue.\n");
	else{
		Q->Size++;
		Q->Rear++;
		Q->Array[Q->Rear]=X;
	}
}
