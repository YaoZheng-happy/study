/*Binary search二分法*/
int BinarySearch(const int A[],int X,int N){
	int Low,Mid,High;
	Low=0;High=N-1;
	while(Low<=High){
		Mid=(Low+High)/2;
		if(A[Mid]<X) Low=Mid+1;//X在右边
		else if(A[Mid]>X) High=Mid-1;//X在左边
		else return X; //Found;
	}
	return -1;//NotFound is defined as -1;
}
