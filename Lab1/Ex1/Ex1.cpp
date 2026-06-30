#include <iostream>
using namespace std;
int main(){
    int age;
    string name, gender, major;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your major: ";
    cin >> major;
    cout << "Please enter your gender (male or female): ";
    cin >> gender;
    cout << "Please enter your age: ";
    cin >> age;
    if ( gender.compare("male")==0){
        cout << "Hi, Mr "<<name<<"! your age is "<<age<<" year old and you learn "<<major<<endl;
    }
    if ( gender.compare("female")==0){
        cout << "Hi, Ms "<<name<<"! your age is "<<age<<" year old and you learn "<<major<<endl;
    }
    if (age>=18){
        cout<<"you can vote!";
    }
    else{
        cout<<"you cant vote!";
    }
    return 0;
}