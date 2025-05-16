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

int zlicz_owoce(Koszyk koszyk){
    return std::count_if(koszyk.begin(), koszyk.end(), [](Roslina a){return a.typ == TypRosliny::Owoc;});
}

int zlicz_warzywa(Koszyk koszyk){
    return std::count_if(koszyk.begin(), koszyk.end(), [](Roslina a){return a.typ == TypRosliny::Warzywo;});
}

int main()
{
    Koszyk koszyk;
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Jablko"));
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Gruszka"));

    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Cebula"));
    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Ziemniak"));

    cout << "Ilosc owocow: " << zlicz_owoce(koszyk) <<endl;
    cout << "Ilosc warzyw: " << zlicz_warzywa(koszyk) <<endl;


    return 0;
}
