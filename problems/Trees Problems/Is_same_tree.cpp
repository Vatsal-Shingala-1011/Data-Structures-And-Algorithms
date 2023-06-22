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

//here we travers tree and check every element is same or not
// class Solution { //self
//     bool check(TreeNode* p, TreeNode* q){
//         if(p==NULL && q==NULL){return true;}
//         if(p==NULL && q!=NULL){return false;}
//         if(p!=NULL && q==NULL){return false;}
//         bool l=check(p->left,q->left);
//         bool r=check(p->right,q->right);
//         bool val= p->val==q->val;
//         if(l & r &val){return true;}
//         else{return false;}
//     }
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         return check(p,q);
        
//     }
// };