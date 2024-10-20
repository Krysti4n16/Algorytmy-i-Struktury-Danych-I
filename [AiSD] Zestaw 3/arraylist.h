// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()
#include <algorithm>

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    ~ArrayList() { delete [] tab; } // destruktor

    ArrayList(const ArrayList& other): msize(other.msize), last(other.last){
        tab= new T[msize];
        for(int i=0;i<last;i++){
            tab[i]=other.tab[i];
            }
    }   // copy constructor
        // usage:   ArrayList<int> list2(list1);

    ArrayList& operator=(const ArrayList& other){
    
        if(this == &other){
            return *this;
        }

        delete[] tab; 

        msize= other.msize;
        last= other.last;
        tab= new T[msize];
        for(int i=0;i<last;i++){
            tab[i]=other.tab[i];
        }
        return *this;
    }   // copy assignment operator, return *this
        // usage:   list2 = list1;

    bool empty() const { return last == 0; } // checks if the container has no elements

    bool full() const { return last == msize; } // checks if the container is full

    int size() const { return last; } // liczba elementow na liscie

    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow

    void push_front(const T& item){
        assert(!full());
        for(int i=last;i>0;i--){
            tab[i]=tab[i-1];
        }
        tab[0]=item;
        last++;
    } // dodanie na poczatek

    void push_back(const T& item){
        assert(!full());
        tab[last]=item;
        last++;
    }// dodanie na koniec

    T& front(){
        assert(!empty());
        return tab[0];
    } // zwraca poczatek, nie usuwa, error dla pustej listy

    T& back(){
        assert(!empty());
        return tab[last-1];
    } // zwraca koniec, nie usuwa, error dla pustej listy

    void pop_front(){
        assert(!empty());
        for(int i=0;i<last;i++){
            tab[i]=tab[i+1];
        }
        last--;
    } // usuwa poczatek, error dla pustej listy

    void pop_back(){
        assert(!empty());
        last--;
    } // usuwa koniec, error dla pustej listy

    void clear(){
        last=0;
    }; // czyszczenie listy z elementow

    void display(){
        for(int i=0;i<last;i++){
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }

    void reverse(){
        for(int i=0;i<last/2;i++){
            std::swap(tab[i],tab[last-1-i]);
        }
    } // odwracanie kolejnosci

    void sort(){
        std::sort(tab,tab+last);
    } // sortowanie listy

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        return os;
    } // usage:   std::cout << L << std::endl;
};

#endif

// EOF
