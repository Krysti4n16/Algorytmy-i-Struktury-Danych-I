// singlelist.h

#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct SingleNode {
// the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList(); // tu trzeba wyczyscic wezly

    SingleList(const SingleList& other); // copy constructor
    // usage:   SingleList<int> list2(list1);

    SingleList& operator=(const SingleList& other); // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }
    std::size_t size() const;// O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1), L.push_front(item)
    void push_back(const T& item); // O(1), L.push_back(item)
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void clear();// czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void reverse();// O(n)
};

template <typename T>
SingleList<T>::~SingleList() {
    clear();
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail) { // jeden wezel na liscie
        head = tail = nullptr;
    } else { // wiecej niz jeden wezel na liscie
        // Szukamy poprzednika ogona.
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

template<typename T>
std::size_t SingleList<T>::size() const{
    if(empty()){
        return 0;
    }
    else{
    size_t size=0;
    SingleNode<T> *node=head;
    while(node != nullptr){
        node=node->next;
        size++;
        }
    return size;
    }
}

template<typename T>
void SingleList<T>::clear(){
    while(!empty()){
        pop_front();
    }
}

template<typename T>
void SingleList<T>::reverse(){
    assert(!empty());

    SingleNode<T> *obecny=head;
    SingleNode<T> *poprz=nullptr;
    SingleNode<T> *next=nullptr;

    tail=head;
    while(obecny != nullptr){
        next=obecny->next;
        obecny->next=poprz;
        poprz=obecny;
        obecny=next;
    }
    head=poprz;
}

template<typename T>
SingleList<T>::SingleList(const SingleList& other) :head(nullptr), tail(nullptr){
    SingleNode<T> *obecny=other.head;
    while(obecny != nullptr) {
        push_back(obecny->value);
        obecny=obecny->next;
    }
}

template<typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList& other){
    if(this != &other){ //sprawdzamy czy nie przypisujemy samego siebie
        clear(); 
        SingleNode<T> *obecny=other.head;
        while(obecny != nullptr){
            push_back(obecny->value);
            obecny=obecny->next;
        }
    }
    return *this;
}


#endif
