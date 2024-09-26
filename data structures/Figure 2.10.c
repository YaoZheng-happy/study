/*Euclid's Algorithmou'ji欧几里得函数，最小共约数*/
unsigned int Gcd(unsigned int M,unsigned int N){
	unsigned int Rem;
	while(N>0){
		Rem=M%N;
		M=N;
		N=Rem;
	}
	return M;
}
