#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
};

void Insert(Node*& root, int data) {
    if (root == nullptr) {
        root = new Node;
        root->id = data;
        root->left = nullptr;
        root->right = nullptr;
        return; 
    }
    else if (data < root->id) {
        Insert(root->left, data);
    }
    else if (data > root->id) {
        Insert(root->right, data);
    }
}

void PreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->id << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(Node* root) {
    if (root != nullptr) {
        InOrder(root->left);
        cout << root->id << " ";
        InOrder(root->right);
    }
}

void PostOrder(Node* root) {
    if (root != nullptr) {
        PostOrder(root->left);
        PostOrder(root->right);   
        cout << root->id << " ";
    }
}

int getSize(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return (1 + getSize(root->left) + getSize(root->right));
    }
}

bool Search(Node* root, int data) {
    if (root == nullptr) {
        return false;
    }
    else if (data == root->id) {
        return true;
    }
    else if (data < root->id) {
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

void FreeTree(Node* root) {
    if (root != nullptr) {
        FreeTree(root->left);
        FreeTree(root->right);
        delete root;
    }
}

void WriteInOrder(Node* root, ofstream& outFile) {
    if (root != nullptr) {
        WriteInOrder(root->left, outFile);
        outFile << root->id << endl;
        WriteInOrder(root->right, outFile);
    }
}

int main() {
    srand(time(nullptr));

    Node* root = nullptr;
    int count = 20;

    cout << "Generating 20 random numbers in range [10 - 1000] and inserting into BST:" << endl;
    for (int i = 0; i < count; i++) {
        int num = rand() % 991 + 10;
        cout << num << " ";
        Insert(root, num);
    }
    cout << "\n\nIn-order Traversal of the BST (Sorted data):" << endl;
    InOrder(root);
    cout << endl;

    string filename = "sorted_numbers.txt";
    ofstream outFile(filename);
    if (outFile.is_open()) {
        WriteInOrder(root, outFile);
        outFile.close();
        cout << "\nSuccessfully wrote the sorted numbers to file '" << filename << "'." << endl;
    } else {
        cerr << "\nError: Could not open file '" << filename << "' for writing." << endl;
    }

    FreeTree(root);

    return 0;
}
