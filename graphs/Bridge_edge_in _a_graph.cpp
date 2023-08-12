//// find c and d is bridge or not//gfg
// class Solution
// {
// 	public:
// 	void dfs(int node,int parent,int &timer,vector<int>& disc,vector<int>& low, vector<int>*& adj,unordered_map<int,bool>& visited,bool& flag,int c,int d){
// 	    visited[node]=true;
// 	    disc[node]=low[node]=timer++;
// 	    for (auto nbr: adj[node]){
// 	        if(nbr==parent) continue;
// 	        if(!visited[nbr]){
// 	            dfs(nbr,node,timer,disc,low,adj,visited,flag,c,d);
// 	            low[node]=min(low[node],low[nbr]);
// 	            //check edge is bridge
// 	            if(low[nbr]>disc[node]){
// 	                vector<int> ans;
// 	                ans.push_back(node);
// 	                if((node==c&&nbr==d)||(node==d&&nbr==c)){
// 	                    flag=true;
// 	                }
// 	            }
// 	        }
// 	        else{
// 	            //Back edge
// 	            low[node]=min(low[node],disc[nbr]); //in case of multiple back edge take min of them
// 	        }
// 	    }
// 	}
//     //Function to find if the given edge is a bridge in graph.
//     int isBridge(int V, vector<int> adj[], int c, int d) 
//     {
//         int timer =0;
//         vector<int> disc(V,-1); //discovery time
//         vector<int> low(V,-1);
//         int parent=-1;
//         unordered_map<int,bool> visited;
//         bool forthisque=false;//for GFGs quesion i make this variable
//         //dsf
//         for(int i=0;i<V;i++){
//             if(!visited[i]){
//                 dfs(i,parent,timer,disc,low,adj,visited,forthisque,c,d);
//             }
//         }
//         if (forthisque==true) return 1;
//         return 0;
        
//     }
// };