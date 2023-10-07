// #include<bits/stdc++.h> 
// using namespace std; 
// // for both BSF & DSF
// // Time Complexity: O(V + E)
// // Space Complexity: O(V)

// class Solution { //DSF
// public:
// 	bool dfs(int u, int par, vector<int>adj[], vector<bool>&vis){
// 		vis[u] = true;    //marking the current vertex as visited.
// 		for(auto v: adj[u]){    //iterating on all the adjacent vertices.
// 			if(v == par) continue;
// 			//if current vertex is visited, we return true else we call the function recursively to detect the cycle.
// 			if(vis[v]) return true;
// 			if(dfs(v, u, adj, vis))
// 				return true;
// 		}
// 		return false;
// 	}
// 	bool isCycle(int V, vector<int> adj[]){
// 		vector<bool>visited(V, false);
// 		for(int i = 0; i < V; i++){
// 		    //if vertex is not visited, we call the function to detect cycle.
// 			if(!visited[i]){
// 				bool cycle = dfs(i, -1, adj, visited);
// 				if(cycle) return true;
// 			}
// 		}
// 		return false;
// 	}
// };

 
// //BSF
// bool isCyclicConntected(vector<int> adj[], int s, int V, vector<bool>& visited) {//BSF
//     // Set parent vertex for every vertex as -1.
//     vector<int> parent(V, -1);
//     queue<int> q;
//     visited[s] = true;
//     q.push(s);
//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for(auto v : adj[u]) {
//             if(!visited[v]) {
//                 visited[v] = true;
//                 q.push(v);
//                 parent[v] = u;
//             }
//             else if(parent[u] != v)
//                 return true;
//         }
//     }
//     return false;
// }
// bool isCyclicDisconntected(vector<int> adj[], int V) {
//     // Mark all the vertices as not visited
//     vector<bool> visited(V, false);
//     for(int i = 0; i < V; i++)
//         if(!visited[i] && isCyclicConntected(adj, i, V, visited))
//             return true;
//     return false;
// }
// void addEdge(vector<int> adj[], int u, int v){
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// int main() { 
// 	int V=6;
// 	vector<int> adj[V];
// 	addEdge(adj,0,1); 
// 	addEdge(adj,1,2); 
// 	addEdge(adj,2,4); 
// 	addEdge(adj,4,5); 
// 	addEdge(adj,1,3);
// 	addEdge(adj,2,3);

//     if (isCyclicDisconntected(adj, V))
//         cout << "Yes";
//     else
//         cout << "No";

// 	return 0; 
// } 