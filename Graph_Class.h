#pragma once
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    list<int>* adj; // Array of adjacency lists

    void DFSUtil(int v, bool visited[]); // Helper for DFS

public:
    Graph(int V); // Constructor
    ~Graph();     // Destructor
    void addEdge(int u, int v); // Add edge
    void printGraph(); // Print adjacency list
    void DFS(int v); // Depth-First Search
    void BFS(int s); // Breadth-First Search
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v); // Directed edge from u to v
}

void Graph::printGraph() {
    cout << "Adjacency List..." << endl;
    for (int i = 0; i < V; ++i) {
        cout<< "V[" << i << "]";
        for (auto x : adj[i])
          cout<<" -> " <<x;
          cout << endl;
        }
    }


void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
        int neighbor = *it;
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

void Graph::DFS(int v) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    cout << "Depth First Traversal (starting from vertex " << v << "):" << endl;
    DFSUtil(v, visited);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSUtil(i, visited);
        }
    }

    cout << endl;
    delete[] visited;
}

void Graph::BFS(int s) {
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    queue<int> q;
    cout << "Breadth First Traversal (starting from vertex " << s << "):" << endl;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                cout << u << " ";

                for (list<int>::iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
                    int neighbor = *it;
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }

    cout << endl;
    delete[] visited;
}