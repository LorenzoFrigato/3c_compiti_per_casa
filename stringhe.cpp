#include <iostream>
#include <string>
using namespace std;

int main(){
char nome [5];
nome [0]= 'm';
nome [1]= 'a';
nome [2]= 'r';
nome [3]= 'c';
nome [4]= 'o';
nome [5]= '\0';
cout << nome << endl;
char cognome [3]= {'f','u','\0'};
cout << cognome << endl;
char indirizzo []= "Via bernardi 3/a";
cout << indirizzo<< endl;
string telefono = "pippo graziani";
cout << telefono<< endl;
cout << telefono[5];

}
