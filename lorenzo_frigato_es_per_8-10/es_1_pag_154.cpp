#include <iostream>
#include <windows.h>
using namespace std;

int main (){
int i,j;
int array[100];
for (i=0;i<100;i++){ // inizializza array a 1
    array[i]=1;
}
for (i=2;i<100;i++){
    if (array[i]==1){
        for(j=2;j<(100/i)+1;j++)//trova tutti i numeri minori di 100 divisibili per i primi 50 numeri
            array[i*j]=0;
    }

cout << "numeri primi <100" <<i;
for (i=1;i<100;i++){// stampa ogni numero a cui non è stato trovato alcun divisore (i=1)
    if(array[i]==1)
        cout<< i;
}
system ("PAUSE");
}

}
