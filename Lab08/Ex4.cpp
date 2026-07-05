#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Customer {
    string number;
    string name;
    char gender;

    Customer() {
        this->number = "";
        this->name = "";
        this->gender = ' ';
    }

    Customer(string number, string name, char gender) {
        this->number = number;
        this->name = name;
        this->gender = gender;
    }
};

struct Node {
    Customer customer;
    Node* next;
    
    Node() {
        this->next = nullptr;
    }

    Node(Customer c) {
        this->customer = c;
        this->next = nullptr;
    }
};

struct List {
    Node* head;
    int size;

    List() {
        this->head = nullptr;
        this->size = 0;
    }

    int getSize() {
        return size;
    }
};

void enqueue(List& list, Customer customer) {
    Node* current = new Node(customer);
    if (list.getSize() == 0) {
        list.head = current;
    } else {
        current->next = list.head;
        list.head = current;
    }
    list.size++;
}

Customer dequeue(List& list) {
    if (list.getSize() == 0) {
        return Customer();
    }
    Customer dequeuedCustomer;
    if (list.getSize() == 1) {
        Node* temp = list.head;
        dequeuedCustomer = temp->customer;
        list.head = nullptr;
        delete temp;
        list.size--;
    } else {
        Node* curr = list.head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        dequeuedCustomer = temp->customer;
        curr->next = nullptr;
        delete temp;
        list.size--;
    }
    return dequeuedCustomer;
}

void displayReverse(Node* node, int& index) {
    if (node == nullptr) return;
    displayReverse(node->next, index);
    cout << index++ << " " 
         << left << setw(15) << node->customer.name 
         << left << setw(1)  << node->customer.gender 
         << "         " << node->customer.number << endl;
}

void displayQueue(List& list) {
    if (list.getSize() == 0) {
        cout << "Queue is empty" << endl;
        return;
    }
    int index = 1;
    displayReverse(list.head, index);
}

int main() {
    List list;
    int choice = 0;

    while (choice != 4) {
        cout << "***********************************" << endl;
        cout << "Welcome to the MK Restaurant!" << endl;
        cout << "Menu:" << endl;
        cout << "1. Add a customer to the queue" << endl;
        cout << "2. Remove a customer from the queue" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit the program" << endl;
        cout << "          Enter a choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            char sex;
            string phone;
            cout << "Enter a student's name: ";
            cin >> name;
            cout << "Enter a student's sex: ";
            cin >> sex;
            cout << "Enter a student's phone number: ";
            cin >> phone;
            Customer c(phone, name, sex);
            enqueue(list, c);
        } 
        else if (choice == 2) {
            if (list.getSize() == 0) {
                cout << "Queue is Empty!" << endl;
            } else {
                Customer c = dequeue(list);
                cout << "Serving customer, " << c.name << "!" << endl;
            }
        } 
        else if (choice == 3) {
            displayQueue(list);
        }
    }
    return 0;
}
