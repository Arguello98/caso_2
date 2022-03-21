#include "quicksort.h"

//particionar usando un pivote aleatorio
int particionar_r(int a[] , int imin, int imax) {
	int r = rand() %imax +imin;
	swap(a[r],a[imin]);
	int ipiv= imin;
	int k= imin;
	int j = k+1;
	while (j<imax){
		if (a[j]<a[ipiv] ) {
			k= k+1;
			swap(a[k],a[j]);
		}
		j= j+1;
	}
	swap(a[k],a[ipiv]);
	return k;
}

//particionar usando pivote el primer elemento
int particionar(int a[] , int imin, int imax) {
	int ipiv= imin;
	int k= imin;
	int j= k+1;
	while (j<imax) {
		if (a[j]<a[ipiv] ) {
			k= k+1;
			swap(a[k],a[j]);
		}
		j= j+1;
	}
	swap(a[k],a[ipiv]);
	return k;
}

//usando como pivote el elemento del medio
int particionar_m(int a[] , int imin, int imax) {
	int r = (imax +imin)/2;
	swap(a[r],a[imin]);
	int ipiv= imin;
	int k= imin;
	int j= k+1;
	while (j<imax) {
		if (a[j]<a[ipiv] ) {
			k= k+1;
			swap(a[k],a[j]);
		}
		j= j+1;
	}
	swap(a[k],a[ipiv]);
	return k;
}

void quicksort(int a[] , int imin, int imax,int caso) {
	if (imin>=imax){
		return;
	}
	int k= 0;
	switch(caso){
		case 0:
			k= particionar(a, imin, imax);
			break;
		case 1:
			k = particionar_m(a, imin, imax);
			break;
		case 2:
			k = particionar_r(a, imin, imax);
			break;
		default:
			k= particionar(a, imin, imax);
			break;
	}
	quicksort(a, imin, k, caso);
	quicksort(a, k+1, imax,caso);
}

