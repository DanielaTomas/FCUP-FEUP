class solid {
protected:
    int v;
    int a;
public:
    solid(int volume, int area) {  v = volume; a = area; }
    virtual double volume() const = 0;
    virtual double area() const = 0;
};

class sphere : public solid {
protected:
    int r;
public:
    sphere(int v, int a, int raio)
    : solid(v,a), r(raio) { }
};
