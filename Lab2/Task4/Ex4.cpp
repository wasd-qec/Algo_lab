#include <iostream>
using namespace std;
int findMin(int a[],int n){
    if (n==1){
        return a[0];
    }
    else if (a[0]<=a[1]){
        for (int i=1;i<=n-1;i++){
            a[i]=a[i+1];
        }
        n--;
    }
    else if (a[0]>a[1]){
        for (int i=0;i<=n;i++){
            a[i]=a[i+1];
        }
        n--;
    }
    return findMin(a, n);
}
int main (){
    int a[] = {1,2,3,4,5};
    int b[] = {33,2,45,4,0};
    cout<<findMin(b,5)<<endl;
    system("pause");
    return 0;
}