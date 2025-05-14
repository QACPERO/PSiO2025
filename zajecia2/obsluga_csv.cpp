#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Exchange_rate{
    string date;
    double usd;
    double eur;
    string table_id;
};

int main()
{
    std::fstream file("C:\\Users\\User\\Documents\\osbluga_pliku_csv\\kursy_usd_eur.csv", std::fstream::in);
    std::vector<Exchange_rate> rates;

    if(file.is_open()){
        std::string line; //tworzymy string do ktorego trafia cala linia
        std::getline(file, line); // pierwsza linia jest naglowkiem z nazwami kolumn wiec ja pomijamy
        while(std::getline(file,line)){
            //sposob drugi z ss
            stringstream ss(line); //przypisanie line do strumienia ss

            Exchange_rate er; //tworzecnie structa
            getline(ss, er.date, ','); //getline mozna uzwac: getline(input np. stringstream, string &docelowy, opcjonalny seprator np. "," wyjsciowo to \n)
            string usd_string;
            getline(ss, usd_string, ',');
            er.usd = stod(usd_string);
            string eur_string;
            getline(ss, eur_string, ',');
            er.eur = stod(eur_string);
            getline(ss, er.table_id, ',');
            rates.push_back(er);
        }
    }
    else {
        cerr << "Nie udalo sie otworzyc pliku kursy_usd_eur.csv" << endl;
    }
    return 0;
}
