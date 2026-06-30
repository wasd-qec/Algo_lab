#include <iostream>
using namespace std;
int main(){
    string name, gender;
    double salary;
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Enter gender (male or female): ";
    cin>>gender;
    cout<<"Enter salary : ";
    cin>>salary;
    double tax;
    if (gender == "male"){
        if (salary > 1000){
            tax = salary*0.095;
        }
        if (salary <=1000 && salary >500){
            tax = salary*0.07;
        }
        if (salary<=500 && salary>300){
            tax = salary*0.05;
        }
    }
    else if (gender == "female"){
        if (salary > 1000){
            tax = salary*0.08;
        }
        if (salary <=1000 && salary >500){
            tax = salary*0.065;
        }
        if (salary<=500 && salary>300){
            tax = salary*0.035;
        }
    }
    else {
        tax = 0;
    }
    cout<<"Your tax are : "<<tax;
    return 0;
}