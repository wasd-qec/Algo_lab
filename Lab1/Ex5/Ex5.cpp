#include <iostream>
using namespace std;

int main() {
	long long minutes;

	cout << "Enter minute(s): ";
	cin >> minutes;

	if (minutes < 0) {
		cout << "Minutes must be non-negative." << endl;
		return 1;
	}

	long long hours = minutes / 60;
	long long remainingMinutes = minutes % 60;
	long long seconds = remainingMinutes * 60;

	cout << "Time format (h:m:s) = "
		 << hours << ":" << remainingMinutes << ":" << seconds << endl;

	return 0;
}