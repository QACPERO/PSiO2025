#include <iostream>

using namespace std;

void draw_square(const int &count){
    for (int i = 0; i < count; i++){
        for (int j = 0; j <count; j++){
            if(j==0 || i == 0 || i == count -1 || j == count -1){
                cout << "#";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    draw_square(10);
    return 0;
}
