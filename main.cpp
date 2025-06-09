#include "main.h"
// std::fill() ir std::replace() algoritmai
int main(){
    vector<int> v;
    v.resize(15);
    fill(v.begin(), v.begin()+ 10, 5);
    for(auto vector : v)
    {
        cout << vector << " "; 
    }

    cout << "\n";

    replace(v.begin(), v.end(), 0, 4);
    for(auto vector : v)
    {
        cout << vector << " "; 
    }

    cout << "\n";

    std::string sakinys = "Man patinka eiti pasivaikscioti";
    cout << sakinys << "\n";
    replace(sakinys.begin(), sakinys.end(), 'a', 'e');
    cout << sakinys << "\n";
    return 0;
}