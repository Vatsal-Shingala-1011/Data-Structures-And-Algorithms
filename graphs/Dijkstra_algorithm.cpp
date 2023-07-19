// class Solution
// {
// 	public:
// 	//Function to find the shortest distance of all the vertices
//     //from the source vertex S.
//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
//         vector<int> dist(V);
//         for(int i=0;i<V;i++){
//             dist[i]=INT_MAX;
//         }
//         set<pair<int,int>> s;
//              // dist, node
//         dist[S]=0;
//         s.insert(make_pair(0,S));
//         while(!s.empty()){
//             auto top=*(s.begin());
//             int nodeDist=top.first;
//             int topNode=top.second;
//             s.erase(s.begin());
//             //traverse on neighbour
//             for(auto neighbour: adj[topNode]){
//                 if(nodeDist+neighbour[1]<dist[neighbour[0]]){
//                     // update distance
//                     dist[neighbour[0]]=nodeDist+neighbour[1];
//                     //insert record in set
//                     s.insert(make_pair(dist[neighbour[0]],neighbour[0]));
//                 }
//             }
//         }
//         return dist;
//     }
// };