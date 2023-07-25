+
#include <vector>
#include <iostream>

template <typename T>
T max_value(const std::vector<T>& v) {
  T max = v.at(0);
  for(T vector : v) {
    if(vector > max) max = vector;
  }
  return max;
}

template <typename T>
void norm_values(std::vector<T>& v, T min, T max) {
  for(int i = 0; i < v.size(); i++) {
      if(v.at(i) < min) v.at(i) = min;
      if(v.at(i) > max) v.at(i) = max;
  }
}

int main() {
  std::vector<int> iv { 2, -1, 2, 5, 1, 4};
  int imax = max_value(iv);
  norm_values(iv, 0, 3);
  std::cout <<  "---- Teste Int ----" << std::endl;
  std::cout <<  "imax: " << imax << std::endl;
  for(int i = 0; i < 6; i++) {
      std::cout <<  "iv.at(" << i << ") = " << iv.at(i) << std::endl;
  }
  std::vector<double>dv { -1.2, 0.5, 1.3, 3.2, -0.7, 1.1 };
  double dmax = max_value(dv);
  norm_values(dv, -1.0, 1.0);
  std::cout <<  "---- Teste Double ----" << std::endl;
  std::cout <<  "dmax: " << dmax << std::endl;
  for(int i = 0; i < 6; i++) {
      std::cout <<  "dv.at(" << i << ") = " << dv.at(i) << std::endl;
  }
  return 0;
}
