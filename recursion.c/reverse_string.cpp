#include<iostream>
using namespace std;

void reverse_str(string s)
{
    if(s.length()==0)
    {
        return;
    }
    string ros=s.substr(1);   //gives string from index 1 to end
    reverse_str(ros);
    cout<<s[0];
}

int main()
{

}
