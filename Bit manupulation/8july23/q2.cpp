#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int j;
            cin>>j;
            v[i]=j;
        }
        bool flag=true;
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            if(v[i]==v[i+1] || v[i]==v[i+1]-1) continue;
            else {
                cout<<"NO"<<endl;
                flag=false;
                break;
            }
        }
        if(flag){
                cout<<"YES"<<endl;
        }
    }
}