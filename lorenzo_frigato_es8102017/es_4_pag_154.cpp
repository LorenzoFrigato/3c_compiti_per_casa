#include <iostream>
using namespace std;

void dimensione(int&);
void caricamento(int [], int);
void prodotto(int[],int);
void somma(int[],int);

int main (){
int vet [10], dim,p,s;
dimensione(dim);
caricamento(vet,dim);
somma(vet,dim);
prodotto(vet,dim);
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
void prodotto(int v[],int dim){
    int p=1;
    for (int i=0;i<dim;i++){
        p=p*v[i];
        i++;
    }
    cout << "Il prodotto delle componenti pari e': " << p << endl;
}
void somma(int v[],int dim){
    int s=0;
    for (int i=1;i<dim;i++){
        s=s+v[i];
        i++;
    }
    cout << "La somma delle componenti dispari e': " << s << endl;
}

