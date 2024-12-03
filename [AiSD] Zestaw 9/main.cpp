#include"priority.h"
#include<cassert>

void test_empty(){
    MyPriorityQueue<int> pq;
    assert(pq.empty() == true);
    pq.push(10);
    assert(pq.empty() == false);
    std::cout << "test_empty zakonczono" << std::endl;
}

void test_size(){
    MyPriorityQueue<int> pq;
    assert(pq.size() == 0);
    pq.push(10);
    pq.push(20);
    assert(pq.size() == 2);
    std::cout << "test_size zakonczono" << std::endl;
}

void test_push_and_top(){
    MyPriorityQueue<int> pq;
    pq.push(10);
    assert(pq.top() == 10);
    pq.push(20);
    assert(pq.top() == 20);
    pq.push(5);
    assert(pq.top() == 20);
    std::cout << "test_push_and_top zakonczono" << std::endl;
}

void test_pop(){
    MyPriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    assert(pq.top() == 20);
    pq.pop();
    assert(pq.top() == 10);
    pq.pop();
    assert(pq.top() == 5);
    pq.pop();
    assert(pq.empty() == true);
    std::cout << "test_pop zakonczono" << std::endl;
}

void test_clear(){
    MyPriorityQueue<int> pq;
    pq.push(10);
    pq.push(20);
    assert(pq.size() == 2);
    pq.clear();
    assert(pq.size() == 0);
    assert(pq.empty() == true);
    std::cout << "test_clear zakonczono" << std::endl;
}

void test_copy_constructor(){
    MyPriorityQueue<int> pq1;
    pq1.push(10);
    pq1.push(20);
    MyPriorityQueue<int> pq2 = pq1; //konstruktor kopiujacy
    assert(pq2.size() == pq1.size());
    assert(pq2.top() == pq1.top());
    std::cout << "test_copy_constructor zakonczono" << std::endl;
}

void test_move_constructor(){
    MyPriorityQueue<int> pq1;
    pq1.push(10);
    pq1.push(20);
    MyPriorityQueue<int> pq2 = std::move(pq1); //konstruktor przenoszacy
    assert(pq2.size() == 2);
    assert(pq1.size() == 0);
    std::cout << "test_move_constructor zakonczono" << std::endl;
}

void test_copy_assignment(){
    MyPriorityQueue<int> pq1;
    pq1.push(10);
    pq1.push(20);
    MyPriorityQueue<int> pq2;
    pq2 = pq1;
    assert(pq2.size() == pq1.size());
    assert(pq2.top() == pq1.top());
    std::cout << "test_copy_assignment zakonczono" << std::endl;
}

void test_move_assignment(){
    MyPriorityQueue<int> pq1;
    pq1.push(10);
    pq1.push(20);
    MyPriorityQueue<int> pq2;
    pq2 = std::move(pq1);
    assert(pq2.size() == 2);
    assert(pq1.size() == 0);
    std::cout << "test_move_assignment zakonczono" << std::endl;
}

int main(){
    std::cout << "Testy priority queue..." << std::endl << std::endl;
    test_empty();
    test_size();
    test_push_and_top();
    test_pop();
    test_clear();
    test_copy_constructor();
    test_move_constructor();
    test_copy_assignment();
    test_move_assignment();
    std::cout << std::endl << "Testy pomyslenie zakonczono" << std::endl;
    return 0;
}
