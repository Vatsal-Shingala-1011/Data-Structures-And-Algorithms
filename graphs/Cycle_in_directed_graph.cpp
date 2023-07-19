// // class Solution { //DSF //why TLE
// //   public:
// //     bool checkCycleDSF(int node,unordered_map<int,bool> & visited,unordered_map<int,bool>& DSFvisited,vector<int>*& adj){
// //         visited[node]=true;
// //         DSFvisited[node]=true;
// //         for(auto neighbour: adj[node]){
// //             if(!visited[neighbour]){
// //                 bool CycleDetected=checkCycleDSF(neighbour,visited,DSFvisited,adj);
// //                 if(CycleDetected) return true;
// //             }
// //             else{
// //                 if(DSFvisited[neighbour]) return true;
// //             }
// //         }
// //         DSFvisited[node]=false;
// //         return false;
// //     }
// //     // Function to detect cycle in a directed graph.
// //     bool isCyclic(int V, vector<int> adj[]) {
// //         //loop if there is disconnected commponent
// //         unordered_map<int,bool> visited;
// //         unordered_map<int,bool> DSFvisited;
// //         for(int i=0;i<V;i++){
// //             if(!visited[i]){
// //                 bool cycleFound=checkCycleDSF(i,visited,DSFvisited,adj);
// //                 if(cycleFound) return true;
// //             }
// //         }
// //         return false;
// //     }
// // };

// class Solution//BSF //kahn's algorithm
// {
// 	public:
// 	//Function to return list containing vertices in Topological order. 
// 	bool isCyclic(int V, vector<int> adj[])
// 	{
//         //find all indegress
//         vector<int> indegree(V,0);
//         for(int i=0;i<V;i++){
//             for(auto j: adj[i]){
//                 indegree[j]++;
//             }
//         }
// 	//push 0 indegree
// 	queue<int> q;
	
// 	for(int k=0;k<V;k++){
// 	    if(indegree[k]==0) q.push(k);
// 	}
// 	// do bsf
// 	int cnt=0;;
// 	while(!q.empty()){
// 	    int front=q.front();
// 	    q.pop();
// 	    //cnt++
// 	    cnt++;
// 	    //neighbour indegree --
// 	    for(auto neighbour: adj[front]){
// 	        indegree[neighbour]--;
// 	        if(indegree[neighbour]==0) q.push(neighbour);
// 	    }
// 	}
// 	return cnt!=V;
// 	}
// };
