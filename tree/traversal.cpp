#include <stack>
#include <queue>
#include "bstree.h"
#include "utils.h"

std::vector<int> BSTree::inOrder() const {
    if (empty())
        return {};
        
    TreeNode *node = root;
    std::vector<int> traversal;
    std::stack<TreeNode*> st;
    
    while (node || !st.empty()) {
        while (node) {
            st.push(node);
            node = node->lchild;
        }
        
        node = st.top();
        st.pop();
        traversal.push_back(node->data);
        node = node->rchild;
    }
    
    return traversal;
}

std::vector<int> BSTree::preOrder() const { 
    if (empty())
        return {};
           
    TreeNode *node = root;
    std::vector<int> traversal;
    std::stack<TreeNode*> st{{node}};
    
    while (!st.empty()) {
        node = st.top();
        st.pop();
        traversal.push_back(node->data);
        
        if (node->rchild)
            st.push(node->rchild);
        if (node->lchild)
            st.push(node->lchild);
    }
        
    return traversal;
}

std::vector<int> BSTree::postOrder() const {
    if (empty())
        return {};
    
    TreeNode *node = root;
    std::vector<int> traversal;
    std::stack<TreeNode*> st{{node}};
    
    while (!st.empty()) {
        node = st.top();
        st.pop();
        traversal.push_back(node->data);
            
        if (node->lchild)
            st.push(node->lchild);
        if (node->rchild)
            st.push(node->rchild);
    }

    reverse(traversal);
    return traversal;
}

void BSTree::levelOrder() {
    std::queue<TreeNode*> q{{root}};
    
    while (!q.empty()) {
        int size = q.size();
                  
        for (int i = 0; i < size; ++i) {
            TreeNode *node = q.front();
            q.pop();
            std::cout << node->data << " ";
            
            if (node->lchild)
                q.push(node->lchild);
            if (node->rchild)
                q.push(node->rchild);
        }
        
        std::cout << std::endl;
    }
        
    std::cout << std::endl;
}
