#include <iostream>
#include <regex>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    std::vector<std::string> lines = {"PO12345", "PO 12345", "PZ973ND", "WE20456"};
    std::regex re(R"(\d{5,})");
    std::smatch match;
    std::vector<string> matches;

    std::fstream file("C:\\Users\\User\\Documents\\regex\\build\\Desktop_Qt_6_8_2_MinGW_64_bit-Debug\\debug\\plik.txt" , ios::in);
    string word;
    vector<string> words;

    cout << "test" << endl;

    if(!file.is_open()){
        cerr << "Nie mozna otworzyc pliku" << endl;
        return 1;
    }

    while(file>>word){
        words.push_back(word);
    }

    for(const auto &n : words){
        if(std::regex_match(n, match, re)){
            matches.push_back(n);
            cout << n << endl;
        }
    }
    return 0;
}
