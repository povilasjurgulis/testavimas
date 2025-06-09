#include "main.h"
// try catch throw 
int padalinimas(int a, int b)
{
    if(b == 0) 
        throw std::runtime_error("Negalima dalinti is nulio!"); // kokį errorą mes
    return a / b;
}

int natural_skaicius(int c)
{
    if(c<0)
        throw std::string("Turi buti naturalusis skaicius!");
    return c;
}

int main(){
    int f = -7;
    try
    {
        //cout << padalinimas(8, 0) <<"\n";
        cout << natural_skaicius(f) << "\n";
    }
    catch(std::runtime_error &negerai)
    {
        cerr << "Klaida: " << negerai.what() << "\n"; // .what() naudoti, kai tipas yra std::runtime_error
    } // Kai vienas catch blokas pagauna išimtį, visi kiti catch blokai praleidžiami.
    catch(std::string &klaida)
    {
        cout << "Klaida: " << klaida << "\n";
    }
    cout << "\nNetgi kai yra error, vis tiek kodas veiks toliau, kadangi cia tik try catch throw";
 
    return 0;
}