#include<iostream>
#include<cstdlib>
#include<time.h>
#include<chrono>

using namespace std;

int* tab_scal;
void scal(int tab[], int poczatek, int mid, int koniec){
    for(int i=poczatek; i<=koniec; i++){
        tab_scal[i]=tab[i];
    }
    int i=poczatek;
    int j=mid+1;
    for(int k=poczatek; k<=koniec;k++){
        if(i<=mid){
            if(j<=koniec){
                if(tab_scal[j]<tab_scal[i]){
                    tab[k]=tab_scal[j++];
                } 
                else{
                    tab[k]=tab_scal[i++];
                }
            } 
            else{
                tab[k]=tab_scal[i++];
            }
        } 
        else{
            tab[k]=tab_scal[j++];
        }
    }
}

void mergesort(int tab[], int poczatek, int koniec){
    if(poczatek>=koniec){
        return;
    }
    int mid=(poczatek+koniec)/2;
    mergesort(tab, poczatek, mid);
    mergesort(tab, mid + 1, koniec);
	scal(tab, poczatek, mid, koniec);
}


int main(){
    int* tab;
    int n,liczba; 
	
    cout << "Podaj ile elementow bedzie miec tabllica:" << endl;
	cin>>n;
    if(n<0){
        cout << "Nieprawidlowa liczba,spodziewano liczby >0" << endl;
        return 0;
    }
	tab= new int[n]; 
	tab_scal= new int[n]; 
	srand(time(NULL));

    cout << "Nieposortowana losowa tablica" << endl;
	for(int i=0;i<n;i++){
        liczba=rand()%100+1; //generuje losowe liczby od 1 do 100
        tab[i]=liczba;
        cout << tab[i] << " ";
    }
	auto start= std::chrono::high_resolution_clock::now();
	mergesort(tab,0,n-1);
    auto stop= std::chrono::high_resolution_clock::now();
    auto duration= std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	
    cout << endl << "Posortowana tablica:" << endl;
	for(int j=0;j<n;j++){
		cout<<tab[j]<<" ";
    }
    cout << endl << "Czas trawania algorytmu sortowania wynosi: " << duration.count() << " nanosekund." << endl;
	
    return 0;
}
