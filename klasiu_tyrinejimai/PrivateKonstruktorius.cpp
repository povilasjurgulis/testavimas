#include "main.h"
// Private Konstruktorius. friend ir inheritance.
class Autorius{

    protected: 
    std::string vardas;
    int metai;
    int atlyginimas;


    private:
    friend class Knyga;
    Autorius(std::string v = " ", int m = 0, int atl = 0) : vardas{v}, metai{m}, atlyginimas{atl}{cout << "Autorius sukonstruotas\n";}


    public:
    static Autorius &sukonstruoti() // reikia &, kad nebūtų tik kopija
    {
        static Autorius objektas;
        return objektas;
    };
    static Autorius &sukonstruoti(std::string va, int met, int atly)
    {
        static Autorius objektas{va, met, atly};
        return objektas;
    };
    int get_metai() const { return metai; }
    int get_atlyginimas() const { return atlyginimas; }
    std::string get_vardas() const { return vardas; }
};

class Knyga : public Autorius { // Mum reikia kad Knyga būtų ir išvestinė Autoriaus klasė IR Autoriaus friend klasė, kad veiktų 'Autorius' c-tor

    private:
    std::string pavadinimas;
    int isleidimo_data;


    public:
    Knyga(std::string pav = "", int data = 0, std::string vard = "", int met = 0, int atly = 0) : 
    pavadinimas{pav}, isleidimo_data{data}, Autorius{vard, met, atly}{ cout << "Knyga sukonstruota\n";} // kadangi friend, galime naudoti Autorius private c-tor

    std::string get_pavadinimas() const { return pavadinimas; }
    int get_isleidimo_data() const { return isleidimo_data; }
    ~Knyga() { cout << "Knyga destruktorius\n"; }
};
int main() {
    Autorius aut = Autorius::sukonstruoti("Povilas", 19, 3500);
    Autorius aut2 = Autorius::sukonstruoti();

    cout << aut.get_metai() << " " << aut.get_vardas() << " " << aut.get_atlyginimas() << "\n";

    Knyga knyga1{"Knyga1", 2023, "Povilas", 19, 3500};
    cout << knyga1.get_pavadinimas() << " " << knyga1.get_isleidimo_data() << " " << knyga1.get_metai() << " " << knyga1.get_vardas() << " " << knyga1.get_atlyginimas() << "\n";
    return 0;
}