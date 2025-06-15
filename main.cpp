#include "main.h"
// std::ostream operator<< realizacija. std::ostream operator<< NEGALI būti virtual!
// object slicing

class Gyvunas {
    protected:
    string vardas;
    public:
    Gyvunas() = default;
    Gyvunas(string v) : vardas{v}{}
    virtual void kalbek() {
        std::cout << "Gyvūnas leidžia garsą\n";
    }

    virtual ostream& whoAmI(ostream &out) const
    {
        out << "As esu "<< vardas << " is Gyvunas klases";
        return out;
    }
    friend ostream& operator<<(ostream &out, const Gyvunas &gyv)
    {
        return gyv.whoAmI(out);
    }

    // friend ostream& operator<<(ostream &out, Gyvunas &gyv)
// {
//     out << gyv.vardas;
//     return out;
// } // Deja su šituo neišeitų padaryti virtual, nes yra friend funkcija
};


class Katinas : public Gyvunas {
    public:
    void kalbek() override { // Neprivalome čia dėti override, bet jis yra dėl saugumo
        std::cout << "Miau\n";
    }
    Katinas() = default;
    Katinas(string var) : Gyvunas{var}{}

    ostream& whoAmI(ostream &out) const
    {
        out << "As esu " << vardas << " is Katinas klases";
        return out;
    }
};

int main() {
    Gyvunas* g = new Katinas;
    g->kalbek(); // vėlyvas binding – kviečiama Katinas::kalbek()

    Gyvunas g2{"Pupis"};
    cout << g2 << "\n"; // isves: Pupis is Gyvunas klases

    Katinas k{"Murkis"};
    cout << k << "\n"; // isves: Murkis is Katinas klases

    Gyvunas g3 = k; // object slicing
    cout << g3 << "\n"; // isves: Murkis is Gyvunas klases
    return 0;
}