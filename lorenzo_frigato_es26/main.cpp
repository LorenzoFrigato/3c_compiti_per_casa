#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
int a=0,b=2;
bool primo=true;
cout << "Immettere numero da controllare: " << endl;
cin>>a ;
if(a==1 || a==2 || a== -1 || a == -2)
    primo == true;
else{
    do{
        if(a%b==0){
            primo = false;
            break;
            }
        else{
            b++;
        }

        } while (b<a);
    }

if (primo==true)
    cout << "Il numero e' primo"<< endl;
else
    cout << "Il numero non e' primo"<< endl;
return 0;
}
