#include <iostream>
#include <stdexcept>
#include "graph.h"
#include "utils.h"

int main() {
    try {
        Graph g(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        
        std::cout << "BFS: ";
        printVec(g.bfs(0));
        std::cout << "DFS: ";
        printVec(g.dfs(0));
    }
    catch(const std::runtime_error &e) {
        std::cerr << "Graph Exception: " << e.what() << std::endl;
    }
    
    try {
        Graph g(5);
        g.addEdgeWeight(0, 1, 1);
        g.addEdgeWeight(0, 2, 2);
        g.addEdgeWeight(1, 3, 3);
        g.addEdgeWeight(1, 4, 4);
        g.addEdgeWeight(2, 3, 5);
        g.addEdgeWeight(3, 4, 6);
        
        std::cout << "Kruskal MST:\n";
        printMST(g.kruskalMST());
        std::cout << "Prim MST:\n";
        printVec(g.primMST());
    }
    catch(const std::runtime_error &e) {
        std::cerr << "Graph Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
