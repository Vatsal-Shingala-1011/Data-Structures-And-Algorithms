#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n;
    cin>>s;
    int t=n;
    map<float,int> m;
     // dis   ,ant
    while(t--){
    int x,y,k;
    cin>>x;
    cin>>y;
    cin>>k;
    double dis=sqrt((x*x)+(y*y));
    m[dis]=k;
    }
    int req=1000000-s;
    int sum=0;
    float ans=0;
    for (const auto& pair : m) {
        if(sum>=req) break;
        ans=pair.first;
        sum+=pair.second;
    }
    if(sum<req) cout<<-1;
    else {printf("%.8f\n",ans);}
    return 0;
}