#include<iostream>
using namespace std;
void Insert(int array[], int size){
    for(int i=0; i<size-1;i++){
        if(array[i]<=array[i+1]){
            continue;
            }
        for(int j=i+1;j>0;j--){
            if(array[j]<array[j-1]){
                int temp = array[j-1];
                array[j-1]=array[j];
                array[j]=temp;
            }
            else{
                break;
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
    
    Insert(arr,size);
    Display(arr, size);
    
    return 0;
}