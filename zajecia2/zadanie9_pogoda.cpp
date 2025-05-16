#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct pogoda
{
    string data;
    string czas;
    double predkosc_dzwieku;
    double temp_dzwiekiem;
    double cisnienie;
    double temp;
    double wilgotnosc;
    double kompas;
    double predkosc_uv;
    double predkosc_wiatru;
    double kierunek;
    double wysokosc;
    double temp_113;
};

void sort_by_temp(vector<pogoda> &dane){

}

int main()
{
    fstream file("C:\\Users\\User\\Downloads\\temp02-2020.csv", ios::in);

    string line;
    getline(file, line); // odrzucenie pierwszej linii (nagłówki)

    vector<pogoda> dane;

    while (getline(file, line)) {
        stringstream ss(line);
        pogoda strc;
        string temp_var;

        getline(ss, strc.data, ',');
        getline(ss, strc.czas, ',');

        getline(ss, temp_var, ',');
        strc.predkosc_dzwieku = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.temp_dzwiekiem = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.cisnienie = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.temp = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.wilgotnosc = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.kompas = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.predkosc_uv = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.predkosc_wiatru = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.kierunek = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.wysokosc = stod(temp_var);

        getline(ss, temp_var, ',');
        strc.temp_113 = stod(temp_var);

        dane.push_back(strc);
    }

    std::sort(dane.begin(), dane.end(), [](pogoda a, pogoda b){
        return a.temp > b.temp;
    });

    // Przykład wypisania pierwszych 5 rekordów
    for (int i = 0; i < dane.size() && i < 10; ++i) {
        const pogoda& p = dane[i];
        cout << p.data << ", "
             // << p.czas << ", "
             // << p.predkosc_dzwieku << ", "
             // << p.temp_dzwiekiem << ", "
             // << p.cisnienie << ", "
             << p.temp << ", "
             // << p.wilgotnosc << ", "
             // << p.kompas << ", "
             // << p.predkosc_uv << ", "
             // << p.predkosc_wiatru << ", "
             // << p.kierunek << ", "
             // << p.wysokosc << ", "
             << p.temp_113 << endl;
    }

    cout << "==================================================" << endl << endl;
    std::sort(dane.begin(), dane.end(), [](pogoda a, pogoda b){
        return a.temp < b.temp;
    });

    for (int i = 0; i < dane.size() && i < 10; ++i) {
        const pogoda& p = dane[i];
        cout << p.data << ", "
             // << p.czas << ", "
             // << p.predkosc_dzwieku << ", "
             // << p.temp_dzwiekiem << ", "
             // << p.cisnienie << ", "
             << p.temp << ", "
             // << p.wilgotnosc << ", "
             // << p.kompas << ", "
             // << p.predkosc_uv << ", "
             // << p.predkosc_wiatru << ", "
             // << p.kierunek << ", "
             // << p.wysokosc << ", "
             << p.temp_113 << endl;
    }

    size_t rozmiar = dane.size();
    if(rozmiar%2==1){
        cout << "mediana to: " << dane[rozmiar/2].temp;
    }
    else{
        double mid = rozmiar/2;
        double result = dane[(ceil(mid)+ceil(mid)-1)/2].temp;
        cout << "Mediana to: " << result;
    }

    return 0;
}
