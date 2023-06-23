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
//     int findindex(vector<int> inorder,int val,int n)//can use mapping for O(1) time complexity to find any index
//     {
//         for(int i=0;i<n;i++)
//         {
//             if(inorder[i]==val)
//             {
//                 return i;
//             }
//         }
//         return -1;
//     }
// TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int& index,int inorderstart,int inorderend,int n)
//     {
//         if(index>=n || inorderstart>inorderend)
//         {
//             return NULL;
//         }
//         //make a node
//         int ele=preorder[index];
//         TreeNode* root=new TreeNode(ele);
//         int indexininorder=findindex(inorder,ele,n);
//         index++;
//         //recursive call
//         root->left=solve(preorder,inorder,index,inorderstart,indexininorder-1,n);
//         root->right=solve(preorder,inorder,index,indexininorder+1,inorderend,n);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int PreOrderIndex=0;
//         int n=preorder.size();
//         TreeNode* ans=solve(preorder,inorder,PreOrderIndex,0,n-1,n);
//         return ans;
//     }
// };