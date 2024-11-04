#include "doublelist.h"

void test_empty(){
    std::cout << std::endl << "test metody empty..." << std::endl;
    DoubleList<int> list;
    assert(list.empty());

    list.push_back(10);
    assert(!list.empty());

    list.pop_back();
    assert(list.empty());

    std::cout << "zakonczono pomyslnie test metody empty" << std::endl;
}

void test_push_front(){
    std::cout << std::endl << "test metody push_front..." << std::endl;
    DoubleList<int> list;
    list.push_front(10);
    list.push_front(20);
    assert(list.front()== 20);
    assert(list.back()== 10);
    assert(list.size()== 2);
    std::cout << "zakonczono pomyslnie test metody push_front" << std::endl;
}

void test_push_back(){
    std::cout << std::endl << "test metody push_back..." << std::endl;
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    assert(list.front()== 10);
    assert(list.back()== 20);
    assert(list.size()== 2);
    std::cout << "zakonczono pomyslnie test metody push_back" << std::endl;
}

void test_display(){
    std::cout << std::endl << "test metody display..." << std::endl;
    DoubleList<int> list;

    std::cout << "oczekiwany wynik (pusta lista): ''" << std::endl;
    list.display();

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    std::cout << "oczekiwany wynik: 10 20 30" << std::endl;
    list.display();

    list.pop_back();
    std::cout << "oczekiwany wynik: 10 20" << std::endl;
    list.display();

    std::cout << "zakonczono pomyslnie test metody display" << std::endl;
}

void test_pop_front(){
    std::cout << std::endl << "test metody pop_front..." << std::endl;
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    assert(list.front()== 20);
    assert(list.size()== 1);
    list.pop_front();
    assert(list.empty());
    std::cout << "zakonczono pomyslnie test metody pop_front" << std::endl;
}

void test_pop_back(){
    std::cout << std::endl << "test metody pop_back..." << std::endl;
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    assert(list.back()== 10);
    assert(list.size()== 1);
    list.pop_back();
    assert(list.empty());
    std::cout << "zakonczono pomyslnie test metody pop_back" << std::endl;
}

void test_size(){
    std::cout << std::endl << "test metody size..." << std::endl;
    DoubleList<int> list;
    assert(list.size()== 0);
    list.push_back(10);
    list.push_back(20);
    assert(list.size()== 2);
    std::cout << "zakonczono pomyslnie test metody size" << std::endl;
}

void test_clear(){
    std::cout << std::endl << "test metody clear..." << std::endl;
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    assert(list.empty());
    std::cout << "zakonczono pomyslnie test metody clear" << std::endl;
}

void test_display_reversed(){
    std::cout << std::endl << "test metody display_reversed..." << std::endl;
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    
    std::cout << "oczekiwany wynik: 30 20 10" << std::endl;
    list.display_reversed();

    assert(list.front()== 10); 
    assert(list.back()== 30);
    assert(list.size()== 3);
    std::cout << std::endl << "zakonczono pomyslnie test metody display_reversed" << std::endl;
}

void test_copy_constructor(){
    std::cout << std::endl << "test metody copy_constructor..." << std::endl;
    DoubleList<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    
    DoubleList<int> list2(list1);
    assert(list2.size()== 2);
    assert(list2.front()== 10);
    assert(list2.back()== 20);
    std::cout << "zakonczono pomyslnie test metody copy_constructor" << std::endl;
}

void test_operator(){
    std::cout << std::endl << "test metody operator..." << std::endl;
    DoubleList<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    
    DoubleList<int> list2;
    list2.push_back(30); // Sprawdzamy, czy clear() dziala poprawnie
    list2 = list1;
    
    assert(list2.size()== 2);
    assert(list2.front()== 10);
    assert(list2.back()== 20);
    std::cout << "zakonczono pomyslnie test metody operator=" << std::endl;
}

void test_front(){
    std::cout << std::endl << "test metody front..." << std::endl;
    DoubleList<int> list;
    list.push_back(10);
    assert(list.front()== 10);
    list.push_front(20);
    assert(list.front()== 20); 
    list.pop_front();
    assert(list.front()== 10); 

    std::cout << "zakonczono pomyslnie test metody front" << std::endl;
}

void test_back(){
    std::cout << std::endl << "test metody back..." << std::endl;
    DoubleList<int> list;
    list.push_back(10);
    assert(list.back()== 10);
    list.push_back(20);
    assert(list.back()== 20);
    list.pop_back();
    assert(list.back()== 10);
    std::cout << "zakonczono pomyslnie test metody back" << std::endl;
}

int main(){
    std::cout << "Testy listy dwukierunkowej" << std::endl;

    test_empty();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_size();
    test_clear();
    test_copy_constructor();
    test_operator();
    test_front();
    test_back();
    
    std::cout << "\n-----------------------" << std::endl;
    test_display();
    std::cout << "\n-----------------------" << std::endl;
    test_display_reversed();

    std::cout << std::endl << "Wszystkie testy zakonczone pomyslnie." << std::endl;
    
    return 0;
}
