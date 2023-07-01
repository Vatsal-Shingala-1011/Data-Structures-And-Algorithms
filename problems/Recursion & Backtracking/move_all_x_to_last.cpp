#include<iostream>
#include<string.h>
using namespace std;

string move_all_x_to_last(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch=s[0];
    string str= move_all_x_to_last(s.substr(1));
    if(ch=='x')
    {
        str=str+ch;
    }
    else{
        str=ch+str;
    }

    return str;
}

int main()
{
    string s="hdkxxxhdhkcxxhkxxhkx";
    cout<<move_all_x_to_last(s);
    return 0;
}