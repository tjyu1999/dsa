#include <vector>
#include <queue>
#include "graph.h"
#include "utils.h"

void Graph::bfs(int n) {
    if (n < 0 || n >= num_vertices)
        throw std::runtime_error("Start vertex is out of bound.");
    
    for (int i = 0; i < num_vertices; ++i)
        vertices[i].visited = false;
    
    std::queue<Vertex *> q;
    std::vector<int> traversal;
    Vertex *v = &vertices[n];
    q.push(v);
    v->visited = true;
    
    while (!q.empty()) {
        Vertex *curr = q.front();
        q.pop();
        traversal.push_back(curr->data);
        ListNode *node = curr->adj;
        
        while (node != nullptr) {
            if (!node->vptr->visited) {
                q.push(node->vptr);
                node->vptr->visited = true;
            }
            
            node = node->next;
        }
    }
    
    printVec(traversal);
}
