#include <iostream>
using namespace std;

void dimensione(int&);
void caricamento(int [], int);
void stampa (int [], int);

int main (){
int vet [10], dim;
dimensione(dim);
caricamento(vet,dim);
stampa (vet,dim);
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
void stampa (int v[], int dim){
    for (int i=dim-1; i>=0;i--){
        cout<< " " << v[i] << " ";
    }



}
