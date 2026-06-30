#include <iostream>
using namespace std;


int main(){
    int user = 7;
    float array[user];
    float *ptr1=array;
    float sum=0,total=1;
    for (int i=0; i<user; i++){
        cout<<"Please enter number"<<(i+1)<<" : ";
        cin>>array[i];
    }
    for (int i=0; i<user; i++){
        cout<<*(ptr1+i)<<endl;
    }
    for (int i=0; i<user; i++){
        sum = sum + *(ptr1+i);
        total = total * *(ptr1+i);
    }
    cout<<sum<<endl<<total;
}