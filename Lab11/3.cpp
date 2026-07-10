#include <iostream>
#include <string>
using namespace std;

int getAsciiSum(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += c; // c is automatically treated as its ASCII integer value
    }
    return sum;
}
int Hash(string& str,int size){
    int pos = getAsciiSum(str);
    return pos%size;
}

void Insert(string array[],int size, string name){
    int pos = Hash(name,size);
    array[pos]=name;
}
void Search(string array[],int size, string name){
    int pos = Hash(name,size);
    if(array[pos]==name){
         cout<<"It is contained in :"<<pos<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}
void Delete(string array[],int size, string name){
    int pos = Hash(name,size);
    if(array[pos]==name){
        cout<<"Deleted : "<< name<<endl;
        array[pos]="";
    }
    else{
        cout<<"not found"<<endl;
    }
}

void Display(string array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Index: " << i << ", Data: " << array[i] << endl;
    }
}

int main() {
    int size = 10;
    string array[10] = {""};

    // 1. Add "Bob" to the hash table
    Insert(array, size, "Bob");

    // 2. Ask user for 3 other names and add them
    cout << "Enter 3 other names:" << endl;
    for (int i = 0; i < 3; i++) {
        string name;
        cout << "Name " << i + 1 << ": ";
        cin >> name;
        Insert(array, size, name);
    }

    // 3. Search for the string "Bob"
    Search(array, size, "Bob");

    // 4. Remove string "Bob"
    Delete(array, size, "Bob");

    // 5. Display all data in the hash table
    cout << "\nDisplaying all data in the hash table:" << endl;
    Display(array, size);

    return 0;
}