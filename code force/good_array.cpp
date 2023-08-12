#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        long long k,req=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>k;
            v[i]=k;
            if(k==1) req++;
            sum+=k-1;
        }
        if(n==1) {
            cout<<"NO"<<endl;
        }
        else if(sum>=req) cout<<"YES"<<endl;
        else{
             cout<<"NO"<<endl;
        }
    }
    return 0;
}