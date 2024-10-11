#include<iostream>
#include<algorithm>
#include<vector>
#include<cassert>
#include<array>

//Sortowanie przez scalanie(mergesort)
template<typename T>
void scal(T* tab, int poczatek, int mid, int koniec){
    T* tab_scal= new T[koniec+1];

    for(int i= poczatek; i<=koniec;i++){
        tab_scal[i]= tab[i];
    }
    int i= poczatek;
    int j= mid+1;
    for(int k= poczatek; k<=koniec;k++){
        if(i<=mid){
            if(j<=koniec){
                if(tab_scal[j]<tab_scal[i]){
                    tab[k]= tab_scal[j++];
                }
                else{
                    tab[k]= tab_scal[i++];
                }
            }
            else{
                tab[k]= tab_scal[i++];
            }
        }
        else{
            tab[k]= tab_scal[j++];
        }
    }
    delete[] tab_scal;
}

template<typename T>
void mergesort(T* tab, int poczatek, int koniec){
    if(poczatek>=koniec){
        return;
    }
    int mid= (poczatek+koniec)/2;
    mergesort(tab, poczatek, mid);
    mergesort(tab, mid+1, koniec);
    scal(tab, poczatek, mid, koniec);
}

//Sortowanie babelkowe(bubblesort)
template<typename T>
void sortowanieBabelkowe(T* tab, int n){
    for(int i= 0;i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(tab[j]>tab[j+1]){
                std::swap(tab[j], tab[j+1]);
            }
        }
    }
}

//Funckja testujaca dla sortowania babelkowego
void vector_test(){
    std::cout <<"Test sortowania przez scalanie" << std::endl << "Test std::vector" << std::endl;

    std::vector<int> vec= { 10, 9, 7, 1, 3, 6, 4, 8, 5, 2 };

    std::cout << "Nieposortowany wektor: ";
    for(int i= 0; i<vec.size();i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;


    sortowanieBabelkowe(vec.data(), vec.size());

    std::cout << "Posortowany wektor: ";
    for(int i= 0; i<vec.size();i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    assert(std::is_sorted(vec.begin(), vec.end()));
    std::cout << "Test przeszedl pomyslnie" << std::endl;
}

//Funckja testujaca dla sortownia przez scalanie(mergesort)

void array_test(){
    std::cout << std::endl <<"Test sortowania babelkowego" << std::endl << "Test std::array" << std::endl;

    std::array<int, 10>arr= { 10, 9, 7, 1, 3, 6, 4, 8, 5, 2 };

    std::cout << "Nieposortowana tablica: ";
    for(int i= 0; i<arr.size();i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    mergesort(arr.data(), 0, arr.size()-1);

    std::cout << "Posortowana tablica: ";
    for(int i= 0; i<arr.size();i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    assert(std::is_sorted(arr.begin(), arr.end()));
    std::cout << "Test przeszedl pomyslnie" << std::endl;
}

int main(){
    vector_test();
    array_test();
}