// class Solution//kruskal algo for MST
// {
// 	public:
// 	void makeset(vector<int>& parent,vector<int>& rank,int V){
// 	    for(int i=0;i<V;i++){
// 	        parent[i]=i;
// 	        rank[i]=0;
// 	    }
// 	}
// 	int findparent(vector<int>& parent,int node){
// 	    if(parent[node]==node){
// 	        return node;
// 	    }
// 	    return parent[node]=findparent(parent,parent[node]); //path compression
// 	}
// 	void unionset(int u, int v,vector<int>& parent,vector<int>& rank){
// 	    u=findparent(parent,u);
// 	    v=findparent(parent,v);
// 	    if(rank[u]<rank[v]){
// 	        parent[u]=v;
// 	    }
// 	    else if(rank[u]>rank[v]){
// 	        parent[v]=u;
// 	    }
// 	    else{//both equal
// 	        parent[v]=u;
// 	        rank[u]++;
// 	    }
// 	}
// 	//Function to find sum of weights of edges of the Minimum Spanning Tree.
//     int spanningTree(int V, vector<vector<int>> adj[])
//     {
//         vector<pair<int,pair<int,int>>>edges;
//         for(int i=0;i<V;i++){
//             for(auto it:adj[i]){
//                 int u=i;
//                 int v=it[0];
//                 int wt=it[1];
//                 edges.push_back({wt,{u,v}});
//             }
//         }
//         sort(edges.begin(),edges.end()); //bydefault sort with index 0
        
//         vector<int> parent(V);
//         vector<int> rank(V);
//         makeset(parent,rank,V);
        
//         int minweight=0;
//         for(auto i:edges){
//             int u=findparent(parent,i.second.first);
//             int v=findparent(parent,i.second.second);
//             int w=i.first;
//             if(u!=v){
//                 minweight+=w;
//                 unionset(u,v,parent,rank);
//             }
//         }
//         return minweight;
//     }
// };



