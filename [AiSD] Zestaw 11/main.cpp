#include<iostream>
#include<cassert>

template <typename T>
class Node{
public:
    T value;
    Node* left;
    Node* right;
    Node* parent;

    Node(T val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

template <typename T>
class BinarySearchTree{
public:
    Node<T>* find_min(Node<T>* node){
        while(node && node->left){
            node= node->left;
        }
        return node;
    }//funkcja pomocnicza, znajduje najbardziej lewy wezel w poddrzewie

    Node<T>* find_successor(Node<T>* node){
        if(!node){
            return nullptr;
        }

        if(node->right){
            return find_min(node->right);
        }

        Node<T>* parent= node->parent;
        while(parent && node == parent->right){
            node= parent;
            parent= parent->parent;
        }

        return parent; //moze zwrocic nullptr
    }
};

void test_find_successor(){

    std::cout << "test_find_successor..." << std::endl;

    /*drzewo BST:
    
            20
           /  \
          10   30
         /  \
       5    15
             / \
           12   18
    */

    Node<int>* root = new Node<int>(20);
    Node<int>* node10 = new Node<int>(10);
    Node<int>* node30 = new Node<int>(30);
    Node<int>* node5 = new Node<int>(5);
    Node<int>* node15 = new Node<int>(15);
    Node<int>* node12 = new Node<int>(12);
    Node<int>* node18 = new Node<int>(18);

    //relacje rodzic-dzieci
    root->left = node10; 
    node10->parent = root;
    root->right = node30; 
    node30->parent = root;

    node10->left = node5;
    node5->parent = node10;
    node10->right = node15; 
    node15->parent = node10;

    node15->left = node12; 
    node12->parent = node15;
    node15->right = node18; 
    node18->parent = node15;

    BinarySearchTree<int> bst;

    assert(bst.find_successor(node5) == node10);    //nastepnik 5 -> 10
    assert(bst.find_successor(node10) == node12);   //nastepnik 10 -> 12
    assert(bst.find_successor(node12) == node15);   //nastepnik 12 -> 15
    assert(bst.find_successor(node15) == node18);   //nastepnik 15 -> 18
    assert(bst.find_successor(node18) == root);     //nastepnik 18 -> 20
    assert(bst.find_successor(root) == node30);     //nastepnik 20 -> 30
    assert(bst.find_successor(node30) == nullptr);  //brak nastepnik dla 30

    std::cout << "Wszystkie testy zakonczone pomyslnie" << std::endl;

    delete root;
    delete node10;
    delete node30;
    delete node5;
    delete node15;
    delete node12;
    delete node18;
}

int main(){
    test_find_successor();
    return 0;
}
