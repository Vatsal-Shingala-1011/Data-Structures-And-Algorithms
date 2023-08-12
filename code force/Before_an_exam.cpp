#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int d,sumtime;
    cin>>d>>sumtime;
    vector<int> min_time(d);
    vector<int> max_time(d);
    vector<int> ans(d);
    int mini,maxi;
    int min_sum=0,max_sum=0;
    int t=d;
    int index=0;
    while(t--){
        cin>>mini>>maxi;
        min_sum+=mini;
        max_sum+=maxi;  
        min_time[index]=mini;
        max_time[index]=maxi;
        ans[index++]=mini;   
    }
    if(sumtime==min_sum){
        cout<<"YES"<<endl;
    }
    else if(sumtime>=min_sum && sumtime<=max_sum){
        cout<<"YES"<<endl;
        int rem=sumtime-min_sum;
        int i=0;
        while(rem>0){
            if(rem<=max_time[i]-min_time[i]){
                ans[i]+=rem;
                break;
            }else{
                ans[i]=max_time[i];
                rem=rem-max_time[i]+min_time[i];
                i++;
            }
        }
        for(i=0;i<d;i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}