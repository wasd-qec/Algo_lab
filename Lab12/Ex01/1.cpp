#include <iostream>
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

    cout << "=== Exercise 1: Student ID BST ===" << endl;
    cout << "Inserting Student IDs (e.g. 20110015, 20110008, 20110020):" << endl;
    
    Insert(root, 20110015);
    Insert(root, 20110008);
    Insert(root, 20110020);
    Insert(root, 20110005);
    Insert(root, 20110012);
    
    cout << "Inserted 5 IDs." << endl;

    cout << "\nPre-order Traversal:" << endl;
    PreOrder(root);
    cout << endl;

    cout << "\nIn-order Traversal (Sorted IDs):" << endl;
    InOrder(root);
    cout << endl;

    cout << "\nPost-order Traversal:" << endl;
    PostOrder(root);
    cout << endl;

    cout << "\nTree Size: " << getSize(root) << endl;

    int testId = 20110012;
    cout << "\nSearching for ID " << testId << ": ";
    if (Search(root, testId)) {
        cout << "Found!" << endl;
    } else {
        cout << "Not Found." << endl;
    }

    FreeTree(root);

    return 0;
}