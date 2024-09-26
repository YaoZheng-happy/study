#include<stdlib.h>
#include<stdio.h>
/*ֱ�Ӳ��������õ����ڱ���*/
void InsertSort(int A[],int n){
	int i,j;
	for(i=2;i<=n;i++){//A[]������±��1��ʼ��A[0]�����Ԫ�أ���Ϊ���ڱ���
		if(A[i]<A[i-1]){//��������
			A[0]=A[i];
			for(j=i-1;A[j]>A[0];j--){
				A[j+1]=A[j];
			}
			A[j+1]=A[0];
		}
	}
}

/*�۰�������򣺽��ȽϺ��ƶ��������롣
���۰��ҳ�Ԫ�صĴ�����λ�ã�Ȼ��ͳһ�ƶ�������λ��֮�������Ԫ��*/
//void InsertSort2(int A[],int n){
//	int i,j,low,high,mid;
//	for(i=2;i<=n;i++){
//		A[0]=A[i];//��A[i]�ݴ���A[0];
//		low=1;high=i-1;//�����۰���ҵķ�Χ
//		while(high>=low){//Ĭ�ϵ�������
//			mid=(high+low)/2;
//			if(A[mid]>A[0]) high=mid-1;//�������ӱ�
//			else low=mid+1;
//		}
//		for(j=i-1;j>=high+1;j--){
//			A[j+1]=A[j];//ͳһ���ƣ��ճ�����λ�á�
//		}
//		A[high+1]=A[0];
//	}
//}

void InsertSort2(int A[],int n){
	int i,j,low,high,mid;
	for(i=2;i<=n;i++){
		A[0]=A[i];//Ҫ�����Ԫ��
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

/*ϣ������*/
void ShellSort(int A[],int n){
	int dk,i,j;
	for(dk=n/2;dk>=1;dk/=2){//�����仯����ͳһ�涨
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

/*kp366 ��ѡ������*/
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

/*kp368 ������Ѹ�*/
void HeadAdjust(int A[],int k,int len);
void BuidMaxHeap(int A[],int len){
	for(int i = len/2;i>0;i--){
		HeadAdjust(A,i,len);
	}
}
void HeadAdjust(int A[],int k,int len){
	A[0]=A[k];//A[0]�ݴ������ĸ����
	for(int i=2*k;i<=len;i*=2){
		if(i<len&&A[i]<A[i+1]) i++;//����key�ϴ���ӽ������ɸѡ
		if(A[0]>=A[i]) break;//ɸѡ����
		else {
			A[k]=A[i];//��A[i]������˫�׽����
			k=i;//�޸�kָ���Ա��������ɸѡ
		}
	}
	A[k]=A[0];//��ɸѡ����ֵ��������λ�á�
}
/*�������㷨*/
void HeapSort(int A[],int len){
	BuidMaxHeap(A,len);//��ʼ����
	for(int i=len;i>1;i--){
		Swap(A[i],A[1]);//����Ѷ�Ԫ��
		HeadAdjust(A,1,i-1);//��������ʣ���i-1��Ԫ������ɶѡ�
	}
}

/*kp378 �鲢����˼���Ӧ��*/
//int n;
//int *B=(int *)malloc((n+1)*sizeof(int));
//void Merge(int A[],int low,int high,int mid){
///*��A������A[low,mid]��A[mid+1,high]�������򣬴˺��������Ǻϲ���һ�������*/
//	int i,j,k;
//	for(k=low;k<=high;k++){
//		B[k]=A[k];//��A������Ԫ�ظ��Ƶ�B��
//	}
//	for(i=k=low,j=mid+1;i<=mid&&j<=high;k++){
//		if(B[i]<=B[j]) A[k]=B[i++]; //�Ƚ�B���������е�Ԫ�أ�����Сֵ���Ƶ�A��
//		else A[k]=B[j++];
//	}
//	while(i<low) A[k++]=A[i++];//����һ����δ�����ɣ�����һ����ʣ�µ�Ԫ�ظ��Ƶ�A�С�
//	while(j<high) A[k++]=A[j++];
//}
int n;
int *B=(int *)malloc((n+1)*sizeof(int));
/*��A������A[low,mid]��A[mid+1,high]�������򣬴˺��������Ǻϲ���һ�������*/
void Merge(int A[],int low,int high,int mid){
	int i,j,k;
	//��A����Ԫ�ظ��Ƶ�B��
	for(k=low;k<=high;k++) B[k]=A[k];
	//��B�е����θ��Գ�һ��Ԫ�رȽϣ�С�ķ���A�У�
	for(i=k=low,j=mid+1;i<=mid&&j<=high;k++){
		if(B[i]<=B[j]) A[k]=B[i++];
		else A[k]=B[j++];
	}
	/*��i�γ���j�Σ����ʱi<mid���Ͱ�i��ʣ�µ�����Ԫ�ض����Ƹ�A��ͬ��i�ζ���j�Ρ�
	������whileѭ����ֻ����һ��ִ�С�*/
	while(i<mid) A[k++]=B[i++];
	while(j<high) A[k++]=B[j++];
}

/*kp378 �ϲ������Ѿ�������ӱ�õ�������*/
void MergeSort(int A[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		MergeSort(A,low,mid);//�ݹ�
		MergeSort(A,mid+1,high);//�ݹ�
		Merge(A,low,high,mid);//�鲢��
	}
}

/*kp381 ��������*/
void CountSort(int A[],int B[],int n,int k){
	int i,C[k];
	for(i=0;i<k;i++){
		C[i]=0;	//��ʼ����������
	}
	for(i=0;i<n;i++) //�������飬ͳ��ÿ��Ԫ�س��ֵĴ�����������
		C[A[i]]++;	//C[x]������ǵ���A[i]Ԫ�ظ���
	for(i=1;i<k;i++) C[i]=C[i]+C[i-1];//C[x]�������<=A[i]Ԫ�ظ���
	for(i=n-1;i>=0;i--){//�Ӻ���ǰ������������B[]
		B[C[A[i]]-1]=A[i];//��Ԫ��A[i]�ŵ�����B����ȷλ��
		C[A[i]]=A[A[i]]-1;//������A�д�����ͬԪ�أ���Ҫ��һ����������Ҫ��
	}
}

