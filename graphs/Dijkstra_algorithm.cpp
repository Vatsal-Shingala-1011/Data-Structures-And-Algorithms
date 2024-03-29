// class Solution
// {
// 	public:
// 	//Function to find the shortest distance of all the vertices from the source vertex S.
//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
//         vector<int> dist(V,INT_MAX);
//         set<pair<int,int>> s; //set return element in sorted order
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
//                          //    wt         
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