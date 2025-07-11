#include "Graph_Class.h"

int main() {
    Graph g(11);
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 5);
    g.addEdge(2, 4);
    g.addEdge(4, 3);
    g.addEdge(5, 6);
    g.addEdge(6, 8);
    g.addEdge(7, 3);
    g.addEdge(7, 8);
    g.addEdge(8, 10);
    g.addEdge(9, 4);
    g.addEdge(9, 7);
    g.addEdge(9, 10);


    g.printGraph();
    cout << endl;
    g.DFS(2);
    cout << endl;
    g.BFS(2);
    cout << endl;

   

    return 0;
    
}