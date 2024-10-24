#include "singlelist.h"

void test_push_front(){
    SingleList<int> list;
    list.push_front(10);
    list.push_front(20);
    assert(list.front()==20);
    assert(list.back()==10);
    assert(list.size()==2);
}

void test_push_back(){
    SingleList<int> list;
    list.push_back(10);
    list.push_back(20);
    assert(list.front()==10);
    assert(list.back()==20);
    assert(list.size()==2);
}

void test_pop_front(){
    SingleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_front();
    assert(list.front()==20);
    assert(list.size()==1);
    list.pop_front();
    assert(list.empty());
}

void test_pop_back(){
    SingleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.pop_back();
    assert(list.back()==10);
    assert(list.size()==1);
    list.pop_back();
    assert(list.empty());
}

void test_size(){
    SingleList<int> list;
    assert(list.size()==0);
    list.push_back(10);
    list.push_back(20);
    assert(list.size()==2);
}

void test_clear(){
    SingleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.clear();
    assert(list.empty());
}

void test_reverse(){
    SingleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.reverse();
    assert(list.front()==30);
    assert(list.back()==10);
    assert(list.size()==3);
}

void test_copy_constructor(){
    SingleList<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    
    SingleList<int> list2(list1);
    assert(list2.size()==2);
    assert(list2.front()==10);
    assert(list2.back()==20);
}

void test_operator(){
    SingleList<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    
    SingleList<int> list2;
    list2.push_back(30); 
    list2 = list1;
    
    assert(list2.size()==2);
    assert(list2.front()==10);
    assert(list2.back()==20);
}

int main(){

    std::cout << "Test listy jednokierunkowej" << std::endl;

    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_size();
    test_clear();
    test_reverse();
    test_copy_constructor();
    test_operator();
    
    std::cout << "Testy zakonoczone pomyslnie" << std::endl;
    return 0;
}
