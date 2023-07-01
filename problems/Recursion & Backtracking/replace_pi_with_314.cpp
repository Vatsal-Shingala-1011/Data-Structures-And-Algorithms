#include<iostream>
#include<string.h>
using namespace std;
int replace(string s)
{
    if(s.length()==0)
    {
        return 0;
    }
    if(s[0]=='p'&&s[1]=='i')
    {
        cout<<3.14;
        replace(s.substr(2));
    }
    else
    {
        cout<<s[0];
        replace(s.substr(1));
    }
    return 0;
}

main()
{
    string s="vatsalpishinpigala";
    replace(s);
return 0;
}