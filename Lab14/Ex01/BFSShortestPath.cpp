#include <iostream>
using namespace std;

const int vertices = 7;
int graphMatrix[vertices][vertices];
bool directed = false;

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
        if (!directed) {
            graphMatrix[v][u] = weight;
        }
    }
}

void display() {
    cout << "Adjacency Matrix:" << endl;
    cout << "  0 1 2 3 4 5 6" << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < vertices; j++) {
            cout << graphMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool hasEdge(int u, int v) {
    if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
        return graphMatrix[u][v] != 0;
    }
    return false;
}

// Queue
const int SIZE = 10;
struct Queue {
    int front;
    int rear;
    int Q[SIZE];
};

struct Queue q1;

void createQueue() {
    q1.front = -1;
    q1.rear = -1;
}

void enqueue(int x) {
    if (q1.rear == SIZE - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (q1.front == -1) {
        q1.front = q1.rear = 0;
        q1.Q[q1.rear] = x;
    } else {
        q1.rear++;
        q1.Q[q1.rear] = x;
    }
}

int dequeue() {
    if (q1.front == -1 || q1.front > q1.rear) {
        cout << "Queue Underflow\n";
        return -1;
    }
    return q1.Q[q1.front++];
}

bool isEmpty() {
    return (q1.front == -1 || q1.front > q1.rear);
}

void printPath(int parent[], int destination) {
    if (parent[destination] == -1) {
        cout << destination;
        return;
    }
    printPath(parent, parent[destination]);
    cout << " -> " << destination;
}

void BFSShortestPath(int start) {
    bool visited[vertices];
    int distance[vertices];
    int parent[vertices];

    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        distance[i] = -1;
        parent[i] = -1;
    }

    createQueue();
    visited[start] = true;
    distance[start] = 0;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        for (int j = 0; j < vertices; j++) {
            if (hasEdge(current, j) && !visited[j]) {
                visited[j] = true;
                distance[j] = distance[current] + 1;
                parent[j] = current;
                enqueue(j);
            }
        }
    }

    cout << "Shortest Distance from Vertex " << start << endl;
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << " : Distance = " << distance[i] << " , Parent = " << parent[i] << endl;
        if (distance[i] != -1) {
            printPath(parent, i);
        }
        cout << endl << endl;
    }
}

int main() {
    initialize();
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    addEdge(6, 5);

    display();
    BFSShortestPath(0);

    return 0;
}
