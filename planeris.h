#ifndef PLANERIS_H
#define PLANERIS_H

#include "lektuvas.h"
class Planeris : public Lektuvas {
    private:

    string gamintojas;
    string modelis;
    string startavimas;

    public:

    Planeris() : Lektuvas(), gamintojas(""), modelis(""), startavimas("") {} // konstruktorius pagal nutylėjimą

    Planeris(double svor, string sparn_tipas, string medz, string gam, string mod, string start) 
        : Lektuvas(svor, sparn_tipas, medz), gamintojas(gam), modelis(mod), startavimas(start) {} // konstruktorius su parametrais


    // rule of three:
    virtual ~Planeris(){} // virtualus destruktorius
    
    Planeris& operator=(const Planeris &obj) { // priskyrimo operatorius
        if (this == &obj) 
            return *this; // grąžiname save, jei objektas yra tas pats
        Lektuvas::operator=(obj); // kviečiame bazinės klasės priskyrimo operatorių
        gamintojas = obj.gamintojas;
        modelis = obj.modelis;
        startavimas = obj.startavimas;
        return *this; // grąžiname save
    }

    Planeris(const Planeris &obj) 
        : Lektuvas(obj), gamintojas(obj.gamintojas), modelis(obj.modelis), startavimas(obj.startavimas) {} // kopijavimo konstruktorius
    // rule of 3 baigta.


    // perrašome grynąją virtualią funkciją iš bazinės klasės "Lektuvas"
    void spausdinti() const override {
        cout << "Planeris: " << endl;
        cout << "Svoris: " << get_svoris() << " kg" << endl;
        cout << "Sparno tipas: " << get_sparno_tipas() << endl;
        cout << "Medžiaga: " << get_medziaga() << endl;
        cout << "Gamintojas: " << gamintojas << endl;
        cout << "Modelis: " << modelis << endl;
        cout << "Startavimas: " << startavimas << endl;
    }

    // getteriai
    string get_gamintojas() const { return gamintojas; }
    string get_modelis() const { return modelis; }
    string get_startavimas() const { return startavimas; }

    // setteriai
    void set_gamintojas(const string &gam) { gamintojas = gam; }
    void set_modelis(const string &mod) { modelis = mod; }
    void set_startavimas(const string &start) { startavimas = start; }
};


#endif