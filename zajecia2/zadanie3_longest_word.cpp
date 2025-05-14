#include <iostream>
#include <vector>

using namespace std;

string find_longest_word(string input){
    size_t space_pos = input.find(' ');
    size_t prev_pos = 0;
    int max_length = 0;
    string max_word;
    string current_word;
    while(space_pos != std::string::npos){
        current_word = input.substr(prev_pos, space_pos - prev_pos);
        if(current_word.size() > max_length){
            max_length = current_word.size();
            max_word = current_word;
        }
        prev_pos = space_pos+1;
        space_pos = input.find(' ', prev_pos + 1);
    }
    current_word = input.substr(prev_pos);
    if(current_word.size() > max_length){
        max_length = current_word.size();
        max_word = current_word;
    }
    return max_word;
}

int main()
{
    std::string input = "Ala ma kota kot jezdzi na Roombie";

    std::string longest = find_longest_word(input); // "Roombie"
    cout << longest << endl;
    return 0;
}
