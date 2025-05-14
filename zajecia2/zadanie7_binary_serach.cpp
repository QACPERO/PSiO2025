#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int binary_s(const vector<double> &vec, const double &to_find){
    int start = 0;
    int end = vec.size();
    while(start <= end){
        int mid = (start+end)/2;
        if(vec[mid] == to_find) return mid;
        else if(to_find > vec[mid]) start = mid+1;
        else end = mid - 1;
    }
    return -1;
}

int main()
{
    vector<double> vec = {1, 2, 5, 8, 9 ,11, 15};
    cout << binary_s(vec, 11);
    return 0;
}
