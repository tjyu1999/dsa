#ifndef _GRAPH
#define _GRAPH

#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int num_vertices;
    struct Vertex;
    std::vector<Vertex> vertices;
    
    struct ListNode {
        Vertex *vptr;
        ListNode *next;
    };

    struct Vertex {
        int data;
        bool visited;
        ListNode *adj;
    };

    void addNode(int n) {  
        vertices[n].data = n;
        vertices[n].visited = false;
        vertices[n].adj = nullptr;
    }
    
    void deleteAll(ListNode *node) {
        ListNode *next;
        
        while (node != nullptr) {
            next = node->next;
            delete node;
            node = next;
        }
    }
    
    void addEdge(ListNode *&node, Vertex *v) {
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
    
    void dfsHelper(Vertex *v);

public:
    Graph(int n) : num_vertices(n), vertices(n) {
        for (int i = 0; i < num_vertices; ++i)
            addNode(i);
    }
    
    ~Graph() {
        for (int i = 0; i < num_vertices; ++i)
            deleteAll(vertices[i].adj);
    }
    
    void addEdge(int n1, int n2) {
        if (n1 < 0 || n1 >= num_vertices || n2 < 0 || n2 >= num_vertices)
            throw std::runtime_error("Graph edge is out of bound.");
        
        addEdge(vertices[n1].adj, &vertices[n2]);
        addEdge(vertices[n2].adj, &vertices[n1]);
    }
    
    void bfs(int);
};

#endif
