#include "main.h"
// Polimorfizmas leidžia to paties pavadinimo funkcijoms elgtis skirtingai (priklausomai nuo konteksto).
// Dinaminis polimorfizmas (su virtual) - funkcijos elgesys priklauso nuo to, kokio tipo objektas iš tikrųjų yra, 
// nors jis naudojamas per bazinės klasės rodyklę ar nuorodą.

// Bazinė klasė
class Gyvunas {
  protected:
    std::string vardas;
    // C-tor'ius yra protected, tam kad neleisti tiesiogiai kurti
    // Gyvunas tipo objektų, bet išvestinės klasės galės jį naudoti
    Gyvunas(std::string v) : vardas(v) {}
  public:
    std::string getVardas() { return vardas; }
    virtual std::string sako() { return "?"; }
};
// Pirma public tipo išvestinė klasė
class Katinas : public Gyvunas {
  public:
    Katinas(std::string v) : Gyvunas(v) {}
    std::string sako() { return "Miauuu"; }
};
// Antra public tipo išvestinė klasė
class Suo : public Gyvunas {
  public:
    Suo(std::string v) : Gyvunas(v) {}
    std::string sako() { return "Au au au"; }
};
// Per nuorodą (reference) perduodu Gyvunas objektą. Reikia nuorodos, nes tik su nuoroda veikia (virtual) dinaminis polimorfizmas
void gyvunasSako(Gyvunas &gyv) { // Jei nebus nuorodos, tai nerodys ką sako ir rodys tiesiog, tarkim 'Cipas sako: ?'
    std::cout << gyv.getVardas() << " sako: " << gyv.sako() << '\n';
}
int main() {
  Katinas kate("Cipsas");
  Suo suo("Kebabas");
  gyvunasSako(kate);
  gyvunasSako(suo);

    return 0;
}