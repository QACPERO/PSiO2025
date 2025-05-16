#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;

    Roslina(TypRosliny t, std::string n) : typ(t), nazwa(n) {}
};

using Koszyk = std::vector<Roslina>;

bool czy_jest_gruszka(const Koszyk &koszyk){
    if((std::find_if(koszyk.begin(), koszyk.end(), [](Roslina a){return a.nazwa == "Gruszka";}))!=koszyk.end()){
        return true;
    }
}


int main()
{
    Koszyk koszyk;
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Jablko"));
    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Ziemniak"));
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Gruszka"));

    if(czy_jest_gruszka(koszyk)){
        cout << "jest";
    }
    else{
        cout << "Nie ma";
    }

    return 0;
}
