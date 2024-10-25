#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <chrono>  
using namespace std; 

void mostrarArreglo(int a[], int n);
void insercionDirecta(int a[], int n);
void shellSort(int array[], int n);
void generarArreglo(int[],int); 
void copiarArreglo(int [], int[], int); 

int main(){
    int n = 1000; 
    int contador = 0; 
    int opcion; 
    
    srand(time(NULL));
    
    int* a = new int[n];
    int* a2 = new int[n];
    
    auto start = chrono::high_resolution_clock::now(); 
    auto end = chrono::high_resolution_clock::now();
    
    do{
        cout<<"\n1. Insercion Directa. "<<endl; 
        cout<<"2. Ordenacion por shellsort"<<endl;
        cout<<"3. Cambiar tamanio del arreglo"<<endl;
        cout<<"4. Salir. "<<endl;  
        cin>>opcion;   
        
        switch(opcion){
            case 1:{
                contador++; 
                if(contador%2==0){
                    generarArreglo(a, n); 	
                    copiarArreglo(a,a2, n); 
                }
                start = chrono::high_resolution_clock::now();
                insercionDirecta(a, n); 
                end = chrono::high_resolution_clock::now();
                //mostrarArreglo(a, n);
                chrono::duration<double> duration = end - start;
                cout << "\nTiempo de ejecucion: (INSERCCION) " << duration.count() << " segundos" << endl;
                cout<<endl;
                break;
            }
            case 2:{
                contador++; 
                if(contador%2==0){
                    generarArreglo(a, n); 	
                    copiarArreglo(a,a2, n); 
                }
                start = chrono::high_resolution_clock::now();
                shellSort(a2, n); 
                end = chrono::high_resolution_clock::now();
                //mostrarArreglo(a2, n);
                chrono::duration<double> duration = end - start;
                cout << "\nTiempo de ejecucion: (SHELL SORT) " << duration.count() << " segundos" << endl;
                cout<<endl;  
                break;
            }
            case 3:{
                // Liberar memoria anterior
                delete[] a;
                delete[] a2;
                
                cout << "Ingrese el nuevo tamanio del arreglo (n): ";
                cin >> n;
                
                a = new int[n];
                a2 = new int[n];
                
                generarArreglo(a, n);
                copiarArreglo(a, a2, n);
                
                cout << "Tamanio del arreglo cambiado a: " << n << endl;
                break;
            }
            case 4:{
                cout << "Saliendo del programa..." << endl;
                opcion = 0;
                break;
            }
            default:{
                cout<<"Opcion invalida. "; 
                break;
            }
        }
        
    }while(opcion != 0); 
    
    delete[] a;
    delete[] a2;
    
    return 0; 
}

void mostrarArreglo(int a[],int n){
    for(int i=0; i<n; i++){
        cout<<a[i]<<" "; 
    }
}

void insercionDirecta(int a[], int n){
    int aux, k;  
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

void generarArreglo(int a[], int n){
    for(int i=0; i<n; i++){
        a[i] = -1000 + rand() % 10001; 
    }
}

void copiarArreglo(int a[],int a2[], int n){
    for(int i=0; i<n; i++){
        a2[i] = a[i]; 
    }
}