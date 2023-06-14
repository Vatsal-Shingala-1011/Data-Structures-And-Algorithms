#include<iostream>
#include<string.h>
using namespace std;

int number_of_ways(int s,int e)
{
    if(e==0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
    
int count;
for(int i=1;i<=6;i++)
{
    count+=number_of_ways(s+1,e);
}
return count;
}


int main()
{
cout<<number_of_ways(0,3);
return 0;
}