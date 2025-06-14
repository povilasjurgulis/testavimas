#include "main.h"
// std::vector polimorfizmas. Jis veikia TIK su rodyklėmis (neveikia su &).
// Jeigu nori, kad veiktų su nuorodomis &, tai reikia naudoti std::reference_wrapper.
class Base {
  protected:
      std::string vardas;
  public:
      Base(std::string v = "") : vardas{v} { }
      virtual void whoAmI() { std::cout << "As esu " << vardas << " is Base klases\n"; }
      virtual void whoAmI() const { std::cout << "As esu " << vardas << " is Base klases\n"; }
};

class Derived : public Base {
  protected:
      int amzius;
  public:
      Derived(std::string v = "", int a = 0) : Base{v}, amzius{a} { }
      void whoAmI() { std::cout << "As esu " << vardas << " is Derived klases\n"; }
      void whoAmI() const { std::cout << "As esu " << vardas << " is Derived klases\n"; }
};

int main() {
  std::vector<Base*> v; // Tik šitokiu atveju veiks polimorfizmas! Netgi su <Base&> neveiktų polimorfizmas
  v.push_back(new Base("Vardenis")); // Įdedame Base objektą į vektorių
  v.push_back(new Base("Vardenuks")); // Įdedame kitą Base objektą į vektorių
  v.push_back(new Derived("Super-puper Vardenux")); // Įdedame Derived objektą į vektorių
  for (const auto& el : v) // Atspausdiname vektoriaus elementus
    el->whoAmI(); // Ką gausime?
  for(const auto& el : v) delete el;
  return 0;
}