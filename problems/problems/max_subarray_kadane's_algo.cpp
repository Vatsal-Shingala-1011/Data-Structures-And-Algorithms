#include<bits/stdc++.h> //my code
using namespace std;

class Solution{
    public:
    
    long long maxSubarraySum(int arr[], int n){
    long long  sum=0;
    long long max=INT_MIN;
    for (int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum>0){
        if(sum>max){
            max=sum;
        }
        }
        if(sum<0 ){
            if(sum>max){
            max=sum;
            }
            sum=0;
        }
    }
    return max;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends