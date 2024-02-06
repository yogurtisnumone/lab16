#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double * data,int n,int m){
	cout << fixed << setprecision(2);
    for(int i = 0; i < n*m; i++){
        cout << *(data+i);
        if(i%m == m-1) cout << endl;
        else cout << " ";
    }
	return;
}
void randData(double * data,int n,int m){
	for(int i = 0; i < n*m; i++){
        *(data+i) = ((double)(rand()%101)/100);
    }
	return;
}
void findRowSum(const double * data,double * rowSum,int n,int m){
	for(int i = 0 ; i < n; ++i){
		*(rowSum+i) = 0;
		for(int j = 0 ; j < m;++j){
			*(rowSum+i) += *(data + (i*m) + j);
		}
	}
	return;
}
void findColSum(const double * data,double * colSum,int n,int m){
	for(int j = 0 ; j < m;++j)
		*(colSum+j) = 0;
	for(int i = 0 ; i < n; ++i){
		for(int j = 0 ; j < m;++j){
			*(colSum+j) += *(data + (i*m) + j);
		}
	}
	return;
}