#include "insertion.h"
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

