#include<iostream>
using namespace std;

int getBit(int n,int pos) //what is bit at position
{
    return((n&(1<<pos))!=0);
}

int setBit(int n,int pos) //set means put 1 at given position
{
    return(n | (1<<pos));
}

int clearBit(int n,int pos) //put 0 at given position
{
    int mask=~(1<<pos);
    return(n & mask);
}

int updateBit(int n,int pos,int value) //update bit with given bit(value)
//update bit is cleat bit and then set bit 
{
    int mask=~(1<<pos);
    n=n&mask;
    return(n | value<<pos);
}
int main()
{
    // count<<getBit(5,2)<<endl;
    cout<<updateBit(5,1,1)<<endl;

}