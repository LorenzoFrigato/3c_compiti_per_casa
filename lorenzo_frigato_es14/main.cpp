#include <iostream>
#include <math.h>

using namespace std;

int main()
{
   int a,b,scelta;
   float area,perimetro,diagonale;
   cout << "Inserisci base rettangolo: " << endl;
   cin>> a;
   cout << "Insrisci altezza rettangolo: " << endl;
   cin >> b;
   cout << "Cosa vuoi calcolare? Scelgi il numero corrispondente:" << endl;
   cout << "1) perimetro" << endl;
   cout << "2) area" << endl;
   cout << "3) diagonale" << endl;
   cin>> scelta;
   switch (scelta){
    case (1):
        perimetro= 2*a+2*b;
        cout << "Il perimetro e': "<< perimetro;
        break;
    case (2):
        area =a*b;
        cout << "L'area e': " << area;
        break;
    case (3):
        diagonale= sqrt(a*a+b*b);
        cout << "la diagonale e': " << diagonale;
        break;
    default:
        cout << "inserisci un valore corretto!!!";
   }

}
