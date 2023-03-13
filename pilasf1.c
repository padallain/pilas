

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct  Piloto{
    char nombre[20];
    int numero ;
    int posicion;  
    char equipo[20];
    char nacionalidad[20];
	 

}Piloto;

typedef  struct nodo{
    Piloto *dato ;
    struct nodo *siguiente;
}Nodo;

typedef struct pila{

    Nodo  *tope;
    int total;

}Pila;

Piloto *crearPiloto( char nombre[20],int numero, int posicion, char equipo[20], char nacionalidad[20] );
Nodo  *crearNodo(Piloto *poche);
Pila *crearPila();
int estaVacia(Pila *pila);
void insertar(Pila *pila, Nodo *nodo);
void imprimir(Pila *pila);


int main(){
	Pila *p;
	Piloto *p1,*p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10;
	Nodo *n, *n2, *n3 , *n4 , *n5 , *n6 , *n7 , *n8 , *n9 , *n10  ;
	p=crearPila ();
	
	p1=crearPiloto("Max Verstappen",1,1,"'Red Bull'","'Holandes'");
	n=crearNodo(p1);
	
	p2=crearPiloto("Lewis Hamilton",44,6,"'Mercedes'","'Britanico'");
	n2=crearNodo(p2);
	
	p3=crearPiloto("'Checo' Perez",45,3,"'Red Bull'","'Mexicano'");
	n3=crearNodo(p3);
	
	p4=crearPiloto("Charles Leclerc",23,2,"'Ferrari'","'Monegasco'");
	n4=crearNodo(p4);
	
	p5=crearPiloto("Lando Norris",69,7,"'Mclaren'","'Britanico'");
	n5=crearNodo(p5);
	
	p6=crearPiloto("Yuki Tsunoda",59,18,"'Alpha Tauri'","'Nipones'");
	n6=crearNodo(p6);
	
	p7=crearPiloto("Fernando Alondo",26,8,"'Aston Martin'","'Espanol'");
	n7=crearNodo(p7);
	
	p8=crearPiloto("Esteban Ocon",65,9,"'Alpine'","'Frances'");
	n8=crearNodo(p8);
	
	p9=crearPiloto("Valteri Bottas",86,12,"'Alpha Romeo'","'Finlandes'");
	n9=crearNodo(p9);
	
	p10=crearPiloto("Carlos Sainz",55,4,"'Ferrari'","'Espanol'");
	n10=crearNodo(p10);
	
	
	
	insertar(p,n);
	insertar(p,n2);
	insertar(p,n3);
	insertar(p,n4);
	insertar(p,n5);
	insertar(p,n6);
	insertar(p,n7);
	insertar(p,n8);
	insertar(p,n9);
	insertar(p,n10);
	 
	imprimir (p);

return 0 ;
}
Piloto *crearPiloto( char nombre[20],int numero, int posicion, char equipo[20], char nacionalidad[20] ){

    Piloto*aux = (Piloto*) malloc(sizeof(Piloto));

     strcpy( aux ->nombre, nombre);

     aux ->numero = numero;

     aux ->posicion= posicion;

    strcpy( aux ->equipo, equipo);
    
    strcpy( aux ->nacionalidad, nacionalidad);

     return  aux;
}

Nodo  *crearNodo(Piloto *piloto){

    Nodo  *aux  = (Nodo*) malloc(sizeof(Nodo));
    aux ->dato = piloto;
    aux ->siguiente = NULL;

    return aux;

}

Pila  *crearPila(){

    Pila  *aux  = (Pila*) malloc(sizeof(Pila));
    aux ->tope = NULL;
    aux ->total = 0;
	
	return aux;
   

}

// 1 Si ella esta vacia , 0 si no esta vacia;
int estaVacia(Pila *pila){
	if (pila -> total==0){
		return 1;
	}else{
		return 0;
	} 
	
	
	
}

void insertar(Pila *pila, Nodo *aux){
	if (estaVacia(pila)){
		pila->tope=aux;
	
	}else{
		aux->siguiente=pila->tope;
		pila->tope=aux;
	}
	pila->total++;
}

void imprimir(Pila *pila){
	Nodo *aux=pila->tope;
	Piloto *p;
	while (aux!=NULL){
		p=aux->dato;
		printf("%s %d %d %s %s \n", p->nombre, p->numero, p->posicion, p->equipo, p->nacionalidad );
		aux= aux->siguiente;
	}



}








