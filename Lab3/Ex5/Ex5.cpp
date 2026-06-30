#include<iostream>
using namespace std;

void findMAxMIn(int *arry, int size, int *max, int *min){
    *max = arry[0];
    *min = arry[0];
    for (int i = 0; i < size; i++) {
        if (arry[i] > *max) *max = arry[i];
        if (arry[i] < *min) *min = arry[i];
    }
}
int main(){
    int array[7] = {1,2,3,4,5,6,6};
    int min, max;
    int size = sizeof(array) / sizeof(array[0]);
    cout<<&array<<endl<<min<<endl<<max<<endl; 
    findMAxMIn(array, size, &max, &min);
    cout<<&array<<endl<<min<<endl<<max;
    
}