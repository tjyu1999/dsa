#ifndef _BSTREE
#define _BSTREE

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

struct TreeNode {
        int data;
        TreeNode *lchild;
        TreeNode *rchild;
        TreeNode(int x) : data(x), lchild(nullptr), rchild(nullptr) {}
    };

class BSTree {
private:
    TreeNode *root;
    
    void deleteAll(TreeNode *node){
        if (node) {
            deleteAll(node->lchild);
            deleteAll(node->rchild);
            delete node;
        }
    }
    
    void __addLeft(const int &pdata, const int &data) {
        TreeNode *node = __searchBST(root, pdata);
        node->lchild = new TreeNode(data);
    }
    
    void __addRight(const int &pdata, const int &data) {
        TreeNode *node = __searchBST(root, pdata);
        node->rchild = new TreeNode(data);
    }
    
    TreeNode *__searchBST(TreeNode *node, const int &data){
        if (node == nullptr)
            return nullptr;
        
        if (node->data > data)
            return __searchBST(node->lchild, data);
        else if (node->data < data)
            return __searchBST(node->rchild, data);
        
        return node;
    }
    
    TreeNode *__insertBST(TreeNode *node, const int &data) {
        if (node == nullptr)
            return new TreeNode(data);
        
        if (node->data > data)
            node->lchild = __insertBST(node->lchild, data);
        else if (node->data < data)
            node->rchild = __insertBST(node->rchild, data);
        
        return node;
    }
    
    TreeNode *__removeBST(TreeNode *node, const int &data) {
        if (node == nullptr)
            return nullptr;
        
        if (node->data > data)
            node->lchild = __removeBST(node->lchild, data);
        else if (node->data < data)
            node->rchild = __removeBST(node->rchild, data);
        else {
            TreeNode *temp = node;
            
            if (node->lchild == nullptr)
                return node->rchild;
            else if (node->rchild == nullptr)
                return node->lchild;
            else {
                TreeNode *min = minSubTree(node->rchild);
                node->data = min->data;
                node->rchild = __removeBST(node->rchild, min->data);
                temp = nullptr;
            }
            
            delete temp;
        }
        
        return node;
    }
    
    TreeNode *minSubTree(TreeNode *node) {
        while (node->lchild)
            node = node->lchild;
        
        return node;
    }
    
    void levelOrder();

public:
    BSTree(int n) {
        root = new TreeNode(n);
    }
    
    ~BSTree() {
        deleteAll(root);
    }
    
    bool empty() const {
        return root == nullptr;
    }
    
    void addLeft(const int &pdata, const int &data) {
        if (data >= pdata)
            throw std::runtime_error("Invlaid operation.");
            
        __addLeft(pdata, data);
    }
    
    void addRight(const int &pdata, const int &data) {
        if (data < pdata)
            throw std::runtime_error("Invlaid operation.");
            
        __addRight(pdata, data);
    }
    
    bool searchBST(const int &data) {
        if (__searchBST(root, data))
            return true;
        
        return false;
    }
    
    void insertBST(const int &data) {
        if (searchBST(data))
            throw std::runtime_error("The node exists.");
        
        __insertBST(root, data);
    }
    
    void removeBST(const int &data) {
        if (!searchBST(data))
            throw std::runtime_error("The node does not exist.");
        
        __removeBST(root, data);
    }
    
    void printTree() {
        if (!empty())       
            levelOrder();
    }
    
    std::vector<int> inOrder() const;   
    std::vector<int> preOrder() const;
    std::vector<int> postOrder() const;
};

#endif
