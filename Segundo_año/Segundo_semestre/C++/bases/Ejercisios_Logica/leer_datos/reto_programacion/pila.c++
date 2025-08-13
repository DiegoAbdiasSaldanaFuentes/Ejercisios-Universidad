#include <iostream>
#include <conio.h>
#include <stdlib.h> // new
using namespace std; // esto quita el uso de std::cout a cout esto NO es recomenadable

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&,int); //prototipo

int main(){
	Nodo *pila = NULL;
	int n1,n2;

	cout<<"Digite un numero:"<<endl;
	cin>> n1;
	agregarPila(pila,n1);

    cout<<"Digite otro numero:"<<endl;
    cin>> n2;
    agregarPila(pila,n2);

	getch();
	return 0;
}

void agregarPila(Nodo *&pila,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;

    cout<<"\nElemento"<<n<< "agregado a PILA correctamente"<<endl;
}