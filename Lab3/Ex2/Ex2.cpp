#include <iostream>
using namespace std;
int main(){
    cout << "Enter N number: ";
    int n;
    cin >> n;
    int* ptr = &n;
    *ptr = *ptr + 7;
    
    cout << "Modified value of n: " << n << endl;
    
    return 0;
}