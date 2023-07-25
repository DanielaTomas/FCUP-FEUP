#include <stdio.h>
int filtrar_positivos(int vec[], int size) {
    int npositivos = 0, aux=0;
    for (int i = 0;i < size; i++){
        if (vec[i] > 0) {
            vec[aux] = vec[i];
            npositivos++;
            aux++;
        }
    }
    return npositivos;
}
int main() {
    int n;
    scanf("%d", &n);
    int vec[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }
    printf("%d\n", filtrar_positivos(vec, n));
    return 0;
}
