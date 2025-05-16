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

bool czy_same_owoce(const Koszyk & koszyk){
    if(std::all_of(koszyk.begin(), koszyk.end(), [](Roslina a){return a.typ ==TypRosliny::Owoc;})){
        return true;
    }
    else return false;
}

bool czy_same_warzywa(const Koszyk &koszyk){
    if(std::all_of(koszyk.begin(), koszyk.end(), [](Roslina a){return a.typ ==TypRosliny::Warzywo;})){
        return true;
    }
    else return false;

}

bool czy_jakis_owoc(const Koszyk &koszyk){
    if(std::any_of(koszyk.begin(), koszyk.end(), [](Roslina a){return a.typ ==TypRosliny::Owoc;})){
        return true;
    }
    else return false;

}

bool czy_jakies_warzywo(const Koszyk &koszyk){
    if(std::any_of(koszyk.begin(), koszyk.end(), [](Roslina a){return a.typ ==TypRosliny::Warzywo;})){
        return true;
    }
    else return false;

}

int main()
{
    Koszyk koszyk;
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Jablko"));
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Gruszka"));

    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Cebula"));
    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Ziemniak"));


    if(czy_jakies_warzywo(koszyk)) cout << "jakies warzywo " << endl;
    if(czy_jakis_owoc(koszyk)) cout << "jakis owoc" << endl;
    if(czy_same_owoce(koszyk)) cout << "same owoce" << endl;
    if(czy_same_warzywa(koszyk)) cout << "same warzywa" <<endl;

    return 0;
}
