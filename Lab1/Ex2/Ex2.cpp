#include <iostream>
using namespace std;
int main(){
    cout<<"Enter a character: ";
    char ch;
    cin>>ch;
    if (string("aeiouAEIOU").find(ch) != string::npos){
        cout<<"Vowel"<<endl;
    }
    else if (isalpha(ch)){
        cout << "Consonant" <<endl;
    }
    return 0;
}