#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> m;
    int t=n;
    while(t--){
        string str;
        cin>>str;
        if(m.find(str)==m.end()){
            cout<<"OK"<<endl;
            m[str]++;
        }
        else{
            string s=str;
            // cout<<m[str]<<endl;
            string num=to_string(m[str]);
            s=s+num;
            m[str]++;
            cout<<s<<endl;
        }
    }
    return 0;
}