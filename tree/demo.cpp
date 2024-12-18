#include <iostream>
#include <cassert>
#include <stdexcept>
#include "bstree.h"
#include "utils.h"

int main() {
    try {
        BSTree bst(5);
        bst.addLeft(5, 4);
        bst.addLeft(4, 2);
        bst.addLeft(2, 1);
        bst.addRight(2, 3);
        bst.addRight(5, 12);
        bst.addLeft(12, 11);
        bst.addLeft(11, 10);
        bst.addRight(12, 20);
        bst.addLeft(20, 18);
        
        bst.printTree();
        assert(bst.searchBST(12));
        bst.insertBST(15);
        bst.printTree();
        bst.removeBST(2);
        bst.printTree();
    }
    catch(const std::runtime_error &e) {
        std::cerr << "BSTree Exception: " << e.what() << std::endl;
    }

    try {
        BSTree bst(5);
        bst.addLeft(5, 4);
        bst.addLeft(4, 2);
        bst.addLeft(2, 1);
        bst.addRight(2, 3);
        bst.addRight(5, 12);
        bst.addLeft(12, 11);
        bst.addLeft(11, 10);
        bst.addRight(12, 20);
        bst.addLeft(20, 18);
        
        std::cout << "Inorder:   ";
        printVec(bst.inOrder());
        std::cout << "Preorder:  ";
        printVec(bst.preOrder());
        std::cout << "Postorder: ";
        printVec(bst.postOrder());
    }
    catch(const std::runtime_error &e) {
        std::cerr << "BSTree Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
