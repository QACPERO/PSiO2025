#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

                             using namespace std;

class Pojazd {
public:
    virtual ~Pojazd() = default;

    string nazwa;
    int miejsca;
    float pojemnosc;
    Pojazd(){};
    Pojazd(string n, float p, int m) : nazwa(n), miejsca(m), pojemnosc(p) {}
    Pojazd(string n, float p) :  nazwa(n), pojemnosc(p) {}
    virtual string toString()= 0;
};
class Auto : public Pojazd {
public:
    Auto(string n, float p, int m) : Pojazd(n,p,m) {}

    virtual string toString(){
        return "Typ: Auto, Nazwa: " + nazwa + ", Waga: " + to_string(pojemnosc) + ", kola: 4," + "siedzienia" + to_string(miejsca);
    }
};
class Motocykl : public Pojazd {
public:
    Motocykl(string n, float p, int m) : Pojazd(n,p,m) {}
    Motocykl(string n , float p) : Pojazd(n,p) {}

    virtual string toString(){
        return "Typ: Motocykl, Nazwa: " + nazwa + ", Waga: " + to_string(pojemnosc) + ", kola: 2," + "siedzienia" + to_string(miejsca);
    }
};

ostream &operator<<(ostream &os, Pojazd &p){
    os << p.toString();
    return os;
}

int main() {
    // PUNKTY DODATKOWE
    // 2: poprawne wykorzystanie polimorfizmu
    // 2: poprawne przekazanie parametrow konstruktora do zmiennych skladowych klasy
    // 2: poprawne przekazywanie przez referencje/wskaznik lub przez wartosc
    // 2: poprawne uzycie modyfikatora const

    // Uzupelnij implementacje klasy Pojazd i wyprowadzonych klas Auto i Motocykl
    // tak aby uruchomic poprawnie ponizszy kod
    // PUNKTY: 14
    using Pojazdy = std::vector<std::unique_ptr<Pojazd>>;
    Pojazdy pojazdy;
    pojazdy.emplace_back(std::make_unique<Auto>(Auto("Toyota Land Cruiser", 2500.0, 7)));
    pojazdy.emplace_back(std::make_unique<Auto>(Auto("Chevrolet Camaro v8", 1700.0, 4)));
    pojazdy.emplace_back(std::make_unique<Motocykl>(Motocykl("Ducati Panigale V4", 175.0)));

    // Skonstruuj operator wstawienia do strumienia tak aby obiekty byly wyswietlane jak ponizej:
    // Podpowiedz: dodaj i uzyj w operatorze metody wirtualnej toString() (Lab05.1.cpp)
    // Typ: Auto, Nazwa: Toyota Land Cruiser, Waga: 2500.000000, Kola: 4, Siedzenia: 7
    // Typ: Auto, Nazwa: Chevrolet Camaro v8, Waga: 1700.000000, Kola: 4, Siedzenia: 4
    // Typ: Motocykl, Nazwa: Ducati Panigale V4, Waga: 175.000000, Kola: 2
    // PUNKTY: 5

    for (auto& p: pojazdy)
        cout << *p << endl;

    cout << "===============================" << endl;

    // Posortuj obiekty wg nazwy (nie wg typu!)
    // Podpowiedz: dodaj i uzyj metody wirtualnej getName()
    // PUNKTY: 5
    // Powinno wyswietlac:
    // Typ: Auto, Nazwa: Chevrolet Camaro v8, Waga: 1700.000000, Kola: 4, Siedzenia: 4
    // Typ: Motocykl, Nazwa: Ducati Panigale V4, Waga: 175.000000, Kola: 2
    // Typ: Auto, Nazwa: Toyota Land Cruiser, Waga: 2500.000000, Kola: 4, Siedzenia: 7
    std::sort(pojazdy.begin(), pojazdy.end(), [](std::unique_ptr<Pojazd> &p1, std::unique_ptr<Pojazd> &p2){return p1->nazwa < p2->nazwa;});

    for (auto& p: pojazdy)
        cout << *p << endl;
    cout << "===============================" << endl;

    // Obiekty posortowane wg malejacej liczby kol i rosnacej wagi.
    // Podpowiedz: dodaj i uzyj dodatkowych metod wirtualnych wheels() i weight()
    // PUNKTY: 8
    // Powinno wyswietlac:
    // Typ: Auto, Nazwa: Chevrolet Camaro v8, Waga: 1700.000000, Kola: 4, Siedzenia: 4
    // Typ: Auto, Nazwa: Toyota Land Cruiser, Waga: 2500.000000, Kola: 4, Siedzenia: 7
    // Typ: Motocykl, Nazwa: Ducati Panigale V4, Waga: 175.000000, Kola: 2
    std::sort(pojazdy.begin(), pojazdy.end(), [](std::unique_ptr<Pojazd> &p1, std::unique_ptr<Pojazd> &p2){
        if(p1->miejsca>p2->miejsca){
            return true;
        }
        else if(p1->miejsca<p2->miejsca){
            return false;
        }
        else{
            if(p1->pojemnosc > p2->pojemnosc) return true;
            else return false;
        }
    });

    for (auto& p: pojazdy)
        cout << *p << endl;
    cout << "===============================" << endl;

    return 0;
}
