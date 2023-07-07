#include <iostream>
using namespace std;

int numberOfones(int n)
{
    int q= 0;
    while(n!=0)
    {
        n = n & (n - 1);
        q=q+1;        
    }
    return q;
}

int main()
{
    cout << numberOfones(19) << endl;
    return 0;
}