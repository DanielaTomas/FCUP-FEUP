#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char** argv) {
  std::ifstream in(argv[1]);  // Abre ficheiro de input
  std::vector<std::string> v;
  std::string s;

  while(getline(in, s)) {
    v.push_back(s);
  }

  std::sort(v.begin(), v.end());
  std::ofstream out(argv[2]); // Abre ficheiro de output

  for(std::string vector : v) {
    out << vector << std::endl;
  }
}
