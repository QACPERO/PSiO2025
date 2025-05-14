#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<double> bubble_sort(vector<double> &to_sort){
    for(int i = 0; i < to_sort.size(); i++){
        for(int j = 0; j < to_sort.size()-i-1; j++){
            if(to_sort[j]>to_sort[j+1]){
                double third_var = to_sort[j];
                to_sort[j] = to_sort[j+1];
                to_sort[j+1] = third_var;
            }
        }
    }
    return to_sort;
}

int main()
{
    vector<double> numbers = {2,3,1,10,12,14,17,0,22,54};
    bubble_sort(numbers);
    for (auto n : numbers){
        cout << n << ",";
    }
    return 0;
}
