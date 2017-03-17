#include <iostream>
using namespace std;

void Componivet3(int vet1[], int vet2[], int vet3[], int n){
    int i=1,resto;
    while (i<=n){
        resto=i%2;
        if(resto=0)
            vet3[i]=vet1[i];
        else
            vet3[i]=vet2[i]*3;
        i++;
    }

}
int main (){
int n;
int vet1[50], vet2[50], vet3[50];
cout << "Inserisci n: "<< endl;
cin >> n;
Componivet3(vet1,vet2,vet3,n);
}
