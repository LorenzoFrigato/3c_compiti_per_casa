#include <iostream>
#define N 100
using namespace std;

void selection_sort(int v[], int dim);

int main(){
    int a[N] = {-2,3,4,1,0,8,6,5,1,4,3,0};
    int dim = 12;
    selection_sort(a, dim);

    return 0;
}

void selection_sort(int v[], int dim)
{
    int comodo;
    for(int i = 0; i < dim-1; i++){
        for (int j = i+1; j < dim; j++){
            if (v[i] > v[j]){
                comodo = v[i];
                v[i] = v[j];
                v[j] = comodo;
            }
        }
    }
}//end selection sort
