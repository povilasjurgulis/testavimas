#include "main.h"
// Virtualus destruktorius (šiuo atveju labai reikalingas, nes būtų memory leak!)

class Base {
  protected:
    std::string vardas;
  public:
    Base(std::string v = "") : vardas{v} { }
  // virtual'i funkcija
    virtual void whoAmI() { std::cout << "Aš esu " << vardas << " iš Base klasės\n"; }
};
class Derived : public Base {
  protected:
    int amzius;
  public:
    Derived(std::string v = "", int a = 0) : Base{v}, amzius{a} { }
  void whoAmI() { std::cout << "Aš esu " << vardas << " iš Derived klasės\n"; }
};

int main() {
  Derived d{"Vardenis", 36};
  d.whoAmI(); // ką gavome čia?
  Base &refB = d; // Base tipo nuoroda į Derived objektą d
  Base *ptrB = &d; // Base tipo rodyklė į Derived objektą d
  refB.whoAmI(); // ką gavome čia?
  ptrB->whoAmI(); // ką gavome čia?
  Base b = d; // Base objektui priskiriame Derived objektą
  b.whoAmI(); // ką gausime čia? Ats.: Vardenis iš Base klasės, KADANGI mes ne b adresui priskyrėmę d, o tada neveikia virtualumas! 
  
  return 0;
}