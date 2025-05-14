//zadanie czesc 2 z przkatnymi 
#include <iostream>

using namespace std;

void draw_square(const int &count, const bool &left_diagonal, const bool &right_diagonal){
    for (int i = 0; i < count; i++){
        for (int j = 0; j <count; j++){
            if(j==0 || i == 0 || i == count -1 || j == count -1) cout << "#";
            else if(left_diagonal == true && i == j) cout << "#";
            else if(right_diagonal == true && i + j == count-1) cout << "#";
            else cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    draw_square(7, true, true);
    return 0;
}


//================================================================================================
//zadanie czesc 1
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
