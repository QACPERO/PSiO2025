#include <iostream>

using namespace std;

bool is_palindrome(const string &word){
    for (int i = 0; i < word.size() ; i++){
        if (word[i]!=word[word.size()-i-1]) return false;
    }
    return true;
}

int main()
{
    std::string word = "racecar";
    if (is_palindrome(word)) {
        std::cout << "To palindrom!" << std::endl;
    } else {
        std::cout << "Nope" << std::endl;
    }
    return 0;
}
