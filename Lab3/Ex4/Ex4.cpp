#include <iostream>
#include <cmath>
using namespace std;
void  solveEquation(int  a,  int  b,  int  c,  float  *x1,  float  *x2,  float  *delta){
    *delta = (b*b)-(4*a*c);
    if (*delta<0){
        cout<<"The solution is complex"<<endl;
    }
    else{
        *delta = sqrt(*delta);
        *x1 = (-b+*delta)/2*a;
        *x2 = (+b+*delta)/2*a;
        cout<<x1<<x2;
    }
}
int main(){
    int a=1,b=2,c=3;
    float x1,x2,delta;
    solveEquation(a,b,c,&x1,&x2,&delta);
    
}