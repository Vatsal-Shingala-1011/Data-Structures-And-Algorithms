//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution{ //self
    private:
    void solve(vector<vector<int>> m, int n, vector<string>& ans,int row,int col,string str){
        if(row==n-1 && col==n-1){
            ans.push_back(str);
            return;
        }
        //up check
        if(row>0 && m[row-1][col]==1 ){
            m[row][col]=0;
            str.push_back('U');
            solve(m,n,ans,row-1,col,str);
            m[row][col]=1;
        }
        //down check
        if(row<n-1 && m[row+1][col]==1 ){
            m[row][col]=0;
            str.push_back('D');
            solve(m,n,ans,row+1,col,str);
            m[row][col]=1;
        }
        //left check
        if(col>0 && m[row][col-1]==1 ){
            m[row][col]=0;
            str.push_back('L');
            solve(m,n,ans,row,col-1,str);
            m[row][col]=1;
        }
        //right check
        if(col<n-1 && m[row][col+1]==1 ){
            m[row][col]=0;
            str.push_back('R');
            solve(m,n,ans,row,col+1,str);
            m[row][col]=1;
        }
        return;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[n-1][n-1]==0){return ans;}
        string str;
        int row=0,col=0;
        solve(m,n,ans,row,col,str);
        return ans;
    }
};

    //     void getallpath(int matrix[MAX][MAX], int n,int row,int col,vector<string> &ans,string cur)
    // {
    //     if(row>=n or col>=n or row<0 or col<0 or matrix[row][col] == 0)
    //     return ;
        
    //     if(row == n-1 and col == n-1)
    //     {
    //         ans.push_back(cur);
    //         return ;
    //     }
        
    //     //now if its one we have 4 calls
    //     matrix[row][col] = 0;
        
    //     getallpath(matrix,n,row-1,col,ans,cur+"U");
    //     getallpath(matrix,n,row,col+1,ans,cur+"R");
    //     getallpath(matrix,n,row,col-1,ans,cur+"L");
    //     getallpath(matrix,n,row+1,col,ans,cur+"D");
        
    //     matrix[row][col] = 1;
        
    //     return ;
    // }
    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends