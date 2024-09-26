#include<stdlib.h>
#include<stdio.h>
/*直接插入排序，用到“哨兵”*/
void InsertSort(int A[],int n){
	int i,j;
	for(i=2;i<=n;i++){//A[]数组的下标从1开始，A[0]不存放元素，作为“哨兵”
		if(A[i]<A[i-1]){//递增序列
			A[0]=A[i];
			for(j=i-1;A[j]>A[0];j--){
				A[j+1]=A[j];
			}
			A[j+1]=A[0];
		}
	}
}

/*折半插入排序：将比较和移动操作分离。
先折半找出元素的待插入位置，然后统一移动待插入位置之后的所有元素*/
//void InsertSort2(int A[],int n){
//	int i,j,low,high,mid;
//	for(i=2;i<=n;i++){
//		A[0]=A[i];//将A[i]暂存入A[0];
//		low=1;high=i-1;//设置折半查找的范围
//		while(high>=low){//默认递增有序
//			mid=(high+low)/2;
//			if(A[mid]>A[0]) high=mid-1;//查找左子表
//			else low=mid+1;
//		}
//		for(j=i-1;j>=high+1;j--){
//			A[j+1]=A[j];//统一后移，空出插入位置。
//		}
//		A[high+1]=A[0];
//	}
//}

void InsertSort2(int A[],int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){
		A[0]=A[i];//要插入的元素
		low=1;high=i-1;
		while(low<=high){
			mid=(low+high)/2;
			if(A[mid]>A[0])high=mid-1;
			else low=mid+1;
		}
		for(j=i-1;j>=high+1;j--){
			A[j+1]=A[j];
		}
		A[high+1]=A[0];	
	}
}

/*希尔排序*/
void ShellSort(int A[],int n){
	int dk,i,j;
	for(dk=n/2;dk>=1;dk/=2){//增量变化，无统一规定
		for(i=dk+1;i<=n;i++){
			if(A[i]<A[i-dk]){
				A[0]=A[i];
				for(j=i-dk;j>0&&A[0]<A[j];j-=dk){
					A[j+dk]=A[j];
				}
				A[j+dk]=A[0];
			}
		}
	}
}

/*kp366 简单选择排序*/
void Swap(int a,int b);
void SelectSort(int A[],int n){
	int min,i,j;
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(A[j]<A[min]) min=j;
		}	
		if(min!=i) Swap(A[min],A[i]);
	}
}

/*kp368 建立大堆根*/
void HeadAdjust(int A[],int k,int len);
void BuidMaxHeap(int A[],int len){
	for(int i = len/2;i>0;i--){
		HeadAdjust(A,i,len);
	}
}
void HeadAdjust(int A[],int k,int len){
	A[0]=A[k];//A[0]暂存子树的根结点
	for(int i=2*k;i<=len;i*=2){
		if(i<len&&A[i]<A[i+1]) i++;//沿着key较大的子结点向下筛选
		if(A[0]>=A[i]) break;//筛选结束
		else {
			A[k]=A[i];//将A[i]调整到双亲结点上
			k=i;//修改k指，以便继续向下筛选
		}
	}
	A[k]=A[0];//被筛选结点的值放入最终位置。
}
/*堆排序算法*/
void HeapSort(int A[],int len){
	BuidMaxHeap(A,len);//初始建堆
	for(int i=len;i>1;i--){
		Swap(A[i],A[1]);//输出堆顶元素
		HeadAdjust(A,1,i-1);//调整，把剩余的i-1个元素整理成堆。
	}
}

/*kp378 归并排序思想的应用*/
//int n;
//int *B=(int *)malloc((n+1)*sizeof(int));
//void Merge(int A[],int low,int high,int mid){
///*表A的两段A[low,mid]和A[mid+1,high]各自有序，此函数将它们合并成一个有序表*/
//	int i,j,k;
//	for(k=low;k<=high;k++){
//		B[k]=A[k];//将A中所有元素复制到B中
//	}
//	for(i=k=low,j=mid+1;i<=mid&&j<=high;k++){
//		if(B[i]<=B[j]) A[k]=B[i++]; //比较B的两个段中的元素，将较小值复制到A中
//		else A[k]=B[j++];
//	}
//	while(i<low) A[k++]=A[i++];//若第一个表未检测完成，将第一个表剩下的元素复制到A中。
//	while(j<high) A[k++]=A[j++];
//}
int n;
int *B=(int *)malloc((n+1)*sizeof(int));
/*表A的两段A[low,mid]和A[mid+1,high]各自有序，此函数将它们合并成一个有序表*/
void Merge(int A[],int low,int high,int mid){
	int i,j,k;
	//将A所有元素复制到B中
	for(k=low;k<=high;k++) B[k]=A[k];
	//把B中的两段各自抽一个元素比较，小的放入A中；
	for(i=k=low,j=mid+1;i<=mid&&j<=high;k++){
		if(B[i]<=B[j]) A[k]=B[i++];
		else A[k]=B[j++];
	}
	/*若i段长于j段，则此时i<mid，就把i段剩下的所有元素都复制给A；同理i段短于j段。
	这两个while循环，只会有一个执行。*/
	while(i<mid) A[k++]=B[i++];
	while(j<high) A[k++]=B[j++];
}

/*kp378 合并两个已经排序的子表得到排序结果*/
void MergeSort(int A[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(A,low,mid);//递归
		MergeSort(A,mid+1,high);//递归
		Merge(A,low,high,mid);//归并。
	}
}

/*kp381 计数排序*/
void CountSort(int A[],int B[],int n,int k){
	int i,C[k];
	for(i=0;i<k;i++){
		C[i]=0;	//初始化计数数组
	}
	for(i=0;i<n;i++) //遍历数组，统计每个元素出现的次数（个数）
		C[A[i]]++;	//C[x]保存的是等于A[i]元素个数
	for(i=1;i<k;i++) C[i]=C[i]+C[i-1];//C[x]保存的是<=A[i]元素个数
	for(i=n-1;i>=0;i--){//从后往前遍历输入数组B[]
		B[C[A[i]]-1]=A[i];//将元素A[i]放到数组B的正确位置
		C[A[i]]=A[A[i]]-1;//若数组A中存在相同元素，需要这一步，否则不需要。
	}
}

