#include <iostream>

using namespace std;

int main()
{
int a,cent=0,dec=0,b=0;
cout << "Immetti a: ";
cin >> a ;
b=a;
if (a>=100)
    do{
    a=a-100;
    cent++;
    }while(a>100);
if(a>=10)
    do{
    a=a-10;
    dec++;
    }while(a>10);


cout << "Il numero "<< b << " ha: "<< endl;
cout << cent <<" centinaia" << endl;
cout << dec << " decine" << endl;
cout << a << " unita'";

}
