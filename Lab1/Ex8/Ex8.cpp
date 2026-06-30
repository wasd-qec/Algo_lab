#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

void quadraticRoots(double a, double b, double c) {
    if (a == 0) {
        cout << "Not a quadratic equation because a = 0." << endl;
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Two real roots: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << "One real root: x = " << x << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Two complex roots: x1 = " << realPart << " + " << imaginaryPart << "i"
             << ", x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

double computeBMI(double weightKg, double heightM) {
    return weightKg / (heightM * heightM);
}

void showBMICategory(double bmi) {
    if (bmi < 18.5) {
        cout << "BMI = " << bmi << " -> underweight" << endl;
    } else if (bmi < 25) {
        cout << "BMI = " << bmi << " -> normal weight" << endl;
    } else if (bmi < 30) {
        cout << "BMI = " << bmi << " -> overweight" << endl;
    } else {
        cout << "BMI = " << bmi << " -> obese" << endl;
    }
}

long long sumExceptDivisibleBy3(int n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 != 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Celsius to Fahrenheit" << endl;
        cout << "2. Fahrenheit to Celsius" << endl;
        cout << "3. Root of quadratic equation" << endl;
        cout << "4. Compute BMI and category" << endl;
        cout << "5. Sum 1..n except numbers divisible by 3" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        if (choice == 1) {
            double c;
            cout << "Enter Celsius: ";
            cin >> c;
            cout << "Fahrenheit = " << celsiusToFahrenheit(c) << endl;
        } else if (choice == 2) {
            double f;
            cout << "Enter Fahrenheit: ";
            cin >> f;
            cout << "Celsius = " << fahrenheitToCelsius(f) << endl;
        } else if (choice == 3) {
            double a, b, c;
            cout << "For ax^2 + bx + c = 0" << endl;
            cout << "Enter a, b, c: ";
            cin >> a >> b >> c;
            quadraticRoots(a, b, c);
        } else if (choice == 4) {
            double weight, height;
            cout << "Enter weight (kg): ";
            cin >> weight;
            cout << "Enter height (m): ";
            cin >> height;

            if (height <= 0) {
                cout << "Height must be greater than 0." << endl;
            } else {
                double bmi = computeBMI(weight, height);
                showBMICategory(bmi);
            }
        } else if (choice == 5) {
            int n;
            cout << "Enter n: ";
            cin >> n;
            if (n < 1) {
                cout << "n must be at least 1." << endl;
            } else {
                cout << "Sum = " << sumExceptDivisibleBy3(n) << endl;
            }
        } else if (choice == 0) {
            cout << "Program ended." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 0);

    return 0;
}
