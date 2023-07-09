#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,l;
        cin>>n;
        cin>>l;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v[i]=a;
        }
        int start=0,end=l,flag=n,sflag,eflag,i=0,j=n-1;float t=0,t1,t2,sp1=1,sp2=1;
        while(flag>=1){
            sflag=v[i];
            eflag=v[j];
            t1=(sflag-start)/sp1;
            t2=(end-eflag)/sp2;
            if(t1<=t2){
                t+=t1;
                start=sflag;
                end=end-(sp2*t1);
                sp1++;
                flag--;
                i++;
            }
            else{
                t+=t2;
                end=eflag;
                start+=(t2*sp1);
                sp2++;
                flag--;
                j--;
            }
        }
        t+=(end-start)/(sp1+sp2);
        printf("%.15f\n",t);
    }
}