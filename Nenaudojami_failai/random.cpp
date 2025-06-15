#include "main.h"
// random (RNG)
int main()
{
    // srand() nustato pradžios tašką. Jei srand() praleidžiame, tai interpretuojama kaip srand(1)
    srand(time(0)); // Dabar visada skaičiai bus skirtingi. time(0) reikia time.h bibliotekos.
    /* deja time(0) kinta vienos sekundės dažnumu, todėl jeigu labai greitai dar kartą paleisi programą,
    gausi tuos pačius skaičius */
    for(int i=0; i<5; i++)
    {
        printf("Skaicus %d yra random\n",rand());
    }

    cout << "Kiti random skaiciai: \n";

    // Teisingesnis random number būdas su <random> ir <chrono> bibliotekomis:
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count())); // engine - generuoja random skaičių sekas
    std::uniform_int_distribution<int> dist(0, 99); // distribution - sugeneruotas reikšmes transformuoja pagal intervalą
    for(int i = 0; i < 5; i ++)
    {
        cout << dist(mt) << " ";
    }
    cout << endl;


    // Pats GERIAUSIAS random number generating būdas, kuriam reikia tik <random> bibliotekos:
    std::random_device rd(); // Generuoja seedą (panašiai, kaip kad naudoti laiką su <chrono> tik čia reikia tik <random>)
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99);
    for(int i = 0; i < 5; i ++)
    {
        cout << dist(mt) << " ";
    }
    return 0;
}