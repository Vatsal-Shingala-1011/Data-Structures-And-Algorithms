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
// class Solution { //O(1) extra space 
// //code 100%self not logic
// public:
//     void flatten(TreeNode* root) {
//         TreeNode* curr=root;
//         while(curr!=NULL)
//         {
//             if(curr->left){
//                 TreeNode* predecessor=curr->left;
//                 while(predecessor->right)//not null
//                 {
//                     predecessor=predecessor->right;
//                 }
//                 predecessor->right=curr->right;
//                 curr->right=curr->left;
//                 curr->left=NULL;
//             }
//             curr=curr->right;
            
//         }
//     }
// };