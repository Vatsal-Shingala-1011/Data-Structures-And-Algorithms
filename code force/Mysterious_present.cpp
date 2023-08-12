#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}
 bool check(vector<int>& base1,vector<int>& base2)
 {
     if(base2[0]<base1[0] && base2[1]<base1[1]){
         return true;
     }
     else 
     return false;
 }

int main(){
    int n,w,h;
    cin>>n>>w>>h;
    int t=n;
    vector<int> ans;
    vector<vector<int>> v(n,vector<int>(2));
    for(int i=0;i<n;i++){
        int f,s;
        cin>>f>>s;
        v[i][0]=f;
        v[i][1]=s;
        if(v[i][0]>v[i][1]) swap(v[i][0],v[i][1]);
    }
    sort(v.begin(),v.end(),cmp);
    int prev=-1;
    vector<int>currrow(n+1,0);
    vector<int>nextrow(n+1,0);
    for(int curr=n-1;curr>=0;curr--)
    {
        for(int prev=curr-1;prev>=-1;prev--)
        {
            // INCLUDE THE HEIGHT 
            int take=0;
            if(prev==-1 || ( check(v[curr],v[prev]) && ((v[curr][0]>w &&v[curr][1]>h)||(v[curr][0]<w &&v[curr][1]<h)) )) //
                take=1+nextrow[curr+1];

            // EXCLUDE THE HEIGHT
            int notake= 0 + nextrow[prev+1];

            currrow[prev+1]=max(take,notake);  
        }
        // after every iteration upper row will be equal to currrow 
        nextrow=currrow;  
    }
    cout<<nextrow[0];

    return 0;
}

