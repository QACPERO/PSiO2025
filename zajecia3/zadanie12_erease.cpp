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


int main()
{
    Koszyk koszyk;
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Jablko"));
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Gruszka"));

    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Cebula"));
    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Ziemniak"));

    koszyk.erase(std::remove_if(koszyk.begin(), koszyk.end(), [](Roslina a){return a.nazwa[0]=='J';}));
    for(auto n : koszyk){
        cout << n.nazwa << endl;
    }
    return 0;
}
