#include<vector>
#include<algorithm>   // make_heap, push_heap, pop_heap
#include<iostream>

template <typename T>
class MyPriorityQueue {
    std::vector<T> lst; // działa domyślny konstruktor dla std::vector
public:
    MyPriorityQueue(std::size_t s=10) { lst.reserve(s); } // default constructor

    ~MyPriorityQueue() { lst.clear(); }

    MyPriorityQueue(const MyPriorityQueue& other) : lst(other.lst) {} // copy constructor

    MyPriorityQueue(MyPriorityQueue&& other) : lst(std::move(other.lst)) {} // move constructor

    MyPriorityQueue& operator=(const MyPriorityQueue& other){
        if(this != &other){
            lst= other.lst;
        }
        return *this;
    } // copy assignment operator, return *this

    MyPriorityQueue& operator=(MyPriorityQueue&& other){
        if(this != &other){
            lst= std::move(other.lst);
        }
        return *this;
    } // move assignment operator, return *this

    bool empty() const { return lst.empty(); }

    std::size_t size() const { return lst.size(); } // liczba elementów w kolejce

    void push(const T& item) { // dodanie do kolejki
        lst.push_back(item);
        std::push_heap(lst.begin(), lst.end());
    }

    void push(T&& item) { // dodanie do kolejki
        lst.push_back(std::move(item));
        std::push_heap(lst.begin(), lst.end());
    }

    T& top() { return lst.front(); } // zwraca element największy, nie usuwa

    void pop() { // usuwa element największy
        std::pop_heap(lst.begin(), lst.end());
        lst.pop_back();
    }

    void clear() { lst.clear(); } // czyszczenie listy z elementów

    void display(){
        for(std::size_t i=0;i<lst.size();++i){
        std::cout << lst[i] << " ";
    }
    std::cout << std::endl;
    }
};
