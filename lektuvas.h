#ifndef LEKTUVAS_H
#define LEKTUVAS_H

#include "main.h"

class Lektuvas{ // bazinė klasė (bet ir abstrakti klasė)
    private:

    double svoris;
    string sparno_tipas;
    string medziaga;


    public:
    
    Lektuvas() : svoris(0), sparno_tipas(""), medziaga("") {} // konstruktorius pagal nutylėjimą

    Lektuvas(double svor, string sparn_tipas, string medz) 
        : svoris(svor), sparno_tipas(sparn_tipas), medziaga(medz) {} // konstruktorius su parametrais

    Lektuvas(const Lektuvas &obj) // kopijavimo konstruktorius
        : svoris(obj.svoris), sparno_tipas(obj.sparno_tipas), medziaga(obj.medziaga) {} // kopijavimo konstruktorius

    Lektuvas& operator=(const Lektuvas &obj) { // priskyrimo operatorius
        if (this == &obj) 
            return *this; // grąžiname save, jei objektas yra tas pats
        svoris = obj.svoris;
        sparno_tipas = obj.sparno_tipas;
        medziaga = obj.medziaga;
        return *this; // grąžiname save
    }

    virtual ~Lektuvas(){} // virtualus destruktorius

    // getteriai
    double get_svoris() const { return svoris; }
    string get_sparno_tipas() const { return sparno_tipas; }
    string get_medziaga() const { return medziaga; }

    virtual void spausdinti() const = 0; // grynoji virtuali funkcija (padarome klasę abstrakčia)
};

#endif