#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <list>

using namespace std;

int randomInt(int min, int max) {
    static std::default_random_engine e{static_cast<long unsigned int>(time(0))};
    std::uniform_int_distribution<int> d{min, max};
    return d(e);
}

int main()
{
    std::vector<int> numbers;

    for (int i = 0; i < 25; i++){
        numbers.push_back(randomInt(-20,20));
    }

    auto max_it = std::max_element(numbers.begin(), numbers.end());
    cout << "Max value: " << *max_it << endl;

    auto min_it = std::min_element(numbers.begin(), numbers.end());
    cout << "Min value: " << *min_it << endl;

    for(auto n : numbers){
        cout << n << ", ";
    }

    auto [min,max] = std::minmax_element(numbers.begin(), numbers.end());
    cout << endl << *min << " -----  " << *max;
    return 0;
}
