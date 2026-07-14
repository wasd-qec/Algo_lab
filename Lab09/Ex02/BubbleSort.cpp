#include<iostream>
using namespace std;
void bubblesort(int array[],int size){
    for (int i = 0; i<size; i++){
        for(int j=0; j<size-i-1;j++){
            if(array[j]>array[j+1]){
                int temp = array[j+1];
                array[j+1]=array[j];
                array[j]=temp; 
            }
        }
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
    
    bubblesort(arr, size);
    Display(arr, size);
    
    return 0;
}