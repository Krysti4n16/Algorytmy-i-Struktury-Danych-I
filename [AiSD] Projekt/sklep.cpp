#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>

void StronaStartowa() {
    std::cout << "************************************************************" << std::endl;
    std::cout << "*                  Sklep Wedkarski \"Barwena\"             *" << std::endl;
    std::cout << "*              Projekt obiektowej aplikacji C++            *" << std::endl;
    std::cout << "*       											         *" << std::endl;
    std::cout << "************************************************************" << std::endl;


    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    system("clear");
}

void wyswietl_kategorie() {
    std::cout << "Wybierz kategorie produktu: " << std::endl;
    std::cout << "1. Wedki" << std::endl;
    std::cout << "2. Kolowrotki" << std::endl;
    std::cout << "3. Przynety" << std::endl;
    std::cout << "4. Splawiki" << std::endl;
    std::cout << "5. Zylki i plecionki" << std::endl;
    std::cout << "6. Akcesoria" << std::endl;
    std::cout << "7. Wyswietl koszyk" << std::endl;
    std::cout << "8. Zakoncz zakupy" << std::endl << "Wybor: " << std::endl;
}



class Produkt {
public:
    virtual void wyswietl() = 0;
    virtual double pobierzCene() const = 0;
    virtual ~Produkt() = default;
};



/*class SklepWedkarski {
public:

    void pokaz(Produkt* produkt) {
        produkt->wyswietl();
    }

};*/

class Wedka :public Produkt {
public:

    Wedka(std::string n, double c, std::string p) : nazwa(n), cena(c), parametr(p) {}
    Wedka() : nazwa("brak"), cena(0.0), parametr("brak") {}

    void wyswietl() override {
        std::cout << "Nazwa: " << nazwa << " Cena" << cena << " Dlugosc:" << parametr << " m" << std::endl;
    }
    std::string nazwa;
    double cena;
    std::string parametr;

    void ustaw(std::string naz, double cen, std::string par)
    {
        nazwa = naz;
        cena = cen;
        parametr = par;
    }

    double pobierzCene() const override{
        return cena;
    }
};


//kolowrotek nie ma parametru

class Kolowrotek : public Produkt {
public:
    Kolowrotek(const std::string& n, double c, const std::string& p)
        : nazwa(n), cena(c), parametr(p) {}
    Kolowrotek() : nazwa("brak"), cena(0.0), parametr("brak") {}

    void wyswietl() override {
        std::cout << "Nazwa: " << nazwa << " Cena: " << cena << std::endl;
    }

    void ustaw(const std::string& naz, double cen, const std::string& par) {
        nazwa = naz;
        cena = cen;
        parametr = par;
    }

    double pobierzCene() const override{
        return cena;
    }

private:
    std::string nazwa;
    double cena;
    std::string parametr;
};


// przyneta ma kolor

class Przyneta : public Produkt {
public:
    Przyneta(const std::string& n, double c, const std::string& p)
        : nazwa(n), cena(c), parametr(p) {}
    Przyneta() : nazwa("brak"), cena(0.0), parametr("brak") {}

    void wyswietl() override {
        std::cout << "Nazwa: " << nazwa << " Cena: " << cena << " Kolor: " << parametr << std::endl;
    }

    void ustaw(const std::string& naz, double cen, const std::string& par) {
        nazwa = naz;
        cena = cen;
        parametr = par;
    }

    double pobierzCene() const override{
        return cena;
    }

private:
    std::string nazwa;
    double cena;
    std::string parametr;
};

//parametr w splawiku to rodzaj

class Splawik : public Produkt {
public:
    Splawik(const std::string& n, double c, const std::string& p)
        : nazwa(n), cena(c), parametr(p) {}
    Splawik() : nazwa("brak"), cena(0.0), parametr("brak") {}

    void wyswietl() override {
        std::cout << "Nazwa: " << nazwa << " Cena: " << cena << " Rodzaj: " << parametr << std::endl;
    }

    void ustaw(const std::string& naz, double cen, const std::string& par) {
        nazwa = naz;
        cena = cen;
        parametr = par;
    }

    double pobierzCene() const override{
        return cena;
    }

private:
    std::string nazwa;
    double cena;
    std::string parametr;
};

//parametr w splawiku to grubosc 
class Zylka : public Produkt {
public:
    Zylka(const std::string& n, double c, const std::string& p)
        : nazwa(n), cena(c), parametr(p) {}
    Zylka() : nazwa("brak"), cena(0.0), parametr("brak") {}

