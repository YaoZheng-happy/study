#include<stdio.h>
#include<stdlib.h>
#define MaxDegree 10
/*Figure 3.18 Type declarations for array implementation of the polynomial ADT
多项式的数组实现的类型声明*/
typedef struct{
	int CoeffiArray[MaxDegree+1];//系数组成的数组
	int Highpower;//幂
} *polynomial;

/*Figure 3.19 Procedure to initialize a polynomial to zero*/
void ZerePolynomial(polynomial Poly){
	int i;
	for(i=0;i<=MaxDegree;i++)
		Poly->CoeffiArray[i]=0;
	Poly->Highpower=0;
}

/*Figure 3.20 Procedure to add two polynomials*/
int Max(int a,int b){
	return a>b?a:b;
}
void AddPolynomial(const polynomial Poly1,const polynomial Poly2,polynomial PolySum){
	int i;
	ZerePolynomial(PolySum);
	PolySum->Highpower=Max(Poly1->Highpower,Poly2->Highpower);
	for(i=PolySum->Highpower;i>=0;i--){
		PolySum->CoeffiArray[i]=Poly1->CoeffiArray[i]+Poly2->CoeffiArray[i];
	}
}

/*Figure 3.21 Procedure to multiply two polynomials*/
void MultPolynomial(const polynomial Poly1,const polynomial Poly2,polynomial PolyProd){
	int i,j;
	ZerePolynomial(PolyProd);
	PolyProd->Highpower=Poly1->Highpower+Poly2->Highpower;
	if(PolyProd->Highpower>MaxDegree){
		printf("Exceeded array size.\n");
		return;
	}else{
		for(i=0;i<=Poly1->Highpower;i++){
			for(j=0;j<=Poly2->Highpower;j++){
				PolyProd->CoeffiArray[i+j]+=Poly1->CoeffiArray[i]*Poly2->CoeffiArray[j];
			}
		}
	}
}

/*Figure 3.23 Type declaration for linked list implementation of the Polynomial*/
typedef struct Node *PtrToNode;
typedef struct Node{
	int Coefficient; 
	int Exponent;
	PtrToNode Next;
};
typedef PtrToNode Polynomial;//Nodes sorted by exponent;
