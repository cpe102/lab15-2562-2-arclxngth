#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

void randData(double *arr, int N, int M){

	for(int i=0; i<N*M; i++){

		double num = rand()%101/100.00;
		*(arr+i) = num;
	}
}

void showData(double *arr, int N, int M){

	for(int i=0; i<N*M; i++){
		if(i%M==0 && i!=0)	cout<<endl;
		cout<<*(arr+i)<<"\t";
	}
	cout<<endl;
}

void findColSum(const double *arr, double *sum, int N, int M){

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){

			*(sum+j) += *(arr+j+i*M);
		}
	}
}
