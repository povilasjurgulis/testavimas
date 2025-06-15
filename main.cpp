#include "main.h"
// l-value yra left value (tarkim kintamieji ar nuorodos &).
// r-value yra right value (tarkim skaičiai (pvz: 7)).

int main() {
    
    const int &ref3 = 8; // &ref3 yra l-value nuoroda, o 8 yra r-value
    int a = 6; // a yra non-const l-value, 6 yra r-value
    const int &ref4 = ++a;
    const int &ref5 = a++;
    cout << ref3 + a << endl;
    cout << ref4 << endl << ref5  << endl;

    int x = 10;
    ++x = 20; // veikia, nes ++x yra left value.
    // tačiau x++ = 20 NEVEIKIA! Kadangi x++ yra r-value (right value)
    cout << x << endl;

    const int &&ref6 = 15; // &&ref6 yra r-value nuoroda inicializuota su r-value reikšme 15
    cout << ref6 << endl; // dabar ref6 jau yra l-value
    return 0;
}