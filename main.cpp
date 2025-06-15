#include "main.h"


int main() {
    
    const int &ref3 = 8;
    int a = 6;
    cout << ref3 + a;
    return 0;
}