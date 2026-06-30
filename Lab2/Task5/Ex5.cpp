#include <iostream>
using namespace std;
int findSum(int a[],int n){
    if (n == 1){
        return a[0];
    }
    a[0] = a[n-1] + a[0];
    n--;
    return findSum(a, n);
}
    
int main (){
    int a[] = {1,2,3,4,5};
    int b[] = {33,2,45,4,0};
    cout<<findSum(a,5)<<endl;
    system("pause");
    return 0;
}