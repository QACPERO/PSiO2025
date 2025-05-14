#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string &sentence){
    stringstream ss(sentence);
    vector<string> result;
    string curr_word;
    while(getline(ss, curr_word, ' ')){
        result.push_back(curr_word);
    }
    return result;
}

vector<string> split(const string &sentence, const char &separator){
    stringstream ss(sentence);
    vector<string> result;
    string curr_word;
    while(getline(ss, curr_word, separator)){
        result.push_back(curr_word);
    }
    return result;
}

int main()
{
    std::string sentence = "Ala ma kota";
    std::vector<std::string> words = split(sentence); // wynik: {"Ala", "ma", "kota"}
    for(const auto &word : words){
        cout << word << endl;
    }
    cout << endl;
    std::string csv = "Mount Everest,8848,1953";
    std::vector<std::string> data = split(csv, ',');
    for (const auto &word : data){
        cout << word << endl;
    }
    return 0;
}