    void wyswietl() override {
        std::cout << "Nazwa: " << nazwa << " Cena: " << cena << " Grubosc: " << parametr << " mm" << std::endl;
    }

    void ustaw(const std::string& naz, double cen, const std::string& par) {
        nazwa = naz;
        cena = cen;
        parametr = par;
    }

    double pobierzCene() const override{
        return cena;
    }

private:
    std::string nazwa;
    double cena;
    std::string parametr;
};


//akcesoria bez parametru
class Akcesoria : public Produkt {
public:
    Akcesoria(const std::string& n, double c, const std::string& p)
        : nazwa(n), cena(c), parametr(p) {}
    Akcesoria() : nazwa("brak"), cena(0.0), parametr("brak") {}

    void wyswietl() override {
        std::cout << "Nazwa: " << nazwa << " Cena: " << cena << std::endl;
    }

    void ustaw(const std::string& naz, double cen, const std::string& par) {
        nazwa = naz;
        cena = cen;
        parametr = par;
    }

    double pobierzCene() const override{
        return cena;
    }

private:
    std::string nazwa;
    double cena;
    std::string parametr;
};

class Kup {
private:
    class Koszyk {
    public:
        void dodajProdukt(Produkt* produkt) {
            produkty.push_back(produkt);
        }

        void wyczyscKoszyk() {
            produkty.clear();
        }

        const std::vector<Produkt*>& getProdukty() const {
            return produkty;
        }

    private:
        std::vector<Produkt*> produkty;
    };

    Koszyk koszyk;

    double koszykowyKoszt() const {
        double koszt = 0.0;
        for (Produkt* produkt : koszyk.getProdukty()) {
            koszt += produkt->pobierzCene();
        }
        return koszt;
    }

    std::string czasAktualny() {
    std::time_t teraz = std::time(nullptr);
    std::tm czasTeraz;
    localtime_r(&teraz, &czasTeraz);
    
    char czasChar[80];
    std::strftime(czasChar, sizeof(czasChar), "%Y-%m-%d %H:%M:%S", &czasTeraz);

    return std::string(czasChar);
}

    
public:
    void dodajProduktDoKoszyka(Produkt* produkt) {
        koszyk.dodajProdukt(produkt);
    }

    void dokonajZakupu() {
        std::ofstream raport("raport.txt", std::ios::app);

        raport << "Data zakupu: " << czasAktualny() << std::endl;
        raport << "Koszt całkowity zakupow: " << koszykowyKoszt() << " PLN" << std::endl;
        raport << "---------------------------------------------" << std::endl;

        std::cout << "Kupione produkty: " << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        for (Produkt* produkt : koszyk.getProdukty()) {
            produkt->wyswietl();
            std::cout << std::endl;
        }

        std::cout << std::endl << "Za zakupy zaplacisz: " << koszykowyKoszt() << " PLN" << std::endl;

        raport.close();
        koszyk.wyczyscKoszyk();
    }

    void wyswietlKoszyk() {
        if (koszyk.getProdukty().empty()) {
            std::cout << "Koszyk jest pusty" << std::endl;
        } 
        else {
            std::cout << "Zawartosc koszyka:" << std::endl;
            for (Produkt* produkt : koszyk.getProdukty()) {
                produkt->wyswietl();
            }
            std::cout << "Laczna kwota: " << koszykowyKoszt() << " PLN" << std::endl;
        }
    }
};

