#include <iostream>

using namespace std;

int NWD(int a, int b){
    int c;
    while(b > 0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;

}

int main()
{
    int result = NWD(24,52);
    cout << result << endl;
    return 0;
}
