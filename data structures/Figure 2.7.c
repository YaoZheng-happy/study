static int MaxSubSum(const int A[],int left,int right){
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRightBorderSum;
	int LeftBorderSum,RightBorderSum;
	int Center,i;
	
	if(left==right){//Base Case
		if(A[left]>0) return A[left];
		else return 0;
	}
	Center=(right+left)/2;
	MaxLeftSum=MaxSubSum(A,left,Center);
	MaxRightSum=MaxSubSum(A,Center+1,right);
	MaxLeftBorderSum=0;LeftBorderSum=0;
	for(i=Center;i>=left;i--){
		LeftBorderSum+=A[i];
		if(LeftBorderSum>MaxLeftBorderSum)
			MaxLeftBorderSum=LeftBorderSum;
	}
	MaxRightBorderSum=0;RightBorderSum=0;
	for(i=Center+1;i<=right;i++){
		RightBorderSum+=A[i];
		if(RightBorderSum>MaxRightBorderSum)
			MaxRightBorderSum=RightBorderSum;
	}
	return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);
	
}
int MaxSubsequenceSum(const int A[],int N){
	return MaxSubSum(A,0,N-1);
}
