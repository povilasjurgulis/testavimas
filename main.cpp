#include "main.h"
// Klausimas: Jei kelios bazinės klasės turi funkciją tuo pačiu pavadinimu, 
// tai kuri iškviečiama išvestinėje klasėje?
// Ats.: Nei viena! Nebent iš išvestinės klasės specifiškai kvieti bazinių klasių metodus,
// pvz: Bazinės klasės A ir B (ir jos abi turi Hello() metodą), o C yra jų abiejų išvestinė,
// tai C.Hello() neveiks, bet C.A::Hello() ir C.B::Hello() veiks. 
class A{
    public:
    void Hello(){ cout << "Hello is klases A!\n";}
};

class B{
    public:
    void Hello(){ cout << "Hello is klases B!\n";}
};

class C : public A, public B{
    public:
    C() = default;
    // Kadangi klasė C neturi savo Hello() ir klasių A ir B metodas Hello taip pat aprašyti
    // , tai C.Hello() NEVEIKS!
};

class D : public C{
    public:
    void Hello(){ cout << "Hello is klases D!\n";}
    D() = default;
};
int main() {
    
    C objektas;
    // C.Hello(); NEVEIKIA! Kadangi tokį patį vardą turi ir bazinė klasė A ir B
    objektas.A::Hello(); // Veikia
    objektas.B::Hello(); // Irgi veikia

    D dObj;
    dObj.Hello(); // Veikia
    // dObj.C::Hello(); Neveikia!
    dObj.A::Hello(); // Veikia
    dObj.B::Hello(); // Veikia
    return 0;
}