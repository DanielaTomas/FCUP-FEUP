#include <stdio.h>
#include <stdlib.h>

struct _coord2d {
  double x;
  double y;
};
typedef struct _coord2d coord2d;

void coord2d_print(const coord2d* c) {
  printf("(%f,%f)\n", c->x, c->y);
}

void coord2d_add(coord2d* r, const coord2d* c1, const coord2d* c2) {
  r->x = c1->x + c2->x;
  r->y = c1->y + c2->y;
}

void coord2d_sub(coord2d* r, const coord2d* c1, const coord2d* c2) {
  r->x = c1->x - c2->x;
  r->y = c1->y - c2->y;
}

void coord2d_mul(coord2d* r, double k, const coord2d* c) {
  r->x = k * c->x;
  r->y = k * c->y;
}

int main(int argc, char* argv[]) {
  // Initialization with default values
  coord2d a = { 3.5, 5 };
  coord2d b = { .x = -1.75, .y = -2.5 };

  if (argc == 5) {
    a.x = atof(argv[1]);
    a.y = atof(argv[2]);
    b.x = atof(argv[3]);
    b.y = atof(argv[4]);
  }
  coord2d r;
  if(argc <= 4) {
    r.x = -1;
    r.y = -2;
    coord2d_print(&r);
  }
  else {
    coord2d_mul(&r, 0.5, &a);
    coord2d_add(&r, &r, &b);

    coord2d c = { 1, 2 };
    coord2d_sub(&r, &r, &c);
    coord2d_print(&r);
  }
  return 0;
}
