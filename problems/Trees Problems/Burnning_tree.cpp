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
// public:
//     TreeNode* mapping_parent(TreeNode* root,int start,map<TreeNode*,TreeNode*>& parent) //mapping and return target node
//     {
//         TreeNode* res=NULL; //start node
//         queue<TreeNode*> q; 
//         q.push(root);
//         parent[root]=NULL;
//         while(!q.empty())
//         {
//             TreeNode* front=q.front();
//             q.pop();
//             if(front->val==start)
//             {
//                 res=front;
//             }
//             if(front->left!=NULL)
//             {
//                 parent[front->left]=front;
//                 q.push(front->left);
//             }
//             if(front->right!=NULL)
//             {
//                 parent[front->right]=front;
//                 q.push(front->right);
//             }

//         }
//         return res;
//     }

//     void burntree(TreeNode* targetnode,map<TreeNode*,TreeNode*>& parent,int& time){
//         map<TreeNode*,bool> visited;
//         queue<TreeNode*> q;
//         q.push(targetnode);
//         visited[targetnode]=true;

//         while(!q.empty()){
//             int size=q.size();
//             bool flag=0;
//             for(int i=0;i<size;i++)
//             {
//                 TreeNode* front=q.front();
//                 q.pop();

//                 if(front->left!=NULL && !visited[front->left])
//                 {
//                     flag=1;
//                     q.push(front->left);
//                     visited[front->left]=true;
//                 }
//                 if(front->right!=NULL && !visited[front->right])
//                 {
//                     flag=1;
//                     q.push(front->right);
//                     visited[front->right]=1;
//                 }
//                 if(parent[front]!=NULL && !visited[parent[front]] )
//                 {
//                     flag=1;
//                     q.push(parent[front]);
//                     visited[parent[front]]=1;
//                 }
//             }
//             if(flag==1){
//             time++;
//             }
//         }

//     }

//     int amountOfTime(TreeNode* root, int start) {//100% done coded
//         int time=0;
//         map<TreeNode*,TreeNode*> parent;
//         TreeNode* targetnode=mapping_parent(root,start,parent);
//         burntree(targetnode,parent,time);
//         return time;
//     }
// };