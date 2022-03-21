#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void insertion_sort( int arr[], int tamano){

	for(int i=1; i<tamano; i++)   
    {  
        int temp = arr[i];  
        int j= i-1;  
        while(j>=0 && temp <= arr[j])  
        {  	
        	swap(arr[j+1],arr[j]); 
            j = j-1;  
        }  
    } 	
}	
int main(int argc, char** argv) {

	// caso lineal
	int a_1[20000];
	int a_2[30000];
	int a_3[40000];
	int a_4[50000];
	//caso cuadratico
	int b_1 [20000];
	int b_2[30000];
	int b_3[40000];
	int b_4[50000];

	
	for(int i=0; i <50000; i++){
		if(i <40000){
			if(i <30000){
				if(i <20000){
					a_1[i] = i;
					b_1[i] = 19999-i;
				}
				a_2[i] = i;
				b_2[i] = 29999-i;
			}
			a_3[i] = i;
			b_3[i] = 39999-i;
		}
		a_4[i] = i;
		b_4[i] = 49999-i;
	}
	/*El caso donde el isnertion sort tiene un comportamiento lineal es cuando la lista esta ordenada */
	cout <<"caso lineal"<<endl;
    auto start = std::chrono::system_clock::now();
	insertion_sort(a_1,20000);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float,std::milli> duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(a_2,30000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(a_3,40000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(a_4,50000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
 	/*Caso	cuadratico cuando la lista esta ordenada de mayor a menor*/
	 
	cout<<"Caso cuadratico"<<endl; 
	
	start = std::chrono::system_clock::now();
	insertion_sort(b_1,20000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(b_2,30000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(b_3,40000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;
	
	start = std::chrono::system_clock::now();
	insertion_sort(b_4,50000);
	end = std::chrono::system_clock::now();
	duration = end - start;
	cout<<duration.count()<<endl;

	return 0;
}
