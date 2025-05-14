#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Exchange_rate{
    string date;
    double usd;
    double eur;
    string table_id;
};

void sort_usd(vector<Exchange_rate> &to_sort){
    for(int i = 0; i < to_sort.size(); i++){
        for(int j = 0; j < to_sort.size()-i-1; j++){
            if(to_sort[j].usd>to_sort[j+1].usd){
                Exchange_rate third_var = to_sort[j];
                to_sort[j] = to_sort[j+1];
                to_sort[j+1] = third_var;
            }
        }
    }
}

void sort_eur(vector<Exchange_rate> &to_sort){
    for(int i = 0; i < to_sort.size(); i++){
        for(int j = 0; j < to_sort.size()-i-1; j++){
            if(to_sort[j].eur>to_sort[j+1].eur){
                Exchange_rate third_var = to_sort[j];
                to_sort[j] = to_sort[j+1];
                to_sort[j+1] = third_var;
            }
        }
    }
}

int binary_s(const vector<Exchange_rate> &vec, const double &to_find){
    int start = 0;
    int end = vec.size();
    while(start <= end){
        int mid = (start+end)/2;
        if(vec[mid].usd == to_find) return mid;
        else if(to_find > vec[mid].usd) start = mid+1;
        else end = mid - 1;
    }
    return -1;
}

int main()
{
    fstream file("C:\\Users\\User\\Downloads\\kursy_usd_eur.csv", ios::in);
    std::vector<Exchange_rate> rates;

    if(file.is_open()){
        string line;
        getline(file, line);
        while(getline(file,line)){
            stringstream ss(line);

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
    sort_eur(rates);
    for (size_t i = 0; i < rates.size() && i < 10; ++i) {
        const auto& n = rates[i];
        cout << n.date << ", " << n.eur << ", " << n.usd << ", " << n.table_id << endl;
    }
    cout << "======================================================" << endl << endl << endl;
    sort_usd(rates);
    for(auto n : rates){
        cout<< n.date << ", " << n.eur << ", " << n.usd << ", " << n.table_id << endl;
    }
    cout << "======================================================" << endl << endl << endl;



    cout << "Indeks do znalezienia: ";
    cout << binary_s(rates, 3.9011) << endl;
    cout << "Data: " << rates[binary_s(rates, 3.9011)].date << endl;


    return 0;
}
