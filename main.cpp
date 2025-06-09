#include "main.h"
// std::map
int main(){
    map<string, int> kiek_metu; // string bus key, o int bus value. Kad sužinoti kiek kažkam yra metų, reikia žinoti žmogaus vardą.
    map<string, int> kiek_metu_jiems = { {"Povilas", 20}, {"Arnas", 20}, {"Eligijus", 21}, {"Eimantas", 20}, {"Nerijus", 19}, {"Motiejus", 35} };

    cout << "Map size: "<< kiek_metu_jiems.size() << "\n";

    cout << "Povilui yra "<< kiek_metu_jiems.at("Povilas") << " metu\n";

    map<string, int>::iterator it = kiek_metu_jiems.begin();
    for(auto mapas : kiek_metu_jiems)
    {
        cout << mapas.first << " " << mapas.second ; // mapas.first duoda vardą (key), o mapas.second duoda metus (value)
        it++;
        if(it == kiek_metu_jiems.end())
        {
        cout << " metu.\n"; 
        break;
        }
        cout << " metu, "; 
    }

    kiek_metu_jiems.insert({"Antanas", 45});
    cout <<"Antanui yra " << kiek_metu_jiems.at("Antanas") << " metai\n";
    kiek_metu = kiek_metu_jiems;
    it = kiek_metu.begin();
    for(auto kiek : kiek_metu)
    {
        cout << kiek.first << " " << kiek.second;
        it++;
        if(it == kiek_metu.end())
        {
            cout << " metu.\n";
            break;
        }
        cout << " metu, ";
    }

    if(kiek_metu.count("Steven"))
        cout << "Steven yra";
    else
        cout << "Steven nera";
    return 0;
}