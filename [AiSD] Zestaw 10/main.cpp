#include <iostream>
#include <queue>
#include<cassert>

template <typename T>
class Node{
public:
    T value;
    Node* left;
    Node* right;

    Node(T val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
int zliczanie_lisci_rekurencyjnie(Node<T>* root){
    if(root==nullptr){
        return 0;
    }
    if(root->left==nullptr && root->right==nullptr){
        return 1;
    }
    return zliczanie_lisci_rekurencyjnie(root->left)+zliczanie_lisci_rekurencyjnie(root->right);
}

template <typename T>
int zliczanie_lisci_iteracyjnie(Node<T>* root){
    if(root==nullptr){
        return 0;
    }
    int licznik_lisci=0;
    std::queue<Node<T>*> q;
    q.push(root);

    while(!q.empty()){
        Node<T>* current=q.front();
        q.pop();

        if(current->left==nullptr && current->right==nullptr){
            licznik_lisci++;
        }
        else{
            if(current->left != nullptr){
                q.push(current->left);
            }
            if(current->right != nullptr){
                q.push(current->right);
            }
        }
    }
    return licznik_lisci;
}

template <typename T>
void clear(Node<T>* root){
    if(root==nullptr){
        return;
    }

    clear(root->left);
    clear(root->right);
    delete root;
}

void test_tree(){
    std::cout << "binary tree test..." << std::endl << std::endl;

    std::cout << "puste drzewo..." << std::endl;
    Node<int>* root1 = nullptr;
    assert(zliczanie_lisci_rekurencyjnie(root1) == 0);
    assert(zliczanie_lisci_iteracyjnie(root1) == 0);
    std::cout << "test zakonczony pomyslnie" << std::endl;

    std::cout << std::endl << "drzewo z jednym wezlem..." << std::endl;
    Node<int>* root2 = new Node<int>(10);
    assert(zliczanie_lisci_rekurencyjnie(root2) == 1);
    assert(zliczanie_lisci_iteracyjnie(root2) == 1);
    clear(root2);
    std::cout << "test zakonczony pomyslnie" << std::endl;

    std::cout << std::endl << "drzewo z dwoma liscmi..." << std::endl;
    Node<int>* root3 = new Node<int>(10);
    root3->left = new Node<int>(5);
    root3->right = new Node<int>(15);
    assert(zliczanie_lisci_rekurencyjnie(root3) == 2);
    assert(zliczanie_lisci_iteracyjnie(root3) == 2);
    clear(root3);
    std::cout << "test zakonczony pomyslnie" << std::endl;

    std::cout << std::endl << "drzewo zlozone..." << std::endl;
    Node<int>* root4 = new Node<int>(10);
    root4->left = new Node<int>(5);
    root4->right = new Node<int>(15);
    root4->left->left = new Node<int>(3);
    root4->left->right = new Node<int>(7);
    root4->right->right = new Node<int>(20);
    assert(zliczanie_lisci_rekurencyjnie(root4) == 3); //liscie 3, 7, 20
    assert(zliczanie_lisci_iteracyjnie(root4) == 3);
    clear(root4);
    std::cout << "test zakonczony pomyslnie" << std::endl;

    std::cout << std::endl << "drzewo z jednym poddrzewem..." << std::endl;
    Node<int>* root5 = new Node<int>(10);
    root5->right = new Node<int>(20);
    root5->right->right = new Node<int>(30);
    assert(zliczanie_lisci_rekurencyjnie(root5) == 1); //lisc 30
    assert(zliczanie_lisci_iteracyjnie(root5) == 1);
    clear(root5);
    std::cout << "test zakonczony pomyslnie" << std::endl;

    std::cout << std::endl << "wszystkie testy przeszły pomyslnie" << std::endl;
}

int main(){
    test_tree();
    return 0;
}
