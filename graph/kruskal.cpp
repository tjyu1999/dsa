#include "graph.h"
 
struct Subset {
    int rank;
    int parent;
};

void Graph::sortEdgesHelper(Edge &e1, Edge &e2) {
    Edge temp = e1;
    e1 = e2;
    e2 = temp;
}

void Graph::sortEdges(std::vector<Edge> &edges) {
    bool swapped;
    
    do {
        swapped = false;
        
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i - 1].w > edges[i].w) {
                swapped = true;
                sortEdgesHelper(edges[i - 1], edges[i]);
            }
        }
    } while (swapped);
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
