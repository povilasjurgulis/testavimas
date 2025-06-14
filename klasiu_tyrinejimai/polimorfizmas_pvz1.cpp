#include "main.h"
// Polimorfizmas leidžia to paties pavadinimo funkcijoms elgtis skirtingai (priklausomai nuo konteksto).
// Dinaminis polimorfizmas (su virtual) - funkcijos elgesys priklauso nuo to, kokio tipo objektas iš tikrųjų yra, 
// nors jis naudojamas per bazinės klasės rodyklę ar nuorodą.

class Zmogus{
    protected:
    string vardas;
    public:
    Zmogus(string v) : vardas{v}{}
    virtual void koks_vardas() { cout << vardas << " yra Zmogus\n";}
};

class Studentas : public Zmogus{
    public:
    Studentas(string var) : Zmogus{var}{} 
    void koks_vardas() { cout << vardas << " yra Studentas\n";}
};

int main() {
    Zmogus zm{"Povilas"};
    Studentas st{"Arnas"};

    zm.koks_vardas(); // Povilas yra Zmogus
    st.koks_vardas(); // Arnas yra Studentas

    Zmogus& zm1 = st; // Sukuriame nuorodą į Zmogus klasės objektą, bet susiejame su Studentas klasės objektu
    zm1.koks_vardas(); // Jei nebūtų virtual, tai čia būtų "Arnas yra Zmogus"

    Zmogus* zm2 = &st;
    zm2->koks_vardas(); // Jei nebūtų virtual, tai čia būtų "Arnas yra Zmogus"

    // Studentas& st1 = zm; Šitaip NEGALIMA, nes Studentas yra išvestinė iš Zmogus
    return 0;
}