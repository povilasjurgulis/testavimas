#include "main.h"
// fill. resize() VS reserve()
int main(){
    vector<int> v;
    v.resize(6); // jeigu būtų v.reserve(6), tai programa nieko nespausdintų

    fill(v.begin(), v.end(), 5);
    for(auto vector : v)
    {
        cout << vector << " "; // Spausdins 5 5 5 5 5 5, kadangi resize(), o ne reserve()
    }
    return 0;
}