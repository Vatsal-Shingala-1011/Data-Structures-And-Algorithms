#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> sorted(n,vector<int>(n,0));
	    for(int i=0;i<n;i++){
	        int k;
	        cin>>k;
	        sorted[i][0]=k;
	    }
	    for(int i=0;i<n;i++){
	        int k;
	        cin>>k;
	        sorted[i][1]=k;
	    }
	    sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            cout<<sorted[i][0]<<" "<<sorted[i][1]<<endl;
        }
	    int s=0;
	    vector<int> v;
	    for(int i=0;i<n;i++){
	        bool flag=true;
	        for(int j=0;j<v.size();j++){
	            if(v[j]<sorted[i][0]){
	                v[j]=sorted[i][1];
	                flag=0;
	            }
	        }
	        if(flag){v.push_back(sorted[i][1]);}
	       // s=max(s,v.size());
	       if(s<v.size()){s=v.size();}
	    }
	    cout<<s<<endl;
	}
    return 0;
}
