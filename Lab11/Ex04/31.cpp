
#include <iostream>
#include <string>
using namespace std;

int getAsciiSum(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += c;
    }
    return sum;
}
struct element {
    element* next;
    element* prev;
    string name;
};

struct list {
    element* head;

};
list* createList(){
    list* List = new list;
    List->head = nullptr;
    return List;
}
void CreateEmptyTable(list* array[],int size){
    for(int i=0;i<size;i++){
        array[i]=createList();
    }
}
int Hash(string& str,int size){
    int pos = getAsciiSum(str);
    return pos%size;
}

void Insert(list* array[],int size, string name){
    int pos = Hash(name,size);
    list* List = array[pos];
    element* node = new element;
    node->prev = nullptr;
    node->name = name;
    node->next = List->head;
    if (List->head != nullptr) { 
        List->head->prev = node;
    }
    List->head=node;
}
void Search(list* array[],int size, string name){
    int pos = Hash(name,size);
    list* List = array[pos];
    element* node = List->head;
    bool found=false;
    int i = 0;
    while (node != nullptr) {
        if (node->name==name){
            cout<<"We found it at index :"<<pos<<"And the position:"<<i<<endl;
            found = true;
        }
        node = node->next;
        i++;
    }
    if (found==false){
        cout<<"We cant find it"<<endl;
    }
}
void Delete(list* array[],int size, string name){
    int pos = Hash(name,size);
    list* List = array[pos];
    element* node = List->head;
    bool found=false;
    int i = 0;
    while (node != nullptr) {
        if (node->name==name){
            cout<<"We found it at index :"<<pos<<"And the position:"<<i<<endl;
            found = true;
            if (node->prev != nullptr){
                node->prev->next=node->next;
            }
            else{
                List->head = node->next;
            }
            if (node->next!=nullptr){
                node->next->prev=node->prev;
            }
            element* toDelete = node;
            node = node->next;
            delete toDelete;
            break;
        }
        else {
            node = node->next;
            i++;
        }
    }
    if (found==false){
        cout<<"We cant find it"<<endl;
    }
}

void Display(list* array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Index: " << i << ", Data: ";
        element* temp = array[i]->head;
        if (temp == nullptr) {
            cout << "Empty";
        } else {
            while (temp != nullptr) {
                cout << "[" << temp->name << "] -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }
        cout << endl;
    }
}

int main() {
    int size = 10;
    list* array[10];
    CreateEmptyTable(array, size);

    // 1. Add "Bob" to the hash table (ASCII: 66+111+98 = 275)
    Insert(array, size, "Bob");

    // 2. Add "Aoc" to the hash table (ASCII: 65+111+99 = 275) to test collision/chaining
    Insert(array, size, "Aoc");

    // 3. Search for the string "Bob" (exists)
    cout << "Searching for existing name 'Bob':" << endl;
    Search(array, size, "Bob");

    // 4. Remove a string that does not exist in the table
    cout << "\nAttempting to delete non-existing name 'Alice':" << endl;
    Delete(array, size, "Alice");

    // 5. Display all data in the hash table
    cout << "\nDisplaying all data in the hash table:" << endl;
    Display(array, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        element* current = array[i]->head;
        while (current != nullptr) {
            element* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        delete array[i];
    }

    return 0;
}