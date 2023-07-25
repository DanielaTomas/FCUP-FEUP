/*(1)

void f() {
  int x;
  g(&x);
}

(2)

int* f() {
  int x;
  return &x;
}

(3)

int* f() {
  int* x = (int*)malloc(sizeof(int));
  return x;
}

(4)
*/
int g(int (*h)(int), int y) {
  return h(y + 2);
}
int f(int x) {
  return x*x;
}
int main() {
  printf("value: %d\n", g(f,2));
  return 0;
}
