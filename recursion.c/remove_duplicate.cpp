#include<iostream>
#include<string.h>
using namespace std;
string remove_duplicate(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch=s[0];
    string str=remove_duplicate(s.substr(1));
    if(ch!=str[0])
    {
        str=ch+str;
    }
    return str;
}

main()
{
    string s="aaabbbccddddfg";
    cout<<remove_duplicate(s);
return 0;
}