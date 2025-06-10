#include "main.h"
// std::chrono
using namespace std::chrono;  // šito nereikia, nes jau turime using namespace std; bet tiesiog parodau
int main()
{
    chrono::seconds five_seconds = chrono::seconds(5); // sekundžių tipas. Priskiriame 5 sekundes.
    auto five_seconds2 = 5s; // kitoks būdas parašyti 5 sekundes.
    //this_thread::sleep_for(five_seconds); // iš std::thread. Will pause for 5 seconds.
    auto one_second = 1s; // viena sekundė
    cout << 1 << " ";
    this_thread::sleep_for(one_second); // reikia #include <thread>
    cout << 2 << " "; 
    this_thread::sleep_for(one_second);
    cout << 3 << "\n";

    auto day = 24h;
    auto my_seconds = seconds(day); // konvertuojame dieną į sekundes
    auto trukme =duration<double>(my_seconds);
    cout << "Dienoje yra " << trukme.count() << " sekundes\n";

    auto my_hours = hours(day); // konvertuojame dieną į valandas. Tačiau valandų neitų konvertuoti į dienas!
    cout << "Dienoje yra " << my_hours.count() << " valandos\n";

    auto old = system_clock::now();
    vector<int> v{};
    v.resize(400000);
    std::fill(v.begin(), v.end(), 15);
    std::sort(v.begin(), v.end());
    auto durationn = system_clock::now() - old; // timepoint2 - timepoint1 = duration
    cout << "Uztruko: " <<duration_cast<microseconds> (durationn).count()<< " microseconds\n";

    // Geresnis būdas apskaičiuoti laiką:
    auto start = chrono::high_resolution_clock::now(); // Pradžia
    vector<int> v2{};
    v2.resize(400000);
    std::fill(v2.begin(), v2.end(), 15);
    std::sort(v2.begin(), v2.end());
    auto end = high_resolution_clock::now(); // Pabaiga
    chrono::duration<double> diff = end - start; // Kiek užtruko
    cout << "Uztruko: " << diff.count() <<" s\n";

    cout << "Milisekundemis uztruko: " << duration_cast<milliseconds>(diff).count() << " s\n";
    return 0;
}