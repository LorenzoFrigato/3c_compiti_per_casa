#include <iostream>
using namespace std;

void caricamento (int x[],int&dim){
cout << "Inserisci dimensione array: ";
cin >> dim;
for (int i=0; i<dim; i++){
    cout << "inserisci il valore della " << i << " posizione: ";
    cin >> x[i];
    }
}

bool test (int a[], int b[], int dima, int dimb){
bool ris=true;
if (dima==dimb){
        for (int i=0; i<dima; i++){
            if(a[i]!=b[i])
                {
                    ris=false;
                    return ris;
                }
        }
return ris;
}
else {
    ris =false;
    return ris;
}

}

int main (){
int a[10];
int b[10];
int dima,dimb;
cout << "ARRAY A: " << endl;
caricamento(a, dima);
cout << "ARRAY B: " << endl;
caricamento (b,dimb);
if (test (a,b,dima,dimb)==true)
    cout << "Gli array sono uguali";
else
    cout << "Gli array sono diversi";
}
