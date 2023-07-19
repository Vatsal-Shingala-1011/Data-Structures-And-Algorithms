//unit weight only for diff weigth dijkstra algo
////BSF
// class Solution {
//   public:
//     vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){ //self
//         unordered_map<int,list<int>> adj;
//         for(int i=0;i<M;i++){
//             int u=edges[i][0];
//             int v=edges[i][1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         unordered_map<int,bool> visited;
//         unordered_map<int,int> parent;
//         queue<int> q;
//         q.push(src);
//         visited[src]=true;
//         while(!q.empty()){
//             int front=q.front();
//             q.pop();
//             for(auto i:adj[front]){
//                 if(!visited[i]){
//                     visited[i]=true;
//                     parent[i]=front;
//                     q.push(i);
//                 }
//             }
//         }
//         vector<int> ans;
//         for(int i=0;i<N;i++){
//             int currNode=i;
//             int dis=0;
//             while(currNode!=src ){
//                 if(parent.find(currNode)==parent.end()) {
//                     dis=-1;
//                     break;
//                 }
//                 currNode=parent[currNode];
//                 dis++;
//             } 
//             ans.push_back(dis);
//         }
//         return ans;
//     }
// };
