#include <iostream>
using namespace std;

const int TABLE_SIZE = 7;
int Hashtable[TABLE_SIZE] = {0};

int Hash(int size, int data) {
    return data % size;
}

void Insert(int Hashtable[], int size, int data) {
    int pos = Hash(size, data);
    Hashtable[pos] = data;
}

void Display(int Hashtable[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Index: " << i << ", Data: " << Hashtable[i] << endl;
    }
}

bool Contain(int Hashtable[], int size, int data) {
    int pos = Hash(size, data);
    if (Hashtable[pos] == data) {
        cout << "It is contained in position/index " << pos << endl << endl;
        return true;
    } else {
        cout << "Not found" << endl << endl;
        return false;
    }
}

void Remove(int Hashtable[], int size, int data) {
    int pos = Hash(size, data);
    if (Hashtable[pos] == data) {
        Hashtable[pos] = 0;
        cout << "removed success" << endl << endl;
    } else {
        cout << "failed to delete as it does not exist" << endl << endl;
    }
}

void insert(int data) {
    Insert(Hashtable, TABLE_SIZE, data);
}

void display() {
    Display(Hashtable, TABLE_SIZE);
}

bool search(int data) {
    return Contain(Hashtable, TABLE_SIZE, data);
}

void remove(int data) {
    Remove(Hashtable, TABLE_SIZE, data);
}

int main() {
    insert(2);
    insert(4);
    insert(7);
    insert(10);
    search(7);
    remove(10);
    display();
    cout << "\n";
    return 0;
}
