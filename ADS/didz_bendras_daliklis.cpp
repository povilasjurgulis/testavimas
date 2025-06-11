#include "main.h"
// GCD - Didžiausias bendras daliklis (EUKLIDO ALGORITMAS)
int GCD(int a, int b)
{
    int c;
    while(b>0)
    {
        c = b;
        b = b % a;
        a = c;
    }
    return a;
}
int main()
{
    int a = 28, b = 68;
    cout << GCD(a, b);
    return 0;
}