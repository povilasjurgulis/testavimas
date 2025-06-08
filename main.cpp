#include "main.h"
// Stekas - last in first out (LIFO) konteineris. Elementus sudedame į galą (Last In) ir spausdinant iš galo triname (First Out). 
int main(){
    // Steko funkcijos: empty, size, push, pop, top
    stack<int> stekas{};
    stack<int> reverseStekas{};

    if(stekas.empty())
        for(int i = 0; i < 10 ; i ++)
            stekas.push(i+1);
    
    cout << "Paprastas stekas: \n";
    while(stekas.size() != 0)
        {
            cout << stekas.top() << " "; // Išspausdins 10 9 8 7 6 5 4 3 2 1
            reverseStekas.push(stekas.top());
            stekas.pop();
        }
    
    cout << "\nReverse stekas: \n";
    while(reverseStekas.size())
        {
            cout << reverseStekas.top() << " "; // Išspausdinas 1 2 3 4 5 6 7 8 9 10
            reverseStekas.pop();
        }
    
    return 0;
}