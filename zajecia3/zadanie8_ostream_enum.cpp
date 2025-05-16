#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <list>
#include <map>


using namespace std;

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;

    Roslina(TypRosliny t, std::string n) : typ(t), nazwa(n) {}
};

using Koszyk = std::vector<Roslina>;

std::ostream &operator<<(std::ostream &out, const Roslina &roslina){
    string typ_s;
    switch(roslina.typ){
        case(TypRosliny::Owoc):
            typ_s = "owoc";
                break;
        case(TypRosliny::Warzywo):
            typ_s = "warzywo";
                break;
    }

    out << "Typ: " << typ_s << ", Nazwa: " << roslina.nazwa;
    return out;
}

std::ostream &operator<<(std::ostream &out, const Koszyk &koszyk){
    for(auto n : koszyk){
        out << n <<endl;
    }

    return out;
}


int main()
{
    Koszyk koszyk;
    koszyk.push_back(Roslina(TypRosliny::Owoc, "Jablko"));
    koszyk.push_back(Roslina(TypRosliny::Warzywo, "Ziemniak"));
    cout << koszyk;
    return 0;
}
