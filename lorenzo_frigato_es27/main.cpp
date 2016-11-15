#include <iostream>

using namespace std;

int main()
{
int a,b=0,c;
bool primo=true;
cout << "Immettere numero numeri da controllare: " << endl;
cin>>a ;
while(b<a) {
if(b==1 || b==2 || b== -1 || b == -2)
    primo == true;
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

if (primo==true)
    cout << b << endl;
b++;
}
}
