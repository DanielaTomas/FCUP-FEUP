#include <iostream>
#include <vector>
#include <algorithm>

struct Game {
    std::string equipa1;
    std::string equipa2;
    int golos1;
    int golos2;
};
void print_game(const Game& g) {
    std::cout << g.equipa1 << ' ' << g.equipa2 << ' ' << g.golos1 << ' ' << g.golos2 << std::endl;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<Game> v;
    for(int i = 0; i < n; i++) {
        std::string s1;
        std::string s2;
        int n1;
        int n2;
        std::cin >> s1 >> s2 >> n1 >> n2;
        v.push_back({s1,s2,n1,n2});
    }
    std::for_each(v.begin(), v.end(), print_game);
    return 0;
}
