#include "main.h"
class Base {
  protected:
    std::string vardas;
    string get_vardas() { return vardas;}
  public:
    Base(std::string v = "") : vardas{v} { }
    std::string getVardas() const { return vardas; }
    void whoAmI() { std::cout << "As esu Base klase\n"; }
    void hello() { std::cout << "Hello is Base klases!\n"; }
};
class Derived : public Base {
  protected:
    int amzius;
  public:
    Derived(int a = 0, std::string v = "") : Base{v}, amzius{a} { }
    int getAmzius() const { return amzius; }
    void whoAmI() { std::cout << "As esu Derived klase\n";}
    void whoAmIForReal() 
    {
        Base::whoAmI();
        whoAmI();
    }
    using Base::get_vardas; // Dabar get_vardas taps public, jeigu kažkas naudos Derived klasę. Negalima šičia rašyti su skliausteliais!
    void hello() = delete; // Padarėme šią funkciją neprieinamą
};

int main() {
  Base b{"Vardenis"};
  std::cout << b.getVardas() << std::endl; // Ką čia gausime? Ats.: Vardenis
  Derived d{45, "Vardenuks"}; 
  std::cout << d.getVardas() << std::endl; // Ką čia gausime? Ats.: Vardenuks
  d.whoAmI(); // Ką čia gausime? Ats.: As esu Derived klase
  d.whoAmIForReal();
  cout << d.get_vardas() << "\n"; // Nors ir get_vardas Base klasėje yra protected, tačiau jį su using padarėme public su Derived klase
  // tačiau b.get_vardas() neveiktų!
  b.hello(); // Veikia
  // d.hello(); // Neveikia, nes yra = delete
    return 0;
}