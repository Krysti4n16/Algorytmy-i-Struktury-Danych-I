#include "arraylist.h"
#include<array>

void table_test(){
    std::cout << std::endl << "Table test" << std::endl;
    
    //Tworzenie listy o rozmiarze 5
    ArrayList<int> list(5);
    
    //Sprawdzanie, czy lista jest początkowo pusta
    assert(list.empty());
    std::cout << "Lista jest pusta" << std::endl;
    
    //Dodawanie elementów na koniec listy
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    //Sprawdzanie, czy lista jest pełna po dodaniu 5 elementow
    assert(list.full());
    std::cout << "Lista jest pelna" << std::endl;

    //Wyświetlanie listy
    list.display();

    //Sprawdzanie wartości na poczatku i na koncu listy
    assert(list.front() == 10);
    assert(list.back() == 50);
    std::cout << "Pierwszy i ostatni elemnet sa poprawne" << std::endl;

    //Usuwanie elementu z poczatku listy
    list.pop_front();
    std::cout << "Lista po usunieciu elementu z pocztaku" << std::endl;
    list.display();

    //Usuwanie elementu z konca listy
    list.pop_back();
    std::cout << "Lista po usunieciu elementu z konca" << std::endl;
    list.display();

    //Dodawanie elementu na początek listy
    list.push_front(5);
    std::cout << "Lista po dodaniu elementu na pocztaku" << std::endl;
    list.display();

    //Sprawdzanie rozmiaru listy
    assert(list.size() == 4);
    assert(list.max_size() == 5);
    std::cout << "Rozmiar i max_size sa poparwne" << std::endl;

    //Czyszczenie listy
    list.clear();
    assert(list.empty());
    std::cout << "Lista jest pusta" << std::endl;

    std::cout << "Table test zakonczono pomyslnie" << std::endl;
}

void array_test() {
    std::cout << std::endl << "Array test" << std::endl;

    //Tworzenie listy o rozmiarze 10
    ArrayList<int> list(10);

    //Dodawanie elementów
    list.push_back(9);
    list.push_back(7);
    list.push_back(5);
    list.push_back(3);
    list.push_back(1);

    // Sprawdzanie elementu na początku i na końcu listy
    assert(list.front()==9);
    assert(list.back()==1);
    std::cout << "Element pocztatkowy i koncowy sa poprawne" << std:: endl;

    std::cout << "Stan listy przed sortowaniem: " << std::endl;
    list.display();

    list.sort();

    std::cout << "Stan listy po sortowaniu: " << std::endl;
    list.display();

    list.reverse();
    std::cout << "Stan listy po odwroceniu: " << std::endl;
    list.display();

    //Usuwanie elementów
    list.pop_back();
    list.pop_front();
    std::cout << "Stan listy po usunieciu elementu z pocztaku oraz konca: " << std::endl;
    list.display();

    //Test konstruktora kopiującego
    ArrayList<int> kopia_lista(list);
    std::cout << "Skopiowana lista: ";
    kopia_lista.display();

    //Modyfikowanie kopii i sprawdzanie czy oryginal pozostal taki sam
    kopia_lista.push_back(11);
    std::cout << "Zmodyfikowano kopie listy: " << std::endl;
    kopia_lista.display();
    std::cout << "Orginalna lista po modyfikacji kopii: " << std::endl;
    list.display();

    //Test operatora przypisania
    ArrayList<int> przypisana_lista(5);
    przypisana_lista= list;
    std::cout << "Przypisana lista: " << std::endl;
    przypisana_lista.display();

    std::cout << "Array test zakonczony pomyslnie " << std::endl;
}

int main(){
    table_test();
    std::cout << std::endl << "--------------------------" << std::endl;
    array_test();
    return 0;
}
