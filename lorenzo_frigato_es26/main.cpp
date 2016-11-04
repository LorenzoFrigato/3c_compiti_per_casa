#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
int a = 0,b,i;
bool primo;
while (a<1){
    cout << " Immettere numero da controllare: " << endl;
    cin>>a ;
}
i=0;
b=0;
while(i<a){// errore nei test del ciclo
    primo= true;
    i++;
    b++;
    if (a % b ==0)
        primo=false;
        break;
}
if (primo==true)
    cout << "Il numero e' primo"<< endl;
else
    cout << "Il numero non e' primo"<< endl;
}
