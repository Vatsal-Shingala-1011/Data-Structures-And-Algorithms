#include<iostream>
using namespace std;

bool ispoweof2(int n)
{
    return(n && !(n & n-1) ); //  when n is zero 1st expression return 0 other wise second expression
}


int main()
{
    
    cout<<ispoweof2(16)<<endl;

}