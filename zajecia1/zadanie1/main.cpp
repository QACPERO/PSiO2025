#include <iostream>
#include <vector>

using namespace std;

void fill_progresive(vector<int> &vec, const int &counter){
    for(int i = 0; i<counter ; i++){
        vec.push_back(i);
    }
}

void print_vector(const vector<int> &vec){
    for (auto &n : vec){
        cout << n << " ";
    }
}

int main()
{
    int liczba;
    cout << "Podaj liczbe: " << endl;
    cin >> liczba;
    vector<int> vec;
    fill_progresive(vec, liczba);
    print_vector(vec);
    return 0;
}
