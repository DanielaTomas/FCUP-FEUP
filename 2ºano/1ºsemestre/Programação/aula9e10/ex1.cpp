#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char**argv) {
    std::ifstream in(argv[1]);
    std::vector<std::string> c;
    while (true) {
        std::string word;
        in >> word;
        if (word.empty()) break;
        c.push_back(word);
    }

  /*
    std::cout << "--- ex1 ---" << std::endl;
    for(auto itr = c.begin(); itr != c.end(); itr++)
        std::cout << *itr << std::endl;

    std::cout << "--- ex2 ---" << std::endl;
    for(auto itr = c.rbegin(); itr != c.rend(); itr++)
        std::cout << *itr << std::endl;

    std::sort(c.begin(), c.end());

    std::cout << "--- ex2 ---" << std::endl;
    for(auto& itr : c)
        std::cout << itr << std::endl;
  */

  /*
    std::cout << "--- ex3 ---" << std::endl;

    std::sort(c.begin(), c.end());
    auto u_end = std::unique(c.begin(),c.end());

    for(auto itr1 = c.begin(); itr1 != u_end; itr1++)
        std::cout << *itr1 << std::endl;
  */
    return 0;
}