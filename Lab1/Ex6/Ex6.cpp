#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter n (n > 50): ";
    cin >> n;

    while (n <= 50) {
        cout << "Invalid input. Please enter n greater than 50: ";
        cin >> n;
    }

    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 10 || i == 30) {
            continue;
        }
        sum += i;
    }

    cout << "Summation from 1 to " << n
         << " (except 10 and 30) = " << sum << endl;

    return 0;
}
