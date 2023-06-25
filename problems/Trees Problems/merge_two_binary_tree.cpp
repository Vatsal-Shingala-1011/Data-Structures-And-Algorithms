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
// public://there is 2 approches here we use space optimum
//     void convert_into_sorted_DLL(TreeNode* root,TreeNode* head)
//     {//not done 
//         if(root==NULL)
//             return;
//         convert_into_sorted_DLL(root->right,head);
//         root->right=head;
//         if(head!=NULL){
//             head->left=root;
//         }
//         convert_into_sorted_DLL(root->left,head);  
//     }

//     TreeNode* merge_linkedlist(TreeNode* head1,TreeNode* head2){//done
//         TreeNode* head=NULL;
//         TreeNode* tail=NULL;
//         while(head1!=NULL && head2!=NULL){
//             if(head1->val < head2->val)
//             {
//                 if(head==NULL)
//                 {
//                     head=head1;
//                     tail=head1;
//                     head1=head1->right;
//                 }
//                 else
//                 {
//                     tail->right=head1;
//                     head1->left=tail;
//                     tail=head1;
//                     head1=head1->right;
//                 }           
//             }
//             else
//             {
//                 if(head==NULL)
//                 {
//                     head=head2;
//                     tail=head2;
//                     head1=head2->right;
//                 }
//                 else
//                 {
//                     tail->right=head2;
//                     head2->left=tail;
//                     tail=head2;
//                     head2=head2->right;
//                 }     

//             }
//         }
//         while(head1!=NULL)
//         {
//             tail->right=head1;
//             head1->left=tail;
//             tail=head1;
//             head1=head1->right;
//         }
//         while(head2!=NULL)
//         {
//             tail->right=head2;
//             head2->left=tail;
//             tail=head2;
//             head2=head2->right;
//         }
//     return head;
//     }

//     int count_nodes(TreeNode* head){
//         int cnt=0;
//         TreeNode* temp=head;
//         while(temp!=NULL)
//         {
//             cnt++;
//         }
//         return cnt;

//     }
//     TreeNode* sorted_linkedlist_to_BST(TreeNode* head,int n)
//     {
//         if(n<=0 || head==NULL)
//         {
//             return NULL;
//         }
//         TreeNode* left=sorted_linkedlist_to_BST(head,n/2-1);
//         head->left=left;

//         head=head->right;

//         head->right=sorted_linkedlist_to_BST(head,n/2-1);
//         return head;
//     }

//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) { //some error not try to solve yet
//         //BST to sorted DLL
//         TreeNode* head1=NULL;
//         convert_into_sorted_DLL(root1,head1);
//         head1->left=NULL;

//         TreeNode* head2=NULL;
//         convert_into_sorted_DLL(root2,head2);
//         head2->left=NULL;
//         //merge sorted DLL
//         TreeNode* head = merge_linkedlist(head1,head2);
//         //convert to BST
//         return sorted_linkedlist_to_BST(head,count_nodes(head));
//     }
// };