#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

int randomInt(int min, int max) {
    static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
    std::uniform_int_distribution<int> d{min, max};
    return d(e);
}

int main()
{
    vector<int> numbers;

    for (int i = 0; i < 25; i++){
        numbers.push_back(randomInt(4,5));
    }

    for (auto it = numbers.begin(); it != numbers.end(); ++it){
        cout << *it << endl;
    }
    int to_remove = 5;
    

    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [to_remove](int a){
        return a == to_remove;
    }), numbers.end());



    cout << "======================================================" << endl;
    for(auto n : numbers){
        cout << n << endl;
    }
    return 0;
}
