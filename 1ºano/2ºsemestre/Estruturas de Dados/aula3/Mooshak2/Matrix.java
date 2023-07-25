import java.util.Scanner;
class Matrix {
  int data[][]; // os elementos da matriz em si
  int rows; // numero de linhas
  int cols; // numero de colunas

  Matrix(int r, int c) {
    data = new int[r][c];
    rows = r;
    cols = c;
  }
  public void read(Scanner in ) {
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < cols; j++)
        data[i][j] = in.nextInt();
  }
  public String toString() {
    String ans = "";
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++)
        ans += data[i][j] + " ";
      ans += "\n";
    }
    return ans;
  }
  public static Matrix identity(int n) {
    Matrix id = new Matrix(n, n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          id.data[i][j] = 1;
        else
          id.data[i][j] = 0;
      }
    }
    return id;
  }
  public Matrix transpose() {
    Matrix tr = new Matrix(cols, rows);
    for (int i = 0; i < cols; i++) {
      for (int j = 0; j < rows; j++) {
        tr.data[i][j] = data[j][i];
      }
    }
    return tr;
  }
  public Matrix sum(Matrix m) {
    Matrix soma = new Matrix(rows, cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        soma.data[i][j] = m.data[i][j] + data[i][j];
      }
    }
    return soma;
  }
  public Matrix multiply(Matrix m) {
    Matrix mult = new Matrix(rows, m.cols);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < m.cols; j++) {
        for (int l = 0; l < cols; l++)
          mult.data[i][j] += data[i][l] * m.data[l][j];
      }
    }
    return mult;
  }
}
