int IsEven(int);
long int Pow(long int X,int N){
	if(N==0) return 1;
	if(N==1) return X;
	if(IsEven(N)) return Pow(X*X,N/2);
	else return Pow(X*X,N/2)*X;
}
int IsEven(int N){//�ж��Ƿ���ż��
	int flag=0;//0��true;-1��false��
	if(N%2!=0) N=-1;
	return N;
}
