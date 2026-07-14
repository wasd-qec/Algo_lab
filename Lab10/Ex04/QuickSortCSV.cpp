#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string gender;
    string dob;
};

void swap(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

bool compare(const Student& a, const Student& b, char choice) {
    if (choice == 'a') {
        return a.id < b.id;
    } else if (choice == 'b') {
        return a.name < b.name;
    } else {
        return a.gender < b.gender;
    }
}

int partition(vector<Student>& arr, int low, int high, char choice) {
    Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compare(arr[j], pivot, choice)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<Student>& arr, int low, int high, char choice) {
    if (low < high) {
        int pi = partition(arr, low, high, choice);
        quickSort(arr, low, pi - 1, choice);
        quickSort(arr, pi + 1, high, choice);
    }
}

void displayStudents(const vector<Student>& arr) {
    cout << "ID\tName\tGender\tDoB" << endl;
    cout << "----------------------------------" << endl;
    for (const auto& s : arr) {
        cout << s.id << "\t" << s.name << "\t" << s.gender << "\t" << s.dob << endl;
    }
}

int main() {
    string filename = "students.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    vector<Student> students;
    string line;
    // Skip header line
    if (getline(file, line)) {
        // Successfully read header
    }

    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string idStr, name, gender, dob;
        if (getline(ss, idStr, ',') &&
            getline(ss, name, ',') &&
            getline(ss, gender, ',') &&
            getline(ss, dob, ',')) {
            Student s;
            s.id = stoi(idStr);
            s.name = name;
            s.gender = gender;
            s.dob = dob;
            students.push_back(s);
        }
    }
    file.close();

    cout << "Loaded " << students.size() << " students." << endl;
    displayStudents(students);

    cout << "\nChoose sorting criteria:" << endl;
    cout << "a. Sort by ID" << endl;
    cout << "b. Sort by name" << endl;
    cout << "c. Sort by gender" << endl;
    cout << "Choice: ";
    char choice;
    if (!(cin >> choice)) {
        return 1;
    }

    if (choice != 'a' && choice != 'b' && choice != 'c') {
        cout << "Invalid choice." << endl;
        return 1;
    }

    quickSort(students, 0, students.size() - 1, choice);

    cout << "\nAfter sorting:" << endl;
    displayStudents(students);

    return 0;
}
