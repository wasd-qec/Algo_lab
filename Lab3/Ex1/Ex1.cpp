#include <iostream>
using namespace std;
int main(){
        string space = "      ";
        int a=1,b=2,c=3;
        int *x=&a,*y=&b,*z=&c;
        cout<<a<<space<<b<<space<<c<<endl;
        cout<<x<<space<<y<<space<<z<<endl;
        *(x)=10;
        *(y)=20;
        *(z)=30;
        cout<<a<<space<<b<<space<<c<<endl;

}