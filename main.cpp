#include "main.h"
class Klase{
    private:

    double* sk;
    int kiekis;
    friend class Klase2; // šitaip deja pažeidžiame inkapsuliaciją (ir nepatariama taip daryti)
    public:

    Klase() : kiekis{0}, sk{new double[0]} { cout << "Klase 'klase' sukonstruota!\n";} // konstruktorius (c-tor)
    //Klase(int size = 0) : kiekis{size} {} //- čia irgi yra default konstruktorius, tačiau jau turime vieną default c-tor, todėl negalima antro
    Klase(int dydis) // čia nėra default c-tor
    {
        this->kiekis = dydis;
        this->sk = new double[dydis];
    }
    Klase(int dydis, int elementas) // čia aišku irgi nėra default c-tor
    {
        this->kiekis = dydis;
        this->sk = new double[dydis];
        std::fill(sk, sk+kiekis, elementas);
    }
    ~Klase() { delete[] sk;} // destruktorius
    int get_size() 
    { 
        return kiekis;
    }
    double get_sk(const int id) const
    {
        if(id < 0 || id >= kiekis)
        {
            std::cerr<<"Bandai pasiekti neegzistuojanti elementa! ";
            return -1;
        }
        return sk[id];
    }
    double operator[] (int &id) // double operator[], nes *sk irgi yra double
    {
        return get_sk(id);
    }
    
};

class Studentas{
    private:
    
    Klase kl;

    public:

    Studentas(){ cout << "Klase 'Studentas' sukonstruota! ";}
};

class Klase2{ // ši klasė yra klasės "Klase" friend, todėl turi prieigą prie private elementų ar metodų
    public:
    void rodyk(Klase a)
    {
        cout << "Klases 'Klase' objekto dydis (kiekis): " << a.kiekis; // galime accessinti private members iš friend klasės "Klase"
    }
};
int main()
{
    Klase povis(4, 5);
    cout << "Size = "<< povis.get_size() << "\nElementai: ";
    for(int i = 0; i < povis.get_size(); i++)
    {
        cout << povis[i] << " ";
    }
    cout << "\nTikriname\n";
    Studentas st; // Taigi, bus iš pat pradžių iškviesta 'Klase' konstruktorius, o tik vėliau 'Studentas' konstruktorius

    cout << "\n";
    Klase2 povis2;
    povis2.rodyk(povis);

    return 0;
}