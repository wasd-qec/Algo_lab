#include <iostream>
using namespace std;

const int vertices = 5;
int graphMatrix[vertices][vertices];

void initialize() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graphMatrix[i][j] = 0;
        }
    }
}

void addEdge(int u, int v, int weight = 1) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        graphMatrix[u][v] = weight;
        graphMatrix[v][u] = weight;
    }
}

bool hasEdge(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        return graphMatrix[u][v] != 0;
    }
    return false;
}

void display() {
    cout << "Adjacency Matrix:" << endl;
    cout << "  0 1 2 3 4" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < vertices; j++) {
            cout << graphMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    initialize();
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    display();

    cout << "Edge (1,3) exists: " << (hasEdge(1, 3) ? "Yes" : "No") << endl;
    cout << "Edge (2,4) exists: " << (hasEdge(2, 4) ? "Yes" : "No") << endl;
    cout << "Edge (0,3) exists: " << (hasEdge(0, 3) ? "Yes" : "No") << endl;

    return 0;
}
