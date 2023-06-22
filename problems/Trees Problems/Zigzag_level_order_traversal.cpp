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
// class Solution { //done
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int> > ans;
//         if(root==NULL){return ans;}
//         queue<TreeNode*> q; // queue contain poiner 
//         bool lefttoright=true;
//         q.push(root);
        
//         while(!q.empty()){
//             int n=q.size();
//             vector<int> level_ans(n);

//             //for every level
//             for(int i=0;i<n;i++)
//             {
//                 TreeNode* front=q.front();
//                 q.pop();
//                 int index=lefttoright?i:n-i-1;
//                 level_ans[index]=front->val;
//                 if(front->left!=NULL)
//                 {
//                     q.push(front->left);
//                 }
//                 if(front->right!=NULL)
//                 {
//                     q.push(front->right);
//                 }
//             }
//             //direction change
//             lefttoright=!lefttoright;
//             ans.push_back(level_ans);
//         }
//     return ans;
//     }
// };