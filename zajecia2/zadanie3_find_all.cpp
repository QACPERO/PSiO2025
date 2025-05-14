#include <iostream>
#include <vector>

using namespace std;


vector<size_t> find_all(const string &input, const char &ch){
    vector<size_t> result;
    size_t prev;
    size_t next = input.find(ch);
    while(next != std::string::npos){
        result.push_back(next);
        prev = next;
        next = input.find(ch, prev+1);
    }
    return result;
}

int main()
{
    std::string input = "Ala ma kota";

    std::vector<size_t> pos = find_all(input, 'a'); // wynik: {2, 5, 10}
    for(auto n : pos){
        cout << n << endl;
    }
    return 0;
}
