#include <iostream>

using namespace std;

int main()
{
int a,b=0,c,i=0;
bool primo=true;
cout << "Immettere quanti numeri primi vuoi visualizzare : " << endl;
cin>>a ;
while(i<a) {
if(b==1 || b==2 )
    primo = true;
else{
    c=2;
    do{
        if(b%c==0){
            primo = false;
            break;
            }
        else{
            c++;
        }

      } while (c<b);
    }

if (primo==true){
         cout << b << endl;
         i = i + 1;
    }
b++;
}
}
