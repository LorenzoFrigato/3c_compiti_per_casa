#include <iostream>
using namespace std;
int MAX=10;
int main () {
int arrayNumeri[MAX],dato,max ;
unsigned int i,num=0,posizMAX;
arrayNumeri[0]=0;
cout << "Inserire i valori (0 per terminare): ";
cin >> dato;
while (dato!=0 && num < MAX){
    arrayNumeri [num]= dato;
    num++;
    if(num<MAX){
        cin>>dato;
    }
}
max=arrayNumeri[0];
posizMAX=0;
for(i=1;i<num;i++){
    if(arrayNumeri[i]>max){
    max=arrayNumeri[i];
    posizMAX=i;
}
}
cout << "MAX: " << max << endl;
cout << "Posizione max: " << posizMAX;

}
