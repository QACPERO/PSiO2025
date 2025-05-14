#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void min_max(const std::vector<double> &vec, double &min, double &max){
    auto it = std::max_element(vec.begin(), vec.end()); //przypisanie przez iterator a nastepnie * do max
    max = *it;

    min = *std::min_element(vec.begin(), vec.end()); // przypisanie bezposrednio do min
}

int main()
{
    double min;
    double max;
    std::vector<double> values = {-1.0, 100, 3.14, -999.9, 21.37};

    min_max(values, min, max);
    cout << "Max: " << max << endl << "Min: " << min << endl;
    return 0;
}
