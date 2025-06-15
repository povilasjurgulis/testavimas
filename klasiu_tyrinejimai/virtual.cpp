#include "main.h"
// Polimorfizmas. Vėlyvas binding - kai yra virtual funkcija.
class Gyvunas {
public:
    virtual void kalbek() {
        std::cout << "Gyvūnas leidžia garsą\n";
    }
};

class Katinas : public Gyvunas {
public:
    void kalbek() override { // Neprivalome čia dėti override, bet jis yra dėl saugumo
        std::cout << "Miau\n";
    }
};

int main() {
    Gyvunas* g = new Katinas;
    g->kalbek(); // vėlyvas binding – kviečiama Katinas::kalbek()
    return 0;
}