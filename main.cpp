#include "insertion.h"
#include "textSearch.h"
#include "quicksort.h"
using namespace std;
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
	
	
	// caso lineal
	int aa_1[20000];
	int aa_2[30000];
	int aa_3[40000];
	int aa_4[50000];
	//caso cuadratico
	int bb_1 [20000];
	int bb_2[30000];
	int bb_3[40000];
	int bb_4[50000];

	
	for(int i=0; i <50000; i++){
		if(i <40000){
			if(i <30000){
				if(i <20000){
					aa_1[i] = i;
					bb_1[i] = 19999-i;
				}
				aa_2[i] = i;
				bb_2[i] = 29999-i;
			}
			aa_3[i] = i;
			bb_3[i] = 39999-i;
		}
		aa_4[i] = i;
		bb_4[i] = 49999-i;
	}
	/*El caso donde el isnertion sort tiene un comportamiento lineal es cuando la lista esta ordenada */
	cout <<"caso lineal"<<endl;
    start = std::chrono::system_clock::now();
	insertion_sort(aa_1,20000);
	end = std::chrono::system_clock::now();
	std::chrono::duration<float,std::milli> duration2 = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(aa_2,30000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration2.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(aa_3,40000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration2.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(aa_4,50000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration2.count()<<endl;
	
 	/*Caso	cuadratico cuando la lista esta ordenada de mayor a menor*/
	 
	cout<<"Caso cuadratico"<<endl; 
	
	start = std::chrono::system_clock::now();
	insertion_sort(bb_1,20000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration2.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(bb_2,30000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration2.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(bb_3,40000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration2.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(bb_4,50000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration2.count()<<endl;
	
	
	string ss = readFile();	
	start = std::chrono::system_clock::now();
 	SuffixTrie*S = new SuffixTrie();
 	insertar(S, ss);
	end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration1 = end - start;
	cout<<duration.count()<<endl;
   
	start = std::chrono::system_clock::now();
 	cout<<"Lorem"<<endl;
    S->search("Lorem");
 	end = std::chrono::system_clock::now();
 	duration = end - start;
	cout<<duration1.count()<<endl;
	
	start = std::chrono::system_clock::now();
 	cout<<"ipsum"<<endl;
    S->search("ipsum");
 	end = std::chrono::system_clock::now(); 	
  	duration = end - start;
	cout<<duration1.count()<<endl;
	
	start = std::chrono::system_clock::now();
 	cout<<"dolor"<<endl;
    S->search("dolor");
 	end = std::chrono::system_clock::now(); 	
  	duration = end - start;	  
 	cout<<duration1.count()<<endl;
 	
 	start = std::chrono::system_clock::now();	
 	cout<<""<<endl;
 	S->search("algo");
	end = std::chrono::system_clock::now(); 	
  	duration = end - start;	  
 	cout<<duration1.count()<<endl;
 	
 	cout<<"termino"<<endl;
	
	return 0;
}
