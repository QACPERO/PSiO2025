#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main()
{
    std::vector<std::string> lines = {"PO12345", "PO 12345", "PZ973ND", "WE20456"};
    std::regex re(R"(((PZ)|(PO))[A-Z0-9]{5})");
    std::smatch match;
    std::vector<string> matches;
    for(const auto &n : lines){
        if(std::regex_match(n,match,re)){
            matches.push_back(match[0]);
        }
    }

    for (const auto &n : matches){
        cout << n << endl;
    }

    return 0;
}
