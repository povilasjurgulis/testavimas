#include "main.h"
// Abstrakčios klasės. Visiškai virtualios funkcijos.


class Gyvunas{ // Abstrakti base klasė
    protected:
    string vardas;
    Gyvunas(string v) : vardas{v} {}
    public:
    virtual string sako() = 0; // Padarome klasę abstrakčia
    string get_vardas() { return vardas;}
};

class Kate : public Gyvunas{ // Išvestinė klasė
    public:
    Kate(string var) : Gyvunas{var}{}
    string sako() { return "Miau miau";} // privaloma realizuoti, nes Gyvunas::sako yra visiškai virtuali funkcija
};

class Suo : public Gyvunas{ // Išvestinės klasė
    public:
    Suo(string va) : Gyvunas{va}{}
    string sako() { return "Au au";} // privaloma realizuoti, nes Gyvunas::sako yra visiškai virtuali funkcija
};

void KaSako(Gyvunas &gyv)
{
    cout << gyv.get_vardas() << " sako " << gyv.sako() << "\n";
}

int main() {
  Kate katinas{"Murkis"};
  Suo suniukas{"Jupis"};

  KaSako(katinas);
  KaSako(suniukas);

  return 0;
}