int main() {

    StronaStartowa();

    //SklepWedkarski sklep;
    Kup kupowanie;

    Wedka wedki[5]; int wedkii = 0;
    Kolowrotek kolowrotki[5]; int kolowrotkii = 0;
    Przyneta przynety[7]; int przynetyi = 0;
    Splawik splawiki[6]; int splawikii = 0;
    Zylka zylki[6]; int zylkii = 0;
    Akcesoria akcesor[9]; int akcesori = 0;


    std::string n, p;
    int c, kategoria;


    std::ifstream plik_wejsciowy("produkty.txt");

    while (plik_wejsciowy >> n >> c >> p >> kategoria)
    {

        //cout<<n<<" "<<c<<" "<<p<<" "<<kategoria<<endl;

        switch (kategoria) {
        case 1:
            wedki[wedkii].ustaw(n, c, p);
            wedkii++;
            break;

        case 2:
            kolowrotki[kolowrotkii].ustaw(n, c, p);
            kolowrotkii++;
            break;

        case 3:
            przynety[przynetyi].ustaw(n, c, p);
            przynetyi++;
            break;

        case 4:
            splawiki[splawikii].ustaw(n, c, p);
            splawikii++;
            break;

        case 5:
            zylki[zylkii].ustaw(n, c, p);
            zylkii++;
            break;

        case 6:
            akcesor[akcesori].ustaw(n, c, p);
            akcesori++;
            break;

        default:
            // Obsługa sytuacji, gdy kategoria jest nieznana
            break;
        }

    }
    int koniec_zakupow = 0;

    while (!koniec_zakupow)
    {

        wyswietl_kategorie();

        std::cin >> kategoria;

        system("clear");

        if (kategoria == 1) {
            std::cout << "-----------------------------------------" << std::endl;
            for (int i = 0; i < wedkii; i++)
            {
                std::cout << " " << i+1 << ".  ";
                wedki[i].wyswietl();
            }
            std::cout << "-----------------------------------------" << std::endl;
            int wybieranie = -1;
            std::cout << "Ktory prokdukt dodac do koszyka: " << std::endl;
            std::cin >> wybieranie;
            kupowanie.dodajProduktDoKoszyka(&wedki[wybieranie-1]);

        }
        else if (kategoria == 2) {
            std::cout << "-----------------------------------------" << std::endl;
            for (int i = 0; i < kolowrotkii; i++)
            {
                std::cout << " " << i+1 << ".  ";
                kolowrotki[i].wyswietl();

            }
            std::cout << "-----------------------------------------" << std::endl;
            int wybieranie = -1;
            std::cout << "Ktory prokdukt dodac do koszyka: " << std::endl;
            std::cin >> wybieranie;
            kupowanie.dodajProduktDoKoszyka(&kolowrotki[wybieranie-1]);

        }
        else if (kategoria == 3) {
            std::cout << "-----------------------------------------" << std::endl;
            for (int i = 0; i <przynetyi; i++)
            {
                std::cout << " " << i+1 << ".  ";
                przynety[i].wyswietl();
            }
            std::cout << "-----------------------------------------" << std::endl;
            int wybieranie = -1;
            std::cout << "Ktory prokdukt dodac do koszyka: " << std::endl;
            std::cin >> wybieranie;
            kupowanie.dodajProduktDoKoszyka(&przynety[wybieranie-1]);

        }
        else if (kategoria == 4) {
            std::cout << "-----------------------------------------" << std::endl;
            for (int i = 0; i <splawikii; i++)
            {
                std::cout << " " << i+1 << ".  ";
                splawiki[i].wyswietl();
            }
            std::cout << "-----------------------------------------" << std::endl;
            int wybieranie = -1;
            std::cout << "Ktory prokdukt dodac do koszyka: " << std::endl;
            std::cin >> wybieranie;
            kupowanie.dodajProduktDoKoszyka(&splawiki[wybieranie-1]);

        }
        else if (kategoria == 5) {
            std::cout << "-----------------------------------------" << std::endl;
            for (int i = 0; i <zylkii; i++)
            {
                std::cout << " " << i+1 << ".  ";
                zylki[i].wyswietl();
            }
            std::cout << "-----------------------------------------" << std::endl;
            int wybieranie = -1;
            std::cout << "Ktory prokdukt dodac do koszyka: " << std::endl;
            std::cin >> wybieranie;
            kupowanie.dodajProduktDoKoszyka(&zylki[wybieranie-1]);

        }
        else if (kategoria == 6) {
            std::cout << "-----------------------------------------" << std::endl;
            for (int i = 0; i <akcesori; i++)
            {
                std::cout << " " << i+1 << ".  ";
                akcesor[i].wyswietl();
            }
            std::cout << "-----------------------------------------" << std::endl;
            int wybieranie = -1;
            std::cout << "Ktory prokdukt dodac do koszyka: " << std::endl;
            std::cin >> wybieranie;
            kupowanie.dodajProduktDoKoszyka(&akcesor[wybieranie-1]);
        }
    
        else if (kategoria == 7) {
            kupowanie.wyswietlKoszyk();
            std::cout << "Nacisnij Enter, aby kontynuować...";
            std::cin.ignore();
            std::cin.get();
        }

        else if (kategoria == 8) {
            koniec_zakupow = 1;
        }

        system("clear");


    }
    kupowanie.dokonajZakupu();
    plik_wejsciowy.close();
    return 0;
}
