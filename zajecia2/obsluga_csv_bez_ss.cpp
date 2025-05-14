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
            //sposob pierwszy bez string stream
            size_t position1 =line.find(",");
            string data = line.substr(0,position1);
            size_t position2 = line.find(",", position1+1);
            string usd = line.substr(position1+1, position2-position1-1);
            size_t position3 = line.find(",", position2+1);
            string eur = line.substr(position2+1, position3-position2-1);
            //size_t position4 = line.find(",", position3);
            string id = line.substr(position3+1);
            cout << data << " " << usd << " " << eur << " " << id << endl;
        }
    }
    else {
        cerr << "Nie udalo sie otworzyc pliku kursy_usd_eur.csv" << endl;
    }
    return 0;
}
