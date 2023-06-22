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

//self and another code both are good and have same time complexity
// class Solution { //100% self
// public:  //left balance right balance then only
//     int height(TreeNode* root,int& flag){
//         if(flag==-1){return 0;}   //if(lefth==-1) or right==-1 return -1;
//                                    //in below code
//         if(root==NULL){return 0;}
//         int l=height(root->left,flag);
//         int r=height(root->right,flag);
//         if(abs(l-r)>1)
//         {
//             flag=-1;
//             return 0;
//         }
//         return max(l,r) +1;
//     }
//     bool isBalanced(TreeNode* root) {
//         if(root==NULL){return true;}
//         int flag=1;
//         height(root,flag);
//         if(flag==-1){return false;}
//         else{return true;}
//     }
// };


// // class Solution {
// // public:
// //     bool isBalanced(TreeNode* root) {
// //         if(height(root)==-1) return false; // if it is balanced then height will be calculated 
// //         //or it will just return -1
// //         return true;
// //     }
// //     int height(TreeNode* root){
// //         if(!root) return 0;
// //         int lefth=height(root->left);
// //         if(lefth==-1) return -1;
// //         int righth=height(root->right);
// //         if(righth==-1) return -1;
// //         if(abs(lefth-righth)>1) return -1;
// //         return max(lefth,righth)+1;
// //     }
// // };