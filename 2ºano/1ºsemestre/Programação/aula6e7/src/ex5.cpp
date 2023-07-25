#include <cassert>
#include <iostream>

namespace leic {
  class dmatrix {
    private:
      double** values;
      int l; // campos para nº de linhas e colunas
      int c;

    public:
      dmatrix(int lines, int cols) {
        assert(lines > 0 && cols > 0);
        values = new double*[lines];
        double *data = new double[lines * cols];

        for (int i = 0; i < lines; i++) {
          values[i] = data + i * cols;
          for (int j = 0; j < cols; j++) {
            values[i][j] = 0.0;
          }
        }
          l = lines;
          c = cols;
      }

      dmatrix(const dmatrix& m) {
          l = m.lines();
          c = m.cols();
          values = new double*[l];
          double *data = new double[l * c];

          for (int i = 0; i < l; i++) {
              values[i] = data + i * c;
              for (int j = 0; j < c; j++) {
                  values[i][j] = m.at(i,j);
              }
          }
      }

      ~dmatrix() {
        // Liberta memória com delete!
          delete[] values[0];
          delete[] values;
      }

      int lines() const {
        return l;
      }

      int cols() const {
        return c;
      }

      double at(int l, int c) const {
          return values[l][c];
      }

      double& at(int l, int c) {
          return values[l][c];
      }

      void fill(double v) {
          for(int i = 0; i < l; i++) {
              for(int j = 0; j < c; j++) {
                  values[i][j] = v;
              }
          }
      }
      void fill_diagonal(double v) {
          for(int i = 0; i < l; i++) {
              for(int j = 0; j < c; j++) {
                  if(i == j) {
                      values[i][j] = v;
                      break;
                  }
              }
          }
      }
      void transpose() {
          dmatrix data = dmatrix(c,l);
          for(int i = 0; i < l; i++) {
              for(int j = 0; j < c; j++) {
                  data.values[i][j] = values[i][j];
              }
          }
          for(int i = 0; i < l; i++) {
              for(int j = 0; j < c; j++) {
                 values[i][j] = data.values[j][i];
              }
          }
      }

      dmatrix& operator=(const dmatrix& m) {
          assert(m.lines() > 0 && m.cols() > 0);
          this->~dmatrix();
          l = m.lines();
          c = m.cols();
          values = new double*[l];
          double *data = new double[l * c];

          for (int i = 0; i < l; i++) {
              values[i] = data + i * c;
              for (int j = 0; j < c; j++) {
                  values[i][j] = m.at(i,j);
              }
          }
          return *this;
      }
  };
  std::ostream& operator<<(std::ostream& out, const dmatrix& m) {
      for(int i = 0; i < m.lines(); i++) {
          for(int j = 0; j < m.cols(); j++) {
              out << m.at(i,j) << " ";
          }
          out << std::endl;
      }
      return out;
  }
}
int main() {
  /*
  leic::dmatrix d(3,3);
  int n;
  std::cout << "Enter n? ";
  std::cin >> n;
  d.fill_diagonal(1);
  std::cout << d;
  */

    leic::dmatrix a(3, 3);
    a.fill_diagonal(1.0);
    leic::dmatrix b = a; // uso de construtor de cópia
    leic::dmatrix c(4,4);
    c = a; // uso de operador de atribuição
    std::cout << a << b << c;
    return 0;
}
