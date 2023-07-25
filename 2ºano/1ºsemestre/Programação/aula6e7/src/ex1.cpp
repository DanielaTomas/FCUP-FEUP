#include <iostream>
#include <string>

//1.2
bool is_palindrome(const std::string& s) {
  int n = s.length()-1;
  for(int i = 0; i < n; i++) {
    if(s.at(i) != s.at(n)) return false;
    n--;
  }
  return true;
}

//1.3
int replace(std::string& s, char a, char b) {
  int cont = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s.at(i) == a) {
      s.at(i) = b;
      cont++;
    }
  }
  return cont;
}

int main(void) {
  std::cout << "Enter string: ";
  std::string str;
  std::cin >> str;

  //1.1
  for(int i = 0; i < str.length(); i++) {
    std::cout << i << ": " << str.at(i) << std::endl;
  }
  //std::cout << is_palindrome(str) << std::endl;
  //std::cout << replace(str,'a','x') << " " << str << std::endl;
  return 0;
}
