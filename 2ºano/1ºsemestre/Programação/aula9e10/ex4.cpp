#include <map>
#include <fstream>
#include <iostream>

int main(int argc, char**argv) {
    std::ifstream in(argv[1]);
    std::map<std::string,int> word_count;

    while (true) {
        std::string word;
        in >> word;
        if (word.empty()) break;
        //word_count[word]++;  //4.2.
        auto itr = word_count.find(word);
        if (itr == word_count.end()) {
            // Não existe, insere nova entrada no mapa
            word_count.insert({word,1});
        } else {
            // Actualiza (*itr).second
            (*itr).second++;
        }
    }

    for (auto n : word_count) {
        std::cout << n.first << " " << n.second << std::endl;
    }

    return 0;
}