#include <iostream>
using namespace std;

void sorpesa(char Lettere []){
int i=2;
while (i<=8){
    cout << Lettere [i];
    i+=2;
}
}

int main(){
char Lettere [10]= {'s','c','t','i','o','a','n','o','x','h'};
sorpesa (Lettere);
}

