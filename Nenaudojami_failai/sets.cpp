#include "main.h"
// No two elements in a set can have the same value and value are automatically stored in ascending orders.
int main(){
    set<int> setas = {8, 6, 7, 9, 2};
    for(auto s : setas)
    {
        cout << s << " ";
    }
    cout << "\n";

    set<int>::iterator it_start = setas.begin();
    it_start++;
    set<int>::iterator it_end = setas.end();
    it_end--;
    set<int> new_set(it_start, it_end);
    for(auto new_s : new_set)
    {
        cout << new_s << " ";
    }
    cout << "\n";

    set<int> set2;
    set2.insert(15);
    set2.insert(8);
    set2.insert(3);
    set2.insert(8);
    set2.insert(8);
    for(auto s2 : set2)
    {
        cout << s2 << " ";
    }
    cout << "\n";

    set<int>::iterator kur_yra_8 = set2.find(8);
    if(kur_yra_8 != set2.end())
    {
        cout << "Value "<< *kur_yra_8 << " found!\n";
    }
    else
    {
        cout << "Value not found!\n";
    }

    //set2.erase(8);
    if(set2.erase(8) == 1)
    {
        cout << "The element was successfully erased!\n";
    }
    else
    {
        cout << "The element was not successfully erased (maybe it just didn't exist)\n";
    }
    set<int>::iterator kur_yra_8_2nd = set2.find(8);
    if(kur_yra_8_2nd != set2.end())
    {
        cout << "Value "<< *kur_yra_8_2nd << " found!\n";
    }
    else
    {
        cout << "Value not found!\n";
    }
    return 0;
}