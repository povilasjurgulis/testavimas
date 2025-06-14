#include "main.h"
// Lambda funkcijos
// [] - išoriniai kintamieji, () - parametrai, {} - pati funkcija, ->int{} - funkciją padarys int tipo
int main()
{
    auto lam = [](){cout << "Sveiki visi!\n";}; // Labai paprasta lambda funkcija
    lam(); // Lambda funkcijos iškvietimas

    int a = 5, b = 6;

    auto lam2 = [a, b](int x, int y){ return x+y;}; // Lambda su išoriniu kintamuoju ir parametrais
    cout << "lam2 = " << lam2(a, b) <<"\n";

    auto lam3 = [](int c, int d){ return c*d;}; // Lambda su parametrais (bet be išorinių kintamųjų)
    cout << "lam3 = "<< lam3(5, 6) << "\n";

    auto lam4 = [a, b](){ return a + b;}; // Lambda su išoriniu kintamuoju
    cout << "lam4 = " << lam4() <<"\n";

    auto lam5 = [a, b](int x, int y){ return x+y;}; // Lambda su išoriniu kintamuoju ir parametrais
    cout << "lam5 = " << lam5(8, b) <<"\n"; // Argumentai gali būti ne tik a ir b, kadangi lambda turi parametrus

    auto lam6 = []()->int{ return 8.6;}; // Pavers į int
    cout << "lam6 = " << lam6() <<"\n";

    auto lam7 = [](double x, double y)->int{ return x + y;}(7.2, 8.7); // lam7 tampa nebe lambda funkcija, bet tiesiog int kintamuoju, nes yra (7.2, 8.7)
    cout << "lam7 = " << lam7 <<"\n"; // lam7 nebėra funkcija, o tiesiog int tipo kintamasis, todėl nebereikia rašyti skliaustų ()
    // Tačiau šitaip neveiks: cout << "lam7 su argumentais " << lam7(4.2, 6.6) << "\n";

    auto lam8 = [](double x, double y)->int{ return x + y;}; // šičia lam7 yra lambda funkcija, nes nėra skliaustų () po funkcijos
    cout << "lam8 = " << lam8(4.289, 6.5) <<"\n";



    // std::for_each()

    vector<int> v; int i = 10; int sk = 1;
    while(i!=0)
    {
        v.push_back(sk*=2);
        i--;
    }
    for_each(v.begin(), v.end(), [](int x){ cout << x << " ";}); // x yra tiesiog vektoriaus elementas. for_each() reikia <algorithm>

    cout << "\n";
    int suma=0;
    for_each(v.begin(), v.end(), [&suma](int x){ suma+=x;}); // Reikia suma perduoti kaip adresą
    cout << "Vektoriaus reiksmiu suma = " << suma << "\n";




    // std::transform su lambda funkcija panaudojimai:

    std::string zodis = "labas";
    std::transform(zodis.begin(), zodis.end(), zodis.begin(), [](char x){return toupper(x);}); // raidės pakeistos į didžiąsias
    cout << zodis << "\n";

    vector<double> v1 = {1, 2, 3};
    vector<double> v2(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), [](int x){return x*=2;}); // vektoriui v2 priskiriame v1 elementus padaugintus iš 2
    cout << "v2 elementai yra (du kartus didesni nei v1): ";
    for(auto vec : v2)
    {
        cout << vec << " ";
    }
    cout <<"\n";

    // Galima naudoti fiksavimo raktą [=], kad visus globalius kintamuosius būtų galima pasiekti per jų kopiją lambda lokaliame kode:
    double skaicius = 5.5;
    std::transform(v1.begin(), v1.end(), v2.begin(), [=](int x) {return skaicius * x;});
    cout << "v2 nauji elementai padauginti is 5.5: "; 
    for(auto vec : v2) cout << vec << " ";
    cout <<"\n";
    
    // Jei norime modifikuoti lokalią kopiją esančią lambda funkcijoje, reikia pridėti tarnybinį žodį mutable:
    std::transform(v1.begin(), v1.end(), v2.begin(), [=](int x)mutable->double{
        skaicius += 2; // pakeičiame skaičiaus reikšmę ir kadangi yra mutable, tai nebus kompiliavimo klaidos
        return skaicius * x;});
    cout << "v2 nauji elementai padauginti is kintancio skaiciaus: "; 
    for(auto vec : v2) cout << vec << " ";
    cout <<"\n";
    cout << "Bet pati 'skaicus' reiksme vis tiek nepasikeicia: " << skaicius << "\n";

    // Jei norime modifikuoti kintamąjį lambda funkcijoje taip, kad jis pasikeistų ir baigus lambda funkciją, reikia naudoti [&]:
    std::transform(v1.begin(), v1.end(), v2.begin(), [&](int x)mutable->double{
        skaicius += 2; // pakeičiame skaičiaus reikšmę ir kadangi yra mutable, tai nebus kompiliavimo klaidos
        return skaicius * x;});
    cout << "v2 nauji elementai padauginti is kintancio skaiciaus: "; 
    for(auto vec : v2) cout << vec << " ";
    cout <<"\n";
    cout << "'skaicus' reiksme pasikeite: " << skaicius << "\n"; 




    // std::sort su lambda funkcija panaudojimai:

    vector<int> vect = {89, 5, 7, 2, 8, 21, 1};
    std::sort(vect.begin(), vect.end(), [](int a, int b){return a > b;}); // Mažejimo tvarka rikiavimas. a - pirmesnis elementas, b - elementas einantis po a.
    for(auto ve : vect)
    {
        cout << ve << " ";
    }
    cout <<"\n";

    std::sort(vect.begin(), vect.end(), [](int a, int b){return a < b;}); // Didėjimo tvarka rikiavimas. a - pirmesnis elementas, b - elementas einantis po a.
    for(auto ve : vect)
    {
        cout << ve << " ";
    }
    cout <<"\n";

    return 0;
}