#include <iostream>
#include <stdint.h>

using namespace std;

uint64_t factorial(uint64_t &number){
    uint64_t result = 1;
    for (int i = 1; i <= number; i++){
        result = result * i;
    }
    return result;
}

int main()
{
    uint64_t number;
    cout << "Podaj liczhbe: ";
    cin >> number;
    uint64_t result = factorial(number);
    cout << endl << "Silnia wynosi: " << result;
    return 0;
}
