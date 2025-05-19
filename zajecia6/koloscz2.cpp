#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Pojazd {
public:
    virtual string toString() = 0;
    virtual string getName() = 0;
    virtual int wheels() = 0;
    virtual double weight() = 0;
    virtual ~Pojazd() {}
};

class Auto : public Pojazd {
    string name;
    double waga;
    int siedzenia;
public:
    Auto(string n, double w, int s) : name(n), waga(w), siedzenia(s) {}
    string toString() {
        return "Typ: Auto, Nazwa: " + name + ", Waga: " + to_string(waga) + ", Kola: 4, Siedzenia: " + to_string(siedzenia);
    }
    string getName() { return name; }
    int wheels() { return 4; }
    double weight() { return waga; }
};

class Motocykl : public Pojazd {
    string name;
    double waga;
public:
    Motocykl(string n, double w) : name(n), waga(w) {}
    string toString() {
        return "Typ: Motocykl, Nazwa: " + name + ", Waga: " + to_string(waga) + ", Kola: 2";
    }
    string getName() { return name; }
    int wheels() { return 2; }
    double weight() { return waga; }
};

ostream& operator<<(ostream& os, Pojazd& p) {
    return os << p.toString();
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
    using Pojazdy = vector<unique_ptr<Pojazd>>;
    Pojazdy pojazdy;
    pojazdy.emplace_back(make_unique<Auto>("Toyota Land Cruiser", 2500.0, 7));
    pojazdy.emplace_back(make_unique<Auto>("Chevrolet Camaro v8", 1700.0, 4));
    pojazdy.emplace_back(make_unique<Motocykl>("Ducati Panigale V4", 175.0));

    // Skonstruuj operator wstawienia do strumienia tak aby obiekty byly wyswietlane jak ponizej:
    // Podpowiedz: dodaj i uzyj w operatorze metody wirtualnej toString() (Lab05.1.cpp)
    // Typ: Auto, Nazwa: Toyota Land Cruiser, Waga: 2500.000000, Kola: 4, Siedzenia: 7
    // Typ: Auto, Nazwa: Chevrolet Camaro v8, Waga: 1700.000000, Kola: 4, Siedzenia: 4
    // Typ: Motocykl, Nazwa: Ducati Panigale V4, Waga: 175.000000, Kola: 2
    // PUNKTY: 5
    for (auto& p : pojazdy)
        cout << *p << endl;
    cout << "=======================" << endl;
    // Posortuj obiekty wg nazwy (nie wg typu!)
    // Podpowiedz: dodaj i uzyj metody wirtualnej getName()
    // PUNKTY: 5
    // Powinno wyswietlac:
    // Typ: Auto, Nazwa: Chevrolet Camaro v8, Waga: 1700.000000, Kola: 4, Siedzenia: 4
    // Typ: Motocykl, Nazwa: Ducati Panigale V4, Waga: 175.000000, Kola: 2
    // Typ: Auto, Nazwa: Toyota Land Cruiser, Waga: 2500.000000, Kola: 4, Siedzenia: 7
    sort(pojazdy.begin(), pojazdy.end(), [](auto& a, auto& b) {
        return a->getName() < b->getName();
    });
    for (auto& p : pojazdy)
        cout << *p << endl;
    cout << "=======================" << endl;
    // Obiekty posortowane wg malejacej liczby kol i rosnacej wagi.
    // Podpowiedz: dodaj i uzyj dodatkowych metod wirtualnych wheels() i weight()
    // PUNKTY: 8
    // Powinno wyswietlac:
    // Typ: Auto, Nazwa: Chevrolet Camaro v8, Waga: 1700.000000, Kola: 4, Siedzenia: 4
    // Typ: Auto, Nazwa: Toyota Land Cruiser, Waga: 2500.000000, Kola: 4, Siedzenia: 7
    // Typ: Motocykl, Nazwa: Ducati Panigale V4, Waga: 175.000000, Kola: 2
    sort(pojazdy.begin(), pojazdy.end(), [](auto& a, auto& b) {
        if (a->wheels() != b->wheels())
            return a->wheels() > b->wheels();
        return a->weight() < b->weight();
    });
    for (auto& p : pojazdy)
        cout << *p << endl;

    return 0;
}
