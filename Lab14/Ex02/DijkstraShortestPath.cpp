#include <iostream>
#include <climits>
using namespace std;

const int V = 6;

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        cout << vertex;
        return;
    }
    printPath(parent, parent[vertex]);
    cout << " -> " << vertex;
}

void dijkstra(int graph[V][V], int source) {
    int dist[V];
    bool visited[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Source = " << source << endl << endl;
    cout << "Vertex\tDistance\tPath" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        if (dist[i] != INT_MAX) {
            printPath(parent, i);
        }
        cout << endl;
    }
}

void display(int graphMatrix[V][V]) {
    cout << "Adjacency Matrix:" << endl;
    cout << "  ";
    for (int i = 0; i < V; i++) {
        if (i == 0) {
            cout << "W ";
        } else {
            cout << char('A' + i - 1) << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        if (i == 0) {
            cout << "W: ";
        } else {
            cout << char('A' + i - 1) << ": ";
        }
        for (int j = 0; j < V; j++) {
            cout << graphMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int graph[V][V] = {
        {0, 5, 8, 0, 0, 0},
        {5, 0, 2, 1, 0, 0},
        {8, 2, 0, 3, 4, 0},
        {0, 1, 3, 0, 5, 7},
        {0, 0, 4, 5, 0, 1},
        {0, 0, 0, 7, 1, 0}
    };

    display(graph);
    dijkstra(graph, 0);

    return 0;
}
