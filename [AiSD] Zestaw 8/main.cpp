#include "myqueue.h"

void test_empty(){
    MyQueue<int> q;
    assert(q.empty());
    q.push(10);
    assert(!q.empty());
    q.pop();
    assert(q.empty());
    std::cout << "test_empty zakonczono" << std::endl;
}

void test_full(){
    MyQueue<int> q(3);
    assert(!q.full());
    q.push(1);
    q.push(2);
    q.push(3);
    assert(q.full()); 
    q.pop();
    assert(!q.full());
    std::cout << "test_full zakonczono" << std::endl;
}

void test_size(){
    MyQueue<int> q(3);
    assert(q.size() == 0);
    q.push(1);
    assert(q.size() == 1);
    q.push(2);
    assert(q.size() == 2);
    q.pop();
    assert(q.size() == 1);
    std::cout << "test_size zakonczono" << std::endl;
}

void test_max_size(){
    MyQueue<int> q(5);
    assert(q.max_size() == 5);
    std::cout << "test_max_size zakonczono" << std::endl;
}

void test_push(){
    MyQueue<int> q(2);
    q.push(1);
    q.push(2);
    assert(q.size() == 2);
    assert(q.full()); 
    std::cout << "test_push zakonczono" << std::endl;
}

void test_pop(){
    MyQueue<int> q;
    q.push(1);
    q.push(2);
    assert(q.size() == 2);
    q.pop();
    assert(q.size() == 1);
    assert(q.front() == 2);
    q.pop();
    assert(q.empty());
    std::cout << "test_pop zakonczono" << std::endl;
}

void test_front_back(){
    MyQueue<int> q;
    q.push(1);
    q.push(2);
    assert(q.front() == 1);
    assert(q.back() == 2);
    q.pop();
    assert(q.front() == 2);
    std::cout << "test_front_back zakonczono" << std::endl;
}

void test_clear(){
    MyQueue<int> q;
    q.push(1);
    q.push(2);
    q.clear();
    assert(q.empty());
    assert(q.size() == 0);
    std::cout << "test_clear zakonczono" << std::endl;
}

void test_copy_constructor(){
    MyQueue<int> q1;
    q1.push(1);
    q1.push(2);
    MyQueue<int> q2(q1);
    assert(q2.size() == q1.size());
    assert(q2.front() == q1.front());
    assert(q2.back() == q1.back());
    std::cout << "test_copy_constructor zakonczono" << std::endl;
}

void test_move_constructor(){
    MyQueue<int> q1;
    q1.push(1);
    q1.push(2);
    MyQueue<int> q2(std::move(q1));
    assert(q2.size() == 2);
    assert(q1.empty());
    std::cout << "test_move_constructor zakonczono" << std::endl;
}

void test_copy_assignment(){
    MyQueue<int> q1;
    q1.push(1);
    q1.push(2);
    MyQueue<int> q2;
    q2 = q1; //kopiowanie
    assert(q2.size() == q1.size());
    assert(q2.front() == q1.front());
    std::cout << "test_copy_assignment zakonczono" << std::endl;
}

void test_move_assignment() {
    MyQueue<int> q1;
    q1.push(1);
    q1.push(2);
    MyQueue<int> q2;
    q2 = std::move(q1); //przeniesienie
    assert(q2.size() == 2);
    assert(q1.empty());
    std::cout << "test_move_assignment zakonczono" << std::endl;
}

int main(){
    std::cout << "Testy myqueue..." << std::endl << std::endl;
    test_empty();
    test_full();
    test_size();
    test_max_size();
    test_push();
    test_pop();
    test_front_back();
    test_clear();
    test_copy_constructor();
    test_move_constructor();
    test_copy_assignment();
    test_move_assignment();
    std::cout << std::endl << "Testy pomyslenie zakonczono" << std::endl;
    return 0;
}
