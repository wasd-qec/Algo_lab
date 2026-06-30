#include <iostream>
using namespace std;

int findOdd(int n) {
    if (n % 2 == 0) {
        return n-1; // If n is even, return the next odd number
    } else {
        return n; // If n is already odd, return it
    }
}
int sum(int n){
    if (n<=1){
        return 1;
    }
    return n+sum((n-2));
}
int main() {
    int n;
    cout << "Enter a number:" << endl;
    cin >> n;
    int odd = findOdd(n);
    int total = sum(findOdd(n));
    cout << "The sum of odd number is: " << total << endl;
}