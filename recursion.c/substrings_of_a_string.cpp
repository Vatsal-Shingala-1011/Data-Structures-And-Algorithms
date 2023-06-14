#include<iostream>
#include<string.h>
using namespace std;
//done
string substring(string s,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return 0;
    }
    char ch=s[0];
    string ros=s.substr(1);
    substring(s,ans);
    substring(s,ans+ch);


}

main()
{

}