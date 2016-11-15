#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cout << "inserisci il primo lato:  " << endl;
    cin >> a;
    cout << "inserisci il secondo lato:  "<< endl;
    cin >> b;
    cout << "inserisci il terzo lato:  " << endl ;
    cin >> c;
    if (a==b){
        if (b==c)
            cout << "triangolo equilatero";
        else
            cout << "triangolo isoscele";

}
    else{
        if (b==c)
            cout << "triangolo isoscele";
        else
            cout << "triangolo scaleno";
}

}
