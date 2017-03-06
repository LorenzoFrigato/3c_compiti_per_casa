#include <iostream>
#include <math.h>
using namespace std;

void dimensione(int&);
void caricamento(int [], int);

int somma(int[],int);

int main (){
int vet [10], dim,p,s;
float radice;
dimensione(dim);
caricamento(vet,dim);
radice = sqrt(somma(vet,dim));
cout << "La radice della somma di tutte le componenti e': "<< radice;

}

void dimensione (int&dim){
    do{
        cout << "Inserisci il numero di elementi: ";
        cin >> dim;
    } while (dim >10 || dim <0);
}
void caricamento(int v [], int dim){
    for (int i=0;i<dim;i++){
        cout << "Inserisci il " << i << " valore:  ";
        cin >> v[i];

    }
}

int somma(int v[],int dim){
    int s=0;
    for (int i=0;i<dim;i++){
        s=s+v[i];
    }
    return s;
}



