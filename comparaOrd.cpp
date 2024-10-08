#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <chrono>  
using namespace std; 

void mostrarArreglo(int a[], int n);
void insercionDirecta(int a[], int n);
void shellSort(int array[], int n);

int main(){
	int n = 10000; 
	int opcion; 
	
	srand(time(NULL)); 
	
	int a[n]; 
	
	for(int i=0; i<n; i++){
		a[i] = -1000 + rand() % 2001; 
	}
	
	
	cout<<"1. Insercion Directa. "<<endl; 
	cout<<"2. Ordenacion por shellsort"<<endl; 
	cin>>opcion;   
	
	// Variables para medir el tiempo
	auto start = chrono::high_resolution_clock::now(); 
	auto end = chrono::high_resolution_clock::now();
	
	switch(opcion){
		case 1:{
			start = chrono::high_resolution_clock::now(); // Iniciar el tiempo
			insercionDirecta(a, n); 
			end = chrono::high_resolution_clock::now();
			mostrarArreglo(a, n);
			break;
		}
		case 2:{
			start = chrono::high_resolution_clock::now();
			shellSort(a, n); 
			end = chrono::high_resolution_clock::now();
			mostrarArreglo(a, n);
			break;
		}
	}
	
	// Calcular la duración
	chrono::duration<double> duration = end - start;
    cout << "\nTiempo de ejecucion: " << duration.count() << " segundos" << endl;
    
	return 0; 
}

void mostrarArreglo(int a[],int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<" "; 
	}
}

void insercionDirecta(int a[], int n){
	int aux, k, menor;  
	for(int i=1; i<n; i++){
		aux = a[i]; 
		k = i-1; 
		while((k>=0) && aux < a[k]){
			a[k+1] = a[k]; 
			k--; 
		}
		a[k+1] = aux; 		
	}
}

void shellSort(int array[], int n){
	int cen, aux;
    int k = n+1;
	while(k>1){
		k=k/2;
		cen = 1;
		while(cen == 1){
			cen = 0;
			int i = 0;
			while(i+k <= n-1){
				if (array[i+k] < array[i]){
					aux = array[i];
					array[i] = array[i+k];
					array[i+k] = aux;
					cen = 1;
				}
				i++;
			}
		}
	}
}

