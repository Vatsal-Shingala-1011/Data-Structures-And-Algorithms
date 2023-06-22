#include <bits/stdc++.h>
using namespace std;
//Optimal approch without queue
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int k) {
    vector<long long> ans;
    queue<long long> q;
    for(int i=0;i<k;i++)
    {
        if(A[i]<0)
        {
            q.push(i); //index
        }
    }
    if(!q.empty())
    {
        ans.push_back(A[q.front()]); //value
    }
    else{ans.push_back(0);}
    int j=0;
    for(int i=k;i<N;i++)
    {
        if(A[j]<0){q.pop();}
        j++;
        if(A[i]<0){q.push(i);}//index}
        if(!q.empty()){ans.push_back(A[q.front()]);} //value
        else{ans.push_back(0);}
    }
    return ans;
}