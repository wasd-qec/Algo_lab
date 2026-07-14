#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
};

List* createList() {
    List* ls = new List;
    ls->head = nullptr;
    return ls;
}

void add_end(List* ls, int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    if (ls->head == nullptr) {
        ls->head = temp;
    } else {
        Node* curr = ls->head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void displayList(List* ls) {
    Node* curr = ls->head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

List** createGraph(int vertices) {
    List** graph = new List*[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = createList();
    }
    return graph;
}

void addEdge(List** graph, int u, int v) {
    add_end(graph[u], v);
    add_end(graph[v], u);
}

void displayGraph(List** graph, int vertices) {
    cout << "Adjacency List" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        displayList(graph[i]);
        cout << endl;
    }
}

int main() {
    int n = 8;
    List** graph = createGraph(n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 7);
    addEdge(graph, 6, 7);

    displayGraph(graph, n);

    // Free memory
    for (int i = 0; i < n; i++) {
        Node* curr = graph[i]->head;
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete graph[i];
    }
    delete[] graph;

    return 0;
}
