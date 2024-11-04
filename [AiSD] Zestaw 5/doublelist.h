// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() {} // destruktor
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList(); // tu trzeba wyczyscic wezly

    DoubleList(const DoubleList& other); // copy constructor
    // usage:   DoubleList<int> list2(list1);

    DoubleList& operator=(const DoubleList& other); // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }
    std::size_t size() const; // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1)
    void push_back(const T& item); // O(1)
    void push_front(T&& item); // O(1)
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(1)
    void clear(); // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void display_reversed(); // O(n)
};

template <typename T>
DoubleList<T>::~DoubleList() {
    clear();
}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_front(T&& item) {
    if (!empty()) {
        head = new DoubleNode<T>(std::move(item), head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(std::move(item));
    }
}

template<typename T>
std::size_t DoubleList<T>::size() const{
    if(empty()){
        return 0;
    }
    else{
        size_t size=0;
        DoubleNode<T> *node=head;
        while(node != nullptr){
            node=node->next;
            size++;
            }
        return size;
    }
}

template <typename T>
void DoubleList<T>::push_back(const T& item){
    if(!empty()){
        tail->next= new DoubleNode<T>(item, nullptr, tail);
        tail=tail->next;
    } 
    else{
        head=tail= new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::pop_front(){
    assert(!empty());
    DoubleNode<T> *node = head; // zapamietujemy
    if(head==tail){
        head=tail= nullptr;
    }
    else{
        head= head->next;
        head->prev= nullptr;
    }
    delete node;
}

template <typename T>
void DoubleList<T>::pop_back(){
    assert(!empty());
    DoubleNode<T> *node = tail;
    if(head==tail){
        head=tail= nullptr;
    }
    else{
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete node;
}

template <typename T>
void DoubleList<T>::display(){
    DoubleNode<T> *node = head;
    while(node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::display_reversed(){
    DoubleNode<T> *node = tail;
    while(node != nullptr){
        std::cout << node->value << " ";
        node=node->prev;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::clear(){
    DoubleNode<T> *node = head;
    while(node != nullptr){
        node->value = T();
        DoubleNode<T> *next_node = node->next;
        delete node;
        node = next_node;
    }
    head = tail = nullptr;
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr) {
    DoubleNode<T>* obecny = other.head;
    while(obecny != nullptr){
        push_back(obecny->value);
        obecny = obecny->next;
    }
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other) {
    if(this != &other){
        clear();
        DoubleNode<T>* obecny= other.head;
        while(obecny != nullptr){
            push_back(obecny->value);
            obecny=obecny->next;
        }
    }
    return *this;
}

#endif

// EOF
