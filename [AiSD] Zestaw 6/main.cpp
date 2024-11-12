#include "mydeque.h"

void test_empty(){
    std::cout << std::endl << "test metody empty..." << std::endl;
    MyDeque<int> deque;
    assert(deque.empty());

    deque.push_back(10);
    assert(!deque.empty());

    deque.pop_back();
    assert(deque.empty());

    std::cout << "zakonczono pomyslnie test metody empty" << std::endl;
}

void test_push_front(){
    std::cout << std::endl << "test metody push_front..." << std::endl;
    MyDeque<int> deque;
    deque.push_front(10);
    deque.push_front(20);
    assert(deque.front() == 20);
    assert(deque.back() == 10);
    assert(deque.size() == 2);

    std::cout << "zakonczono pomyslnie test metody push_front" << std::endl;
}

void test_push_back(){
    std::cout << std::endl << "test metody push_back..." << std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    deque.push_back(20);
    assert(deque.front() == 10);
    assert(deque.back() == 20);
    assert(deque.size() == 2);

    std::cout << "zakonczono pomyslnie test metody push_back" << std::endl;
}

void test_pop_front(){
    std::cout << std::endl << "test metody pop_front..." << std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    deque.push_back(20);
    deque.pop_front();
    assert(deque.front() == 20);
    assert(deque.size() == 1);
    deque.pop_front();
    assert(deque.empty());

    std::cout << "zakonczono pomyslnie test metody pop_front" << std::endl;
}

void test_pop_back(){
    std::cout << std::endl << "test metody pop_back..." << std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    deque.push_back(20);
    deque.pop_back();
    assert(deque.back() == 10);
    assert(deque.size() == 1);
    deque.pop_back();
    assert(deque.empty());

    std::cout << "zakonczono pomyslnie test metody pop_back" << std::endl;
}

void test_size(){
    std::cout << std::endl << "test metody size..." << std::endl;
    MyDeque<int> deque;
    assert(deque.size() == 0);
    deque.push_back(10);
    deque.push_back(20);
    assert(deque.size() == 2);

    std::cout << "zakonczono pomyslnie test metody size" << std::endl;
}

void test_clear(){
    std::cout << std::endl << "test metody clear..." << std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    deque.push_back(20);
    deque.clear();
    assert(deque.empty());

    std::cout << "zakonczono pomyslnie test metody clear" << std::endl;
}

void test_display(){
    std::cout << std::endl << "test metody display..." << std::endl;
    MyDeque<int> deque;

    std::cout << "oczekiwany wynik (pusta lista): ''" << std::endl;
    deque.display();

    deque.push_back(10);
    deque.push_back(20);
    deque.push_back(30);
    
    std::cout << "oczekiwany wynik: 10 20 30" << std::endl;
    deque.display();

    deque.pop_back();
    std::cout << "oczekiwany wynik: 10 20" << std::endl;
    deque.display();

    std::cout << "zakonczono pomyslnie test metody display" << std::endl;
}

void test_display_reversed(){
    std::cout << std::endl << "test metody display_reversed..." << std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    deque.push_back(20);
    deque.push_back(30);
    
    std::cout << "oczekiwany wynik: 30 20 10" << std::endl;
    deque.display_reversed();

    assert(deque.front() == 10); 
    assert(deque.back() == 30);
    assert(deque.size() == 3);

    std::cout << "zakonczono pomyslnie test metody display_reversed" << std::endl;
}

void test_copy_constructor(){
    std::cout << std::endl << "test metody copy_constructor..." << std::endl;
    MyDeque<int> deque1;
    deque1.push_back(10);
    deque1.push_back(20);
    
    MyDeque<int> deque2(deque1);
    assert(deque2.size() == 2);
    assert(deque2.front() == 10);
    assert(deque2.back() == 20);

    std::cout << "zakonczono pomyslnie test metody copy_constructor" << std::endl;
}

void test_operator_assignment(){
    std::cout << std::endl << "test metody operator=..." << std::endl;
    MyDeque<int> deque1;
    deque1.push_back(10);
    deque1.push_back(20);
    
    MyDeque<int> deque2;
    deque2.push_back(30); // Test, czy działa poprawne przypisanie
    deque2 = deque1;
    
    assert(deque2.size() == 2);
    assert(deque2.front() == 10);
    assert(deque2.back() == 20);

    std::cout << "zakonczono pomyslnie test metody operator=" << std::endl;
}

void test_front(){
    std::cout << std::endl << "test metody front..." << std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    assert(deque.front() == 10);
    deque.push_front(20);
    assert(deque.front() == 20); 
    deque.pop_front();
    assert(deque.front() == 10); 

    std::cout << "zakonczono pomyslnie test metody front" << std::endl;
}

void test_back(){
    std::cout << std::endl << "test metody back..." << std::endl;
    MyDeque<int> deque;
    deque.push_back(10);
    assert(deque.back() == 10);
    deque.push_back(20);
    assert(deque.back() == 20);
    deque.pop_back();
    assert(deque.back() == 10);

    std::cout << "zakonczono pomyslnie test metody back" << std::endl;
}

int main(){
    std::cout << "Testy deque" << std::endl;

    test_empty();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_size();
    test_clear();
    test_copy_constructor();
    test_operator_assignment();
    test_front();
    test_back();
    
    std::cout << std::endl << "-----------------------" << std::endl;
    test_display();
    std::cout << std::endl << "-----------------------" << std::endl;
    test_display_reversed();

    std::cout << std::endl << "Wszystkie testy zakonczone pomyslnie." << std::endl;
    
    return 0;
}
