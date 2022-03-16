#include <iostream>
#include <stdlib.h>
using namespace std;


int particionar_R(int a[] , int imin, int imax) {
	int r = rand() %imax +imin;
	swap(a[r],a[imin]);
	int ipiv= imin;
	int k= imin;
	int j= k+1;
	while (j<=imax) {
		if (a[j]<a[ipiv] ) {
			k= k+1;
			swap(a[k],a[j]);
		}
		j= j+1;
	}
	swap(a[k],a[ipiv]);
	return k;
}

int particionar(int a[] , int imin, int imax) {
	int ipiv= imin;
	int k= imin;
	int j= k+1;
	while (j<=imax) {
		if (a[j]<a[ipiv] ) {
			k= k+1;
			swap(a[k],a[j]);
		}
		j= j+1;
	}
	swap(a[k],a[ipiv]);
	return k;
}

void quicksort(int a[] , int imin, int imax) {
if (imin>=imax){

	return;
}
	int k= particionar_R(a, imin, imax);
	quicksort(a, imin, k-1);
	quicksort(a, k+1, imax);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int a[] = {4,5,2,34,123,4,56,7};
	quicksort(a,0,7);
	for(int i =0; i<7;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl;
	
	return 0;
}
