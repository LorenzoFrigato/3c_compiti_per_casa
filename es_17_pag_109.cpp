#include <iostream>
using namespace std;

float cerchio (float);
float quadrato (float);
bool controllo (float);

int main(){
int a;
float b;


cout << "Che area vuoi calcolare? "<< endl;
cout << "1) Area cerchio"<< endl;
cout << "2) Area quadrato"<< endl;
cin >> a;
if(a==1){
    do{
        cout << "Inserisci il raggio: "<< endl;
        cin >> b;
    } while (controllo (b));
    cout << "L'area e': " << cerchio(b);
    }

if(a==2){
    do{
        cout << "Inserisci il lato: " << endl;
        cin >> b;
    }while (controllo (b));
    cout << "L'area e': " << quadrato(b);
    }
}

float cerchio (float b){
    float i;
    i=b*b*(3.14);
    return i;
}
float quadrato (float b){
   float i;
   i= b*b;
   return i;
}
bool controllo (float x){
 if (x <0)
    return true;
 else
    return false;
}
