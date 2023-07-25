#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

struct Game {
    std::string equipa1;
    std::string equipa2;
    int golos1;
    int golos2;
};
void print_game(const Game& g) {
    std::cout << g.equipa1 << ' ' << g.equipa2 << ' ' << g.golos1 << ' ' << g.golos2 << std::endl;
}
bool compareGames1(const Game& a, const Game& b) {
    return a.equipa1 < b.equipa1;
}
bool compareGames2(const Game& a, const Game& b) {
    return (a.golos1 + a.golos2) < (b.golos1  + b.golos2);
}
bool compareGames3(const Game& a, const Game& b) {
    return (a.golos1 + a.golos2) > (b.golos1  + b.golos2);
}
int main() {
    std::vector<Game> v = { {"Arsenal","Liverpool",4,5},
                            {"Chelsea","Arsenal",3,1},
                            {"Chelsea","Leeds",0,1},
                            {"Leeds","Arsenal",2,1},
                            {"Liverpool","Chelsea",4,2},
                            {"Liverpool","Leeds",0,0}
                          };
    //std::sort(v.begin(), v.end(), compareGames1);
    //std::for_each(v.begin(), v.end(), print_game);
    //std::sort(v.begin(), v.end(), compareGames2);
    //std::for_each(v.begin(), v.end(), print_game);
    std::sort(v.begin(), v.end(), compareGames3);
    std::for_each(v.begin(), v.end(), print_game);
    return 0;
}