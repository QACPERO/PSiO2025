#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(const int &number){
    if(number<=1) return false;
    for (int i = 2; i < ceil(sqrt(number)); i++){
        if(number%i == 0) return false;
    }
    return true;
}

int main()
{
    int prime_or_not_prime = 23;
    if (is_prime(prime_or_not_prime)) {
        std::cout << prime_or_not_prime << " is prime!" << std::endl;
    } else {
        std::cout << prime_or_not_prime << " is not prime!" << std::endl;
    }
    return 0;
}
