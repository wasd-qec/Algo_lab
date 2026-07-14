#include <iostream>
#include <fstream>
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

int main() {
    Node* root = nullptr;
    string filename = "numbers.txt";
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cerr << "Error: Could not open file '" << filename << "'." << endl;
        return 1;
    }

    cout << "Reading numbers from '" << filename << "' and inserting into BST:" << endl;
    int num;
    while (inFile >> num) {
        cout << num << " ";
        Insert(root, num);
    }
    inFile.close();
    cout << "\n" << endl;

    cout << "a. Pre-order Traversal:" << endl;
    PreOrder(root);
    cout << "\n" << endl;

    cout << "b. In-order Traversal:" << endl;
    InOrder(root);
    cout << "\n" << endl;

    cout << "c. Post-order Traversal:" << endl;
    PostOrder(root);
    cout << "\n" << endl;

    cout << "Tree Size (Unique Elements): " << getSize(root) << endl;

    FreeTree(root);

    return 0;
}