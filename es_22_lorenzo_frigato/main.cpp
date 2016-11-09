#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
int a,x,n,mag=0,minn=0,ug=0,i;

cout << "Inserisci il numero x che funge da test: "<< endl;
cin >> x;
cout << "Inserisci n numeri da inserire: " << endl;
cin >> n;
i=0;
while (i <n){
    system("CLS");
    cout << "inserisci a " << endl;
    cin >> a;
    if (x < a){
           mag++;
        }
        else{
           if (x > a){
           minn++;
            }
            else {
            ug++;
            }
    i++;
}

        }
system("CLS");
cout << "I numeri maggiori di x sono: "<< mag << endl;
cout << "I  numeri minori di x sono: "<< minn << endl;
cout << "I numeri uguali a x sono: " << ug << endl;
system ("PAUSE");
}


