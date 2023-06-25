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
// class Solution { //100%self
// public:
//     void inorder(TreeNode* root,vector<int>& sort){
//         if(root==NULL)
//         {
//             return;
//         }
//         inorder(root->left,sort);
//         sort.push_back(root->val);
//         inorder(root->right,sort);
//     }
//     bool findTarget(TreeNode* root, int k) {
//     vector<int> sort;
//     inorder(root,sort);
//     int i=0,j=sort.size()-1;
//     while(i<j)
//     {
//         if(sort[i]+sort[j]==k)
//         {return true;}
//         else if(sort[i]+sort[j]>k){
//             j--;}
//         if(sort[i]+sort[j]<k)
//         {i++;}
//     }
//     return false;
//     }
// };