#include <vector>
#include <queue>
#include "graph.h"

void Graph::dfsHelper(Vertex *v, std::vector<int> &traversal) {
    traversal.push_back(v->data);
    v->visited = true;
    ListNode *node = v->adj;
    
    while (node != nullptr ) {
        if (!node->vptr->visited)
            dfsHelper(node->vptr, traversal);
        
        node = node->next;
    }
}

std::vector<int> Graph::dfs(const int n) {
    if (n < 0 || n >= num_vertices)
        throw std::runtime_error("Start vertex is out of bound.");
    
    for (int i = 0; i < num_vertices; ++i)
        vertices[i].visited = false;
    
    std::vector<int> traversal;
    dfsHelper(&vertices[n], traversal);
    
    return traversal;
}
