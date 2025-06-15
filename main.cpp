#include "main.h"
// std::iota

int main() {
    vector<int> v(10);
    std::iota(v.begin(), v.end(), -10); // užpildome vektorių v nuo -10 iki -1 (nes v turi 10 elementų)
    std::for_each(v.begin(), v.end(), [](int vect){ cout << vect << " ";});


    // RNG!

    std::random_device rd;
    cout << endl << "Random skaicius " << rd() <<"\n"; // Lėtas RNG būdas
    // Geriausias RNG būdas:
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 99);
    for(auto &vec : v)
    {
        cout << dist(mt) << " ";
    }
  return 0;
}