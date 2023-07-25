#include <iostream>
#include "graph.h"
#include "graph.cpp"
int main() {

    int cenarios,alunos;
    std::cin >> cenarios;

    for(int i = 1; i <= cenarios; i++) {
        std::cout << "Caso #" << i << " " << std::endl;
        std::cin >> alunos;
        Graph graph(alunos,true);
        
        for(int j = 1; j <= alunos; j++) {
            int num,relacoes;
            std::cin >> num >> relacoes;

            for(int l = 1; l <= relacoes; l++) {
              int relacao;
              std::cin >> relacao;
            }
        }
    }

    return 0;
}