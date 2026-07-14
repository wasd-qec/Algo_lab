#include<iostream>
using namespace std;

void Select(int arra[],int size){
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arra[j] < arra[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arra[i];
        arra[i] = arra[minIndex];
        arra[minIndex] = temp;
    }
}

void Display(int arra[],int size){
    cout<<"Array :"<<endl;
    for (int i = 0; i < size; i++) {
        cout << arra[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    Select(arr, size);
    Display(arr, size);
    
    return 0;
}