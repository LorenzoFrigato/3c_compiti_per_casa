#include <iostream>

using namespace std;

int main()
{
int n,i;
float media=0,a,mass=0,minn=0;

cout << "Inserisci quantita' numeri da inserire: ";
cin >> n;
for(i=0;i<n;i++){
    cout << "Immetti numero: ";
    cin>>a;
    if (i==0){
        minn=a;
        mass=a;
    }else{
        if(a>mass)
            mass=a;
        if(a<minn)
            minn=a;
    }
    media+=a;
}
media/=n;
cout << endl;
cout << "La media dei valori imseriti e': "<< media<< endl;
cout << "Il valore massimo inserito e': "<< mass<<endl;
cout << "Il valore minimo inserito e': "<< minn<< endl;

}
