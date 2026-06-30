#include <iostream>
using namespace std;

void sum1(float *sum, int n){
    if (n<1){return;}
    float up=1,down=0;
    for (int i = 12; i <= ((n*10)+2); i=i+10){
        up = i * up;
        down = i + down;
    }
    *sum = up/down;
}
int main(){
    float sum;
    int n;
    float *ptr = &sum;
    cout<<"Enter the value n : ";
    cin>>n;
    sum1(ptr,n);
    cout<<*ptr;
}