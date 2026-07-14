#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Element {
    string id;
    string name;
    string sex;
    string phone;
    string major;
    Element* next;
    Element* prev;
};

struct List {
    Element* head;
};

List* createList() {
    List* newList = new List;
    newList->head = nullptr;
    return newList;
}

void CreateEmptyTable(List* array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = createList();
    }
}

int Hash(const string& id, int size) {
    string numericPart = "";
    for (char c : id) {
        if (isdigit(c)) {
            numericPart += c;
        }
    }
    if (!numericPart.empty()) {
        try {
            long long val = stoll(numericPart);
            return val % size;
        } catch (...) {
        }
    }
    int sum = 0;
    for (char c : id) {
        sum += c;
    }
    return sum % size;
}

void Insert(List* array[], int size, string id, string name, string sex, string phone, string major) {
    int index = Hash(id, size);
    List* bucket = array[index];

    Element* node = new Element;
    node->id = id;
    node->name = name;
    node->sex = sex;
    node->phone = phone;
    node->major = major;
    node->prev = nullptr;
    node->next = bucket->head;

    if (bucket->head != nullptr) {
        bucket->head->prev = node;
    }
    bucket->head = node;
}

void Display(List* array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        Element* temp = array[i]->head;
        if (temp == nullptr) {
            cout << "Empty" << endl;
        } else {
            while (temp != nullptr) {
                cout << "[" << temp->id << " | " << temp->name << " | " << temp->sex 
                     << " | " << temp->phone << " | " << temp->major << "]";
                temp = temp->next;
                if (temp != nullptr) {
                    cout << " -> ";
                }
            }
            cout << " -> NULL" << endl;
        }
    }
}

int main() {
    int size = 15;
    List* array[15];
    CreateEmptyTable(array, size);

    cout << "=== Part A & B: Insert and Display 3 Students ===" << endl;
    
    // Test data for 3 students
    // Student 1 ID: e20110015
    // Student 2 ID: e20110016
    // Student 3 ID: e20110017
    for (int i = 0; i < 3; i++) {
        string id, name, sex, phone, major;
        cout << "\nEnter student " << i + 1 << " details:" << endl;
        cout << "ID (e.g. e20110015): ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Sex: ";
        cin >> sex;
        cout << "Phone: ";
        cin >> phone;
        cout << "Major: ";
        cin >> major;

        Insert(array, size, id, name, sex, phone, major);
    }

    cout << "\n--- Current Hash Table State ---" << endl;
    Display(array, size);

    cout << "\n=== Part C: Study duplicate hash (collision) case ===" << endl;
    cout << "We will insert a 4th student whose ID has the same hash index as an existing one." << endl;
    cout << "Example: ID 'e20110030' has numeric part 20110030." << endl;
    cout << "20110030 % 15 = 10. ID 'e20110015' also has 20110015 % 15 = 10." << endl;
    cout << "These two will collide at Index 10." << endl;

    cout << "\nInserting colliding student: ID = e20110030, Name = Alice, Sex = F, Phone = 099-888-777, Major = Telecom" << endl;
    Insert(array, size, "e20110030", "Alice", "F", "099-888-777", "Telecom");

    // Also insert a student with identical ID to show duplicate handling in chaining
    cout << "Inserting duplicate ID to verify: ID = e20110015, Name = DuplicateBob, Sex = M, Phone = 123-456, Major = CS" << endl;
    Insert(array, size, "e20110015", "DuplicateBob", "M", "123-456", "CS");

    cout << "\n--- Updated Hash Table State ---" << endl;
    Display(array, size);

    // Free memory
    for (int i = 0; i < size; i++) {
        Element* current = array[i]->head;
        while (current != nullptr) {
            Element* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        delete array[i];
    }

    return 0;
}
