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

void addEdge(int u, int v, int weight) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        graphMatrix[u][v] = weight;
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
    cout << "  A B C D E" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << char('A' + i) << ": ";
        for (int j = 0; j < vertices; j++) {
            cout << graphMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    initialize();
    addEdge(0, 1, 3);
    addEdge(0, 2, 4);
    addEdge(1, 3, 5);
    addEdge(2, 4, 2);
    addEdge(3, 4, 3);
    addEdge(4, 2, 2);

    display();

    cout << "Edge (1,3) exists: " << (hasEdge(1, 3) ? "Yes" : "No") << endl;
    cout << "Edge (2,4) exists: " << (hasEdge(2, 4) ? "Yes" : "No") << endl;
    cout << "Edge (0,3) exists: " << (hasEdge(0, 3) ? "Yes" : "No") << endl;

    return 0;
}
