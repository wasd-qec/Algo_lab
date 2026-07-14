#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    string inFilename = "numbers.txt";
    string outFilename = "selection.txt";
    ifstream inFile(inFilename);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open input file " << inFilename << endl;
        return 1;
    }

    vector<int> arr;
    int num;
    while (inFile >> num) {
        arr.push_back(num);
    }
    inFile.close();

    if (arr.empty()) {
        return 0;
    }

    mergeSort(arr, 0, arr.size() - 1);

    ofstream outFile(outFilename);
    if (!outFile.is_open()) {
        cerr << "Error: Could not open output file " << outFilename << endl;
        return 1;
    }

    for (int x : arr) {
        outFile << x << endl;
    }
    outFile.close();

    cout << "Sorted data written to " << outFilename << endl;
    return 0;
}
