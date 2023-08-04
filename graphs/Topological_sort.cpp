// // class Solution  /////////using DFS
// // {
// // 	public:
// // 	void topological(int node,unordered_map<int,bool>& visited,stack<int>& s,vector<int>*& adj){
// // 	    visited[node]=true;
// // 	    for(auto neighbour: adj[node]){
// // 	        if(!visited[neighbour]){
// // 	            topological(neighbour,visited,s,adj);
// // 	        }
// // 	    }
// // 	    s.push(node);
// // 	}
// // 	//Function to return list containing vertices in Topological order. 
// // 	vector<int> topoSort(int V, vector<int> adj[]) 
// // 	{
// // 	    unordered_map<int,bool> visited;
// // 	    stack<int>s;
// // 	    //call dsf for all components
// // 	    for(int i=0;i<V;i++){
// // 	        if(!visited[i]){
// // 	            topological(i,visited,s,adj);
// // 	        }
// // 	    }
// // 	    vector<int>ans;
// // 	    while(!s.empty()){
// // 	        ans.push_back(s.top());
// // 	        s.pop();
// // 	    }
// // 	    return ans;
// // 	}
// // };

// class Solution//kahn's algorithm //also use for cycle detection in directed graph
// {
// 	public:
// 	//Function to return list containing vertices in Topological order. 
// 	vector<int> topoSort(int V, vector<int> adj[]) 
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
// 	vector<int> ans;
// 	while(!q.empty()){
// 	    int front=q.front();
// 	    q.pop();
// 	    //ans store
// 	    ans.push_back(front);
// 	    //neighbour indegree --
// 	    for(auto neighbour: adj[front]){
// 	        indegree[neighbour]--;
// 	        if(indegree[neighbour]==0) q.push(neighbour);
// 	    }
// 	}
// 	return ans;
// 	}
// };




