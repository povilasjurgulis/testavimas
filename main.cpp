#include "main.h"
// std::array
int main()
{
    std::array<int, 10> ar = {1, 8, 7, 2, 85, 222222, 435};
    sort(ar.begin(), ar.end());
    cout << ar.size() << " elementu: ";
    for(auto arr : ar)
    {
        cout << arr << " ";
    }
    cout << "\n";


    std::array<int, 15> ar2 = {777, 999, 111};
    cout << ar2.size() << " elementu: ";
    std::reverse_copy(ar2.begin(), ar2.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";


    cout << ar2.size() << " elementu: ";
    for(auto arr2 : ar2)
    {
        cout << arr2 << " ";
    }
    cout << "\n";

    return 0;
}