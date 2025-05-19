#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

using StrSeq = vector<string>;
using StrFreq = map<string, int>;

std::vector<std::string> split(const std::string& word, string seps = ".,;:'\"!?()*-/<>@") {
    std::vector<std::string> words;
    std::string s;

    for (auto c : word) {
        if (seps.find(c) == string::npos)
            s += c;
        else if (!s.empty()) {
            words.push_back(s);
            s.clear();
        }
    }
    if (!s.empty())
        words.push_back(s);

    return words;
}

bool is_digit(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main() {
    // PUNKTY DODATKOWE
    // 2: definicje typow z wykorzystaniem using albo typedef
    // 2: poprawne przekazywanie przez referencje/wskaznik lub przez wartosc
    // 2: poprawne uzycie modyfikatora const

    // Otworz plik license.txt (https://put-jug.github.io/lab-psio/_resources/04/license.txt) jako std::fstream o nazwie file
    // PUNKTY: 1

    fstream file("C:\\Users\\User\\Downloads\\license.txt", ios::in);

    // Wczytaj wszystkie slowa jako wektor lancuchow o nazwie words
    // PUNKTY: 2
    StrSeq words;
    string word;
    while(file>>word){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        words.push_back(word);
    }

    // Przetransformuj kazda litere w kazdym slowie do "malych" znakow uzywajac std::tolower()
    // Mozesz uzyc std::transform()
    // PUNKTY: 2



    // Oblicz czestotliwosc slow w wektorze lancuchow words uzywajac kontenera typu std::map
    // PUNKTY: 2
    StrFreq freq;
    for(const auto &n : words){
        freq[n] += 1;
    }

    // Dodatkowo podziel slowa z words przez usuniecie separatorow .,;:'\"!?()*-/<>@
    // Wszystkie slowa po podziale wstaw do nowego wektora lancuchow o nazwie words2
    // Mozesz uzyc funkcji split() z Lab02.1.cpp
    // PUNKTY: 3 (dla pojedynczego dowolnego znaku separatora)
    // PUNKTY: 4 (dla pojedynczego znaku separatora ")
    // PUNKTY: 8 (dla dwoch dowolnych znakow separatora)
    // PUNKTY: 14 (dla wszystkich znakow separatora z wykorzystaniem zmodyfikowanej funkcji split())

    StrSeq words2;
    for (const string& word : words) {
        StrSeq parts = split(word);
        words2.insert(words2.end(), parts.begin(), parts.end());
    }

    // Oblicz czestotliwosc slow w wektorze lancuchow words2 uzywajac kontenera typu std::map
    // PUNKTY: 1
    StrFreq freq2;
    for(const auto &n : words2){
        freq2[n] += 1;
    }

    // Rozdziel slowa z words albo words2 na liczby i nie-liczby korzystajac z std::isdigit()
    // Utworz funkcje isnumber()
    // Wszystkie liczby i nie-liczby wstaw do wektorow lancuchow o nazwach odpowiednio numbers i notnumbers
    // PUNKTY: 4 (slowa z words)
    // PUNKTY: 5 (slowa z words2)
    StrSeq numbers, notnumbers;
    for(const auto &n : words2){
        if(is_digit(n)) numbers.push_back(n);
        else notnumbers.push_back(n);
    }



    // Przesortuj liczby w numbers wg wartosci, traktujac je jako liczby a nie lancuch
    // PUNKTY: 6

    std::sort(numbers.begin(), numbers.end(), [](string a, string b){return stoi(a)>stoi(b);});
    for(auto n : numbers){
        cout << n << endl;
    }
    // Oblicz czestotliwosc liczb (jako lancuch) i nie-liczb uzywajac kontenerow typu std::map
    // PUNKTY: 1
    StrFreq freqN, freqNN;

    return 0;
}
