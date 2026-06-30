#include <iostream>
using namespace std;
int findSum(int a){
    static int sum = 0;
    sum = sum + a;
    if (a == -1){
        return sum;
    }
    cout<<"Enter the number:";
    cin>>a;
    return findSum(a);
}
    
int main (){
    cout<<"Enter the number:";
    int a;
    cin>>a;
    cout<<findSum(a)<<endl;
    system("pause");
    return 0;
}