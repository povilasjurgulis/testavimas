#include "main.h"
// Virtualus destruktorius (šiuo atveju labai reikalingas, nes būtų memory leak!)

class Base {
  public:
  virtual ~Base() { std::cout << "D-tor ~Base()" << std::endl; } // Jei nebūtų virtual, tuomet iškvietus delete b;
  // iškviestų tik bazinės klasės destruktorių, o ne išvestinės klasės destruktorių.
};
class Derived : public Base {
  private:
    double* elem;
    int size;
    int iter = 0; // iteratoriaus reikšmė, kurią naudosime nustatydami elementus
  public:
    Derived (int sz = 0) : elem{new double[sz]}, size{sz} { }
    ~Derived() {
        std::cout << "D-tor ~Derived()" << std::endl;
        delete[] elem; // atlaisviname resursus
    }
    void set_elem(int el)
    {
        elem[iter] = el; // nustatome elementą pagal iteratoriaus reikšmę
        iter++; // padidiname iteratoriaus reikšmę
    }
    
    double get_elem(int id) 
    { 
        return elem[id]; 
    }

    int get_size() 
    { 
        return size; 
    }
};
int main() {
  Derived *d = new Derived(10);
  for(int i = 0; i < d->get_size(); i++)
  {
    d->set_elem(i);
  }
  cout << d->get_elem(5) << endl;
  Base *b = d;
  cout << d->get_elem(8) << endl;

  delete b; // kas nutiks čia? Kadangi b yra bazinės klasės rodyklė,
  // bus iškviestas bazinės klasės destruktorius, ir kadangi destruktorius yra virtualus,
  // bus iškviestas ir išvestinės klasės destruktorius, kuris atlaisvins resursus.

  cout << d->get_elem(9) << endl; // čia gausis nesąmonė, nes d buvo ištrintas, bet d vis dar egzistuoja
  delete d; // čia bus klaida, nes d jau buvo ištrintas per delete b;
  cout << "Hi\n"; // šis kodas niekada nebus pasiektas, nes programa baigs veikti anksčiau dėl klaidos
    return 0;
}