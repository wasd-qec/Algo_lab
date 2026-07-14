#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Employee {
    string id;
    string firstName;
    string lastName;
    string position;
    string gender;
    string phone;
};

struct Node {
    Employee emp;
    Node* left;
    Node* right;
};

void Insert(Node*& root, const Employee& emp) {
    if (root == nullptr) {
        root = new Node;
        root->emp = emp;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (emp.id < root->emp.id) {
        Insert(root->left, emp);
    } else if (emp.id > root->emp.id) {
        Insert(root->right, emp);
    }
}

Node* Search(Node* root, const string& id) {
    if (root == nullptr || root->emp.id == id) {
        return root;
    }
    if (id < root->emp.id) {
        return Search(root->left, id);
    }
    return Search(root->right, id);
}

void InOrder(Node* root) {
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->emp.id << ": " << root->emp.firstName << " " << root->emp.lastName 
             << " (" << root->emp.position << ")" << endl;
        InOrder(root->right);
    }
}

void FreeTree(Node* root) {
    if (root != nullptr) {
        FreeTree(root->left);
        FreeTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    string filename = "employees.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Employee emp;
        if (getline(ss, emp.id, ',') &&
            getline(ss, emp.firstName, ',') &&
            getline(ss, emp.lastName, ',') &&
            getline(ss, emp.position, ',') &&
            getline(ss, emp.gender, ',') &&
            getline(ss, emp.phone, ',')) {
            Insert(root, emp);
        }
    }
    file.close();

    cout << "Loaded employees into BST. Current database listing (In-order):" << endl;
    InOrder(root);

    cout << "\nEnter Employee ID to search (e.g., emp005): ";
    string searchId;
    if (cin >> searchId) {
        Node* result = Search(root, searchId);
        if (result != nullptr) {
            cout << "\nEmployee Found!" << endl;
            cout << "ID: " << result->emp.id << endl;
            cout << "Name: " << result->emp.firstName << " " << result->emp.lastName << endl;
            cout << "Position: " << result->emp.position << endl;
            cout << "Gender: " << result->emp.gender << endl;
            cout << "Phone: " << result->emp.phone << endl;
        } else {
            cout << "\nEmployee not found." << endl;
        }
    }

    FreeTree(root);
    return 0;
}
