#include <algorithm>
#include "graph.h"
 
struct Subset {
    int rank;
    int parent;
};

void Graph::sortEdges(std::vector<Edge> &sortedEdges) {
    std::sort(sortedEdges.begin(), sortedEdges.end(), [](const Edge &e1, const Edge &e2) {
        return e1.w < e2.w;
    });
}

int findParent(std::vector<Subset> &subsets, int vdata) {
    if (subsets[vdata].parent != vdata)
        subsets[vdata].parent = findParent(subsets, subsets[vdata].parent);
        
    return subsets[vdata].parent;
}

void unionSets(std::vector<Subset> &subsets, int v1data, int v2data) {
    int root1 = findParent(subsets, v1data);
    int root2 = findParent(subsets, v2data);
    
    if (subsets[root1].rank < subsets[root2].rank)
        subsets[root1].parent = root2;
    else if (subsets[root1].rank > subsets[root2].rank)
        subsets[root2].parent = root1;
    else {
        subsets[root2].parent = root1;
        subsets[root1].rank++;
    }
}

std::vector<std::vector<int>> Graph::kruskalMST() {
    std::vector<std::vector<int>> mst;
    std::vector<Subset> subsets(num_vertices);
    std::vector<Edge> sortedEdges = edges;
    sortEdges(sortedEdges);
    
    for (int i = 0; i < num_vertices; ++i) {
        subsets[i].rank = 0;
        subsets[i].parent = i;
    }
    
    for (int i = 0, total = 0; i < num_edges && total < num_vertices - 1; ++i) {
        Edge e = sortedEdges[i];
        int v1parent = findParent(subsets, e.v1ptr->data);
        int v2parent = findParent(subsets, e.v2ptr->data);
        
        if (v1parent != v2parent) {
            mst.push_back({e.v1ptr->data, e.v2ptr->data, e.w});
            unionSets(subsets, v1parent, v2parent);
            ++total;
        }
    }
    
    return mst;
}
