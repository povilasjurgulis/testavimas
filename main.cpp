#include "main.h"
// queue (eilutė) - FIFO (First in First out). Pirmasis įdėtas elementas yra pirmasis, kuris bus pašalintas.
int main()
{
    queue<int> q;
    for(int i = 0; i < 10; i++)
        q.push(i);
    
    while(q.size())
    {
        cout << q.front() << " ";
        q.pop();
    }
    
    cout << "\n";

    return 0;
}