#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string find_and_replace(string input, const string &old_word, const string &new_word){

    size_t pos = input.find(old_word);
    while(pos != std::string::npos){
        input.replace(pos,old_word.size(),new_word);
        pos = input.find(old_word);
    }
    return input;
}

int main()
{
    std::string input = "Ala ma kota, kot zjadl Ale!";
    std::string output = find_and_replace(input, "kot", "hefalump");
    // wynik: "Ala ma hefalumpa, hefalump zjadl Ale!"
    cout << output << endl;
    return 0;
}
