#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std; 

void insercionDirecta(int [], int); 

int main(){
	int n; 
	
	srand(time(0)); 
		
	cout<<"Digite la cantidad de elementos que tendra el arreglo: "; 
	cin>>n; 
	
	int a[n]; 
	
	for(int i=0; i<n; i++){
		a[i] = -1000 + rand() % 1000; 
	}
	
	insercionDirecta(a, n); 
	
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	
	
	return 0; 
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