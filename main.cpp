#include "planeris.h"

int main() {
    list<Planeris> sarasas;
    cout << "Iveskite 3 objektus Planeris klasei:" << endl;
    for (int i = 1; i <= 3; ++i) {
        cout << "\nIveskite " << i << "-ojo planerio duomenis: \n";

        double svoris;
        std::string sparnoTipas;
        std::string medziaga;
        std::string gamintojas;
        std::string modelis;
        std::string startavimas;

        cout << "Svoris (kg): ";
        cin  >> svoris;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Sparno tipas: ";
        getline(cin, sparnoTipas);

        cout << "Medziaga: ";
        getline(cin, medziaga);

        cout << "Gamintojas: ";
        getline(cin, gamintojas);

        cout << "Modelis: ";
        getline(cin, modelis);

        cout << "Startavimas (is lyno / nuo kalno): ";
        getline(cin, startavimas);

        sarasas.emplace_back(svoris, sparnoTipas, medziaga, gamintojas, modelis, startavimas);
    }

    sarasas.sort([](const Planeris &x, const Planeris &y) {
        return x.get_svoris() > y.get_svoris(); // rūšiavimas atvirkštine (desc) tvarka
    });

    cout << "\n" << left << setw(10) << "Svoris" << setw(15) << "Sparnas" << setw(15) << "Medziaga" << setw(15) << "Gamintojas"
         << setw(15) << "Modelis" << setw(18) << "Startavimas" << '\n';
    cout << std::string(88, '-') << "\n";

    for(const auto &planeris : sarasas) {
        cout << left << setw(10) << planeris.get_svoris() << setw(15) << planeris.get_sparno_tipas() 
             << setw(15) << planeris.get_medziaga() << setw(15) << planeris.get_gamintojas() 
             << setw(15) << planeris.get_modelis() << setw(18) << planeris.get_startavimas() << '\n';
    }

    sarasas.clear(); // išvalome sąrašą

    return 0;
}