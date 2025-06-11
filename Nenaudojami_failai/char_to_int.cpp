#include "main.h"
// char to int konvertavimas
int main()
{
    cout << 2 % 7 ;
    std::string skaicius; 
    int k, n; // n-tainė skaičiavimo sistema. k - kiek skaitmenų skaičiųje.
    
    cout << "Iveskite desimtaini skaiciu: "; cin >> skaicius;
    k = skaicius.size();
    cout << "Iveskite kelintaine skaiciu sistema konvertuoti: "; cin >> n;
    cout <<"Skaiciuje "<< skaicius << " yra " << k << " skaitmenys\n"; 

    vector<int> skaitm;
    for(int i = 0; i < k; i ++)
    {
        skaitm.push_back(skaicius[i]-'0'); // - '0' naudojamas, kad konvertuotų char to int
        cout << skaitm[i];
    }

    return 0;
}