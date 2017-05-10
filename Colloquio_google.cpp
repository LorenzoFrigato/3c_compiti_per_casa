#include <iostream>
using namespace std;

void caricamento(int a[], int dim){
for (int i=0; i<dim; i++){
    cout << "inserisci il valore della " << i << " posizione: " ;
    cin >> a[i];
    }
}

bool controllo (int a[], int dim, int somma){
int comodo;
/*for (int i =0; i<dim-1; i++){
    for (int n=i; n< dim; n++){
        comodo= a[i]+a[n];
        if (comodo==somma)
            return true;
    }
}
return false;*/
int i=0;
do{
if (a[i]+ a[dim-1]> somma)
    dim--;
if (a[i]+ a[dim-1]< somma)
    i++;
if (a[i]+ a[dim-1]== somma)
    return true;

} while(i!=dim);
return false;


}

int main(){
int a[10], dim, somma;
cout << "Inserisci dimensione array: ",
cin >> dim;
caricamento(a,dim);
cout << "Inserisci somma: ";
cin >> somma;
if (controllo (a, dim, somma))
    cout << "Esiste almeno una coppia che da come somma " << somma;
else
    cout << "Non esiste nessuna coppia che da come somma " << somma;
}
