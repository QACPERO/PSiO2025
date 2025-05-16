#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <list>
#include <map>


using namespace std;

int randomInt(int min, int max) {
    static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
    std::uniform_int_distribution<int> d{min, max};
    return d(e);
}

int main()
{
    std::vector<int> numbers;
    std::list<int> numbers_list;
    std::map<int , int> wystapienia;

    for (int i = 0; i < 10; i++){
        numbers.push_back(randomInt(-20,20));
        numbers_list.push_back(randomInt(-20,20));
    }

    for(auto n : numbers){
        if(std::all_of(wystapienia.begin(), wystapienia.end(), [n](std::pair<int, int> a){return a.first != n;})){
            int counter = 0;
            counter = std::count(numbers.begin(), numbers.end(), n);
            wystapienia[n] = counter;
        }
    }

    for(auto n : wystapienia){
        cout << n.first << " - " << n.second << endl;
    }

    return 0;
}
