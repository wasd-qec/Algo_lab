#include <iostream>
using namespace std;
int power(int m, int n){
    if (n==0){
        return 1;
    }
    return power(m,n-1)*m;
}
int sumSquare(int n){
    if (n<=1){
        return 1;
    }

    return n*n+sumSquare(n-1);
}
int sumDigit(int n){
    if (n<=1){
        return 1;
    }
    return n+sumDigit(n-1);
}
int main(){
    int a = 2;
    int b = 3;
    cout<<power(a,b)<<endl;
    cout<<sumSquare(5)<<endl;//55
    cout<<sumDigit(5)<<endl;
    system("pause");
    return 0;
}