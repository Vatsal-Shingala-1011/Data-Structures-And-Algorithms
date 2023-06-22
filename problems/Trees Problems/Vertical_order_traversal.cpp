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
// //PRE ORDER TRAVERSAL 
// //this code without mutiset
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int,map<int,vector<int>>> nodes;   //to keep 2 variable and one array 
//          // hd,   level,  value of node at that level
//         //map<int,map<int,multiset<int>>>nodes; one of solution contain multiset and no sorting in that code
//         queue<pair<TreeNode*,pair<int,int>>> q; //to store 3 variable in one queue
//          //    node pointer ,     hd, level  
//         vector<vector<int>> ans;
//         if(root==NULL){return ans;}

//         q.push(make_pair(root,make_pair(0,0)));
//         // q.push({root,{0,0}});

//         //PRE ORDER TRAVERSAL with keeping record of hd and level
//         while(!q.empty()){
//             pair<TreeNode* ,pair<int,int>> temp=q.front();
//             //auto temp=q.front()
//             q.pop();
//             TreeNode* frontNode=temp.first;
//             int hd=temp.second.first; 
//             int lvl=temp.second.second;   
//             //nodes store values which we jush pop from queue into map
//             nodes[hd][lvl].push_back(frontNode->val); //nodes[hd][lvl] is vector
//             if(frontNode->left) //if left is not null
//             {
//                 q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
//             }
//              if(frontNode->right) //if left is not null
//             {
//                 q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
//             }

//         }
//         //store values from map to vector ...,-1,0,1,... according to level
//         //self pattern
//         for(auto i:nodes){ //(int,map<int,vector<int>)  // i is map of every vertical from minimum to.
//             vector<int> v;                              //i is map corresponding to every hd
//             vector<int> t;
//             for(auto j:i.second){ //(map<int,vector<int>) // j is collection of vectors every level from mini to...   
//                                 //j is vector to corresponding level containing values of node in that level                                 
//                 for(auto k:j.second) // vector<int> // k is values in vector from every level
//                 {                   //There may be multiple nodes in the same column
//                     v.push_back(k);
//                 }
//                 sort(v.begin(), v.end());
//                 for(auto tt:v){
//                 t.push_back(tt);
//                 }
//                 v.clear();
//             }
//             ans.push_back(t);
//         }
//     return ans;
//     }
// };