#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <ctime>
using namespace std;


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


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	// caso logaritmico
	int a_1 [2000];
	int a_2[3000];
	int a_3[4000];
	int a_4[5000];
	//caso cuadratico
	int b_1 [2000];
	int b_2[3000];
	int b_3[4000];
	int b_4[5000];
	//caso pivote fijo
	int c_1 [2000];
	int c_2[3000];
	int c_3[4000];

	//pivote aleatorio
	int d_1[2000];
	int d_2[3000];
	int d_3[4000];

	
	srand(time(NULL));
	
	for(int i=0; i <5000; i++){
		if(i <4000){
			if(i <3000){
				if(i <2000){
					a_1[i] = i;
					b_1[i] = 1999-i;
					c_1[i] = rand() %2000;
					d_1[i] = c_1[i];
				}
				a_2[i] = i;
				b_2[i] = 2999-i;
				c_2[i] = rand() %3000;
				d_2[i] = c_1[i];
			}
			a_3[i] = i;
			b_3[i] = 3999-i;
			c_3[i] = rand() %4000;
			d_3[i] = c_3[i];
		}
		a_4[i] = i;
		b_4[i] = 4999-i;
	}
	
	/*Caso logaritmico
		Sucede cuando el pivote es el elemento que termina en la mitad del arreglo
		para este caso se raliza el experimento con arreglos arreglados y tomando como pivote el elemento del medio
	*/

	cout <<"caso logaritmico"<<endl;
    auto start = std::chrono::system_clock::now();
	quicksort(a_1,0,2000,1);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float,std::micro> duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(a_2,0,3000,1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(a_3,0,4000,1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(a_4,0,5000,1);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
 	/*Caso	cuadratico 
	 	Sucede cuando la lista esta ordenada de mayor a menor o de menor a mayor
		para este caso se realiza con arreglos ordenados de menor a mayor y usando como pivote el primer elemento
	 */
	 
	cout<<"Caso cuadratico"<<endl; 
	
	start = std::chrono::system_clock::now();
	quicksort(b_1,0,2000,0);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(b_2,0,3000,0);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(b_3,0,4000,0);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(b_4,0,5000,0);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	/*
		En la primera parte del experimento para un arreglo de tamaño 7 y un arreglo de tamaño 15 se puede observar que el crecimiento cuanto se da el caso de comportamiento cuadratico
		es mucho mas rapido que cuando se da el caso de comportamiento logaritmico para los arreglos de mismo tamaño.
	
	*/
	 
	/*Pivote fijo y pivote aleatorio
		Se puede observar que al utilizar el pivote fijo el resultado siempre sera el mismo sobre un arreglo con ciertos elementos sin importar cuantas veces se realice
		en comparacion usando el pivote aleatorio se tendra un tiempo de ejecucion diferente cada vez que se realice el ordenamiento, el tiempo puede ser mayor o menor que usando el pivote fijo
		
		para el expérimento se utilizan 4 arreglos iguales de tamaño 15 
		se realiza el ordenamiento con pivote fijo en 2 de ellos y el resultado de itercambios,asignaciones, operaciones y comparaciones es el mismo en ambos
		pero cuando se realiza con el pivote aleatorio los resultados varian en ambos ya que se elige un pivote diferente cada vez
	*/
	
	cout<<"pivote fijo"<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(c_1,0,2000,0);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(c_2,0,3000,0);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(c_3,0,4000,0);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
 	
	cout <<"pivote aletorio"<<endl;

	start = std::chrono::system_clock::now();
	quicksort(d_1,0,2000,2);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(d_2,0,3000,2);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	quicksort(d_3,0,4000,2);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
		
	cout <<"end"<<endl;
	return 0;
}
