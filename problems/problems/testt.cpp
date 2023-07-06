#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int q;
	    cin>>q;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){cin>>arr[i];}
	    sort(arr.begin(),arr.end());
	    vector<int> v;
	    int size=v.size();
	    int sum=0;
	    for(int i=0;i<=n-3;i++){
	        int a=((n-1-i)*(n-i-2))/2;
	        sum=sum+a;
	        v.push_back(sum);
	    }
	    int index;
	    int ss=v.size();
	    while(q--){
	        cin>>index;
	        for(int i=0;i<ss;i++){
	            if(v[i]>=index){
	                cout<<arr[i]<<endl;
	                break;
	            }
	        }
	    }
	}
	return 0;
}