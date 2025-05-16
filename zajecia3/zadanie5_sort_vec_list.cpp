#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <list>
#include <cmath>

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

    for (int i = 0; i < 10; i++){
        numbers.push_back(randomInt(-20,20));
        numbers_list.push_back(randomInt(-20,20));
    }

    std::sort(numbers.begin(), numbers.end()); //sortowanie rosnaco
    for(auto &n : numbers){
        cout << n << ", ";
    }
    cout << endl <<"============="<<endl;
    std::sort(numbers.begin(), numbers.end(), [](int a, int b){return a > b;}); //sortowanie malejaco
    for(auto &n : numbers){
        cout << n << ", ";
    }
    cout << endl <<"============="<<endl;
    std::sort(numbers.begin(), numbers.end(), [](int a, int b){return abs(a)>abs(b);}); //sortowanie rosnaco z abs
    for(auto &n : numbers){
        cout << n << ", ";
    }
    cout << endl <<"============="<<endl;

    numbers_list.sort(); //sortowanie rosnoca listy 
    for (auto &n : numbers_list){
        cout << n << ", ";
    }
    cout << endl <<"============="<<endl;
    numbers_list.sort([](int a, int b){return a > b;});
    for (auto &n : numbers_list){
        cout << n << ", ";
    }
    return 0;
}
