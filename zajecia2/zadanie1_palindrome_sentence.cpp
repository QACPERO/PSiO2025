#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(const string &word){
    string clear_string;
    for (char ch : word){
        if(isalpha(ch)){
            clear_string += tolower(ch);
        }
    }

    for (int i = 0; i < clear_string.size() ; i++){
        if (clear_string[i]!=clear_string[clear_string.size()-i-1]) return false;
    }
    return true;
}

int main()
{
    std::string word = "Never odd or even";
    if (is_palindrome(word)) {
        std::cout << "To palindrom!" << std::endl;
    } else {
        std::cout << "Nope" << std::endl;
    }
    return 0;
}
