#include <iostream>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    std::vector<std::string> lines = {"PO12345", "PO 12345", "PZ973ND", "WE20456"};
    std::regex re(R"(\d{5,8})");
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

    stringstream ss;
    ss << file.rdbuf();
    string string_file = ss.str();

    while(std::regex_search(string_file, match, re)){
        matches.push_back(match[0]);
        string_file = match.suffix();
        cout << match[0] << endl;
    }

    return 0;
}
