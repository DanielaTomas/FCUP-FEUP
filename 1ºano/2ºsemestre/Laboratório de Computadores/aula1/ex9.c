#include <stdio.h>
int magico(int a[20][20], int n) {
    int somal = 0, somac = 0, somad = 0;
    for (int i = 0, j = 0; i < n; i++, j++) {
        somad += a[i][j];
    }
    for (int i = 0; i < n; i++) {
        somal = 0;
        for (int j = 0; j < n; j++) {
            somal += a[i][j];
        }
        if (somal != somad) {
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
      somac = 0;
        for (int j = 0; j < n; j++) {
            somac += a[j][i];
        }
        if (somac != somad) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    int a[20][20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d\n", magico(a, n));
    return 0;
}
