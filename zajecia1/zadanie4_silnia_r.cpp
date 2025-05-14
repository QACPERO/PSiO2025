#include <iostream>
#include <stdint.h>

using namespace std;

uint64_t factorial_r(uint64_t &number){
    uint64_t result = 1;
    if(number <=1) return 1;
    else{
        uint64_t temp_int = number -1; //trzeba zrobic dodatkowa zmienne zeby przekazac do funkcji bo jest referencja ktora nie zadziala z wartoscia tymczasowa number-1
        return (number * factorial_r(temp_int) );
    }
    return result;
}

int main()
{
    uint64_t number;
    cout << "Podaj liczhbe: ";
    cin >> number;
    uint64_t result = factorial_r(number);
    cout << endl << "Silnia wynosi: " << result;
    return 0;
}
