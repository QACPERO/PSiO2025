#include <iostream>
#include <cmath>

using namespace std;

double liebniz_pi(const double &stop_at){
    double result = 0;
    double current_num =1;
    double sign = 1;

    while(4*(1/current_num)>=stop_at){
        result += sign*(1/current_num)*4;
        sign = sign*(-1);
        current_num +=2;
    }
    return result;
}


int main()
{
    double stop_at = 0.0000001;
    double pi_approx = liebniz_pi(stop_at);

    std::cout << pi_approx << std::endl;
    std::cout << "error: " << pi_approx - M_PI << std::endl;
    return 0;
}
