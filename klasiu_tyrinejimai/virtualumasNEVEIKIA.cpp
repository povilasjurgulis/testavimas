#include "main.h"
// Virtualumas neveikia paskutinėje eilutėje b.whoAmI(), kadangi b objektui priskyrėme d ne per nuorodą ar rodyklę.
// Taigi įvyksta "apipjaustymas", nes perkopijuojama tik Base dalis iš Derived.
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
  Base b = d; // Base objektui priskiriame Derived objektą (ne per nuorodą ar rodyklę)
  b.whoAmI(); // ką gausime čia? Ats.: Vardenis iš Base klasės, 
  // KADANGI mes b objektui priskyrėmę d objektą ne per nuorodą (ar pointerį), o tada neveikia virtualumas! 
  // b.whoAmI() vyksta 'apipjaustymas'.
  return 0;
}