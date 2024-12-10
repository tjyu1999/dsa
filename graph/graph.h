#ifndef _GRAPH
#define _GRAPH

#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int num_vertices;
    int num_edges;
    struct Vertex;
    struct Edge;
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    
    struct ListNode {
        Vertex *vptr;
        ListNode *next;
    };

    struct Vertex {
        int data;
        bool visited;
        ListNode *adj;
    };
    
    struct Edge {
        int w;
        Vertex *v1ptr;
        Vertex *v2ptr;
    };
    
    void deleteAll(ListNode *node) {
        ListNode *next;
        
        while (node != nullptr) {
            next = node->next;
            delete node;
            node = next;
        }
    }

    void setNode(int n) {  
        vertices[n].data = n;
        vertices[n].visited = false;
        vertices[n].adj = nullptr;
    }
    
    void setEdge(Vertex *v1, Vertex *v2, int w) {
        Edge e;
        e.w = w;
        e.v1ptr = v1;
        e.v2ptr = v2;
        edges.push_back(e);
        ++num_edges;
    }
    
    void __addEdge(ListNode *&node, Vertex *v) {
        ListNode *n = new ListNode;
        n->vptr = v;
        n->next = nullptr;
        
        if (node == nullptr)
            node = n;
        else {
            ListNode *temp = node;            
            while (temp->next != nullptr)
                temp = temp->next;
                
            temp->next = n;
        }
    }
    
    void dfsHelper(Vertex *, std::vector<int> &);
    void sortEdges(std::vector<Edge> &);
    void sortEdgesHelper(Edge &, Edge &);

public:
    Graph(int n) : num_vertices(n), vertices(n) {
        for (int i = 0; i < num_vertices; ++i)
            setNode(i);
    }
    
    ~Graph() {
        for (int i = 0; i < num_vertices; ++i)
            deleteAll(vertices[i].adj);
    }
    
    void addEdge(int n1, int n2) {
        if (n1 < 0 || n1 >= num_vertices || n2 < 0 || n2 >= num_vertices)
            throw std::runtime_error("Graph edge is out of bound.");
        
        __addEdge(vertices[n1].adj, &vertices[n2]);
        __addEdge(vertices[n2].adj, &vertices[n1]);
    }
    
    void addEdgeWeight(int n1, int n2, int w) {
        if (n1 < 0 || n1 >= num_vertices || n2 < 0 || n2 >= num_vertices)
            throw std::runtime_error("Graph edge is out of bound.");
        
        setEdge(&vertices[n1], &vertices[n2], w);
        __addEdge(vertices[n1].adj, &vertices[n2]);
        __addEdge(vertices[n2].adj, &vertices[n1]);
    }
    
    std::vector<int> bfs(const int);
    std::vector<int> dfs(const int);
    std::vector<std::vector<int>> kruskalMST();
    std::vector<std::vector<int>> primMST();
};

#endif
