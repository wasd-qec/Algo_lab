#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node {
    string name;
    int age;
    Node* left;
    Node* right;
};

void Insert(Node*& root, string name, int age) {
    if (root == nullptr) {
        root = new Node;
        root->name = name;
        root->age = age;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (name < root->name) {
        Insert(root->left, name, age);
    } else if (name > root->name) {
        Insert(root->right, name, age);
    }
}

void InOrder(Node* root) {
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->name << " (Age: " << root->age << ")" << endl;
        InOrder(root->right);
    }
}

void WriteInOrder(Node* root, ofstream& outFile) {
    if (root != nullptr) {
        WriteInOrder(root->left, outFile);
        outFile << root->name << "," << root->age << endl;
        WriteInOrder(root->right, outFile);
    }
}

void getYoungestAndOldest(Node* root, string& youngestName, int& minAge, string& oldestName, int& maxAge) {
    if (root == nullptr) return;

    if (root->age < minAge) {
        minAge = root->age;
        youngestName = root->name;
    }
    if (root->age > maxAge) {
        maxAge = root->age;
        oldestName = root->name;
    }

    getYoungestAndOldest(root->left, youngestName, minAge, oldestName, maxAge);
    getYoungestAndOldest(root->right, youngestName, minAge, oldestName, maxAge);
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
    int n;
    cout << "Enter number of students: ";
    if (!(cin >> n)) return 1;

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Enter student " << i + 1 << " name: ";
        cin >> name;
        cout << "Enter student " << i + 1 << " age: ";
        cin >> age;
        Insert(root, name, age);
    }

    cout << "\nIn-order Traversal of Students:" << endl;
    InOrder(root);

    ofstream outFile("students.txt");
    if (outFile.is_open()) {
        WriteInOrder(root, outFile);
        outFile.close();
    }

    string youngestName = "";
    string oldestName = "";
    int minAge = 9999;
    int maxAge = -1;

    getYoungestAndOldest(root, youngestName, minAge, oldestName, maxAge);

    if (n > 0) {
        cout << "\nYoungest student: " << youngestName << " (Age: " << minAge << ")" << endl;
        cout << "Oldest student: " << oldestName << " (Age: " << maxAge << ")" << endl;
    }

    FreeTree(root);
    return 0;
}