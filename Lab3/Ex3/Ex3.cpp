#include <iostream>
using namespace std;
void exchange(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    string space="   ";
    float x=100,y=200;
    float *a=&x,*b=&y;
    cout<<x<<space<<y<<endl;
    exchange(a,b);
    cout<<x<<space<<y<<endl;
}