// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     void solve(TreeNode* root, int targetsum,vector<long long> path,int& count)
//     {
//         if(root==NULL)
//         {
//             return;
//         }
//         path.push_back(root->val);
//         solve(root->left,targetsum,path,count);
//         solve(root->right,targetsum,path,count);
//         int n=path.size();
//         long long sum=0;
//         for(int i=n-1;i>=0;i--)
//         {
//             sum+=path[i];
//             if(sum==targetsum)
//             {
//                 count++; 
//             //dont break because there may be more than one path because tree contain -ve values als0
//             }
//         }
//         //no need to pop because scop of variable is goes as fun end
//     }
// public:
//     int pathSum(TreeNode* root, int targetsum) {
//         vector<long long> path;
//         int count=0;
//         solve(root,targetsum,path,count);
//         return count;
//     }
// };