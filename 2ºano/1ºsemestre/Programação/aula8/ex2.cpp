/*
// 2.
// 2.1. A é final, logo não pode ter uma subclasse

class A final {
public:
    A() { }
};
class B : public A {
public:
    B() { }
};
 */

/*
//2.2 x é privado na classe A, logo não pode ser acessado fora da classe

class A {
private:
    int x;
public:
    A() { x = 0; }
};
class B : public A {
public:
    B() {  }
    int f() { return x; }
};
*/

/*
//2.3. O construtor da classe A não recebe argumentos

class A {
private:
    int x;
public:
    A() {  x = 0; }
};
class B : public A {
public:
    B(int x) : A(x) { }
};
 */

/*
// 2.4. B não tem um construtor

class A {
protected:
    int x;
public:
    A(int v) {  x = v; }
};
class B : public A {
public:
    B(int x)  { x = 1; }
};
 */

/*
// 2.5. função f marcada como 'override', mas f de B não é igual ao de A logo não pode ser reescrito

class A {
protected:
    int x;
public:
    A(int v) {  x = v; }
    virtual int f() { return x; }
};
class B : public A {
public:
    B(int v) : A(v) { }
    int f(int v) override { return x + v; }
};
*/

/*
// 2.6.  f de A não pode ser reescrito porque é final

class A {
protected:
    int x;
public:
    A() {  x = 0; }
    virtual int f() final { return x; }
};
class B : public A {
public:
    B() { x = 1; }
    int f() override { return x + 1; }
};
*/

/*
//2.7. f não tem implementação, funciona como interface genérico, ou seja, a classe A é abstrata e não pode ser instanciada diretamente só por B

class A {
protected:
    int x;
public:
    A(int v) {  x = v; }
    virtual int f() = 0;
};
class B : public A {
public:
    B(int v) : A(v) { }
    int f() override { return x + v; }
    int g(int v) {
        A a(v + x);
        B b(v + x);
        return a.f() + b.f();
    }
};
 */