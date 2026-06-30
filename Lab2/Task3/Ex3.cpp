#include <iostream>
using namespace std;
void star(int n){
    cout<<"*";
    if (n<=1){
        cout<<endl;
        return;
    }
    star(n-1);
}
void number(int n){
    cout<<n;
    if (n<=1){
        cout<<endl;
        return;
    }
    number(n-1);
}
int main(){
    while (true){
        cout<<"Menu \n1. n star\n2. n number\n";
        int choice;
        cin>>choice;
        if (choice == 1){
            cout<<"How many star do you want to show?\n";
            int ans;
            cin >> ans;
            star(ans);
        }
        else if (choice == 2){
            cout<<"How many number do you want to show?\n";
            int ans;
            cin >> ans;
            number(ans);
        }
        else { continue; }
        }
}