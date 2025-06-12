#include "main.h"
// Nuoseklioji paieška
int nuosek_paiesk(int mas[], int elem, const int n)
{
    for(int i = 0; i < n; i ++)
    {
        if(mas[i] == elem)
            return i;
    }
    return -1;
}
int main()
{
    const int n = 10;
    int mas[n] = {5, 8, 25, 1, 81, 6, 74, 2, 9, 21}; 
    int elem = 9; // Kažkoks elementas

    int index = nuosek_paiesk(mas, elem, n);
    index == -1 ? cout << "Nera tokio elemento masyve! " :
    cout << "Elementas "<<mas[index]<< " yra "<< index  << " masyvo vietoje";
    return 0;
}