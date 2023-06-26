// #include <bits/stdc++.h> 
// //codint ninja
// //do tabu and space opti in tabu in 2 array and in one array

// int solveRec(vector<int> weight, vector<int>& value, int index, int w) //w capacity of weights
// {
// 	if(index==0){
// 		if(weight[0]<=w){
// 			return value[0];
// 		}
// 		else
// 		{return 0;}
// 	}
// 	int inc=0;
// 	if(weight[index]<=w)
// 	{
// 		inc=value[index]+solveRec(weight,value,index-1,w-weight[index]); 
// 	}
// 	int exc= solveRec(weight,value,index-1,w); 
// 	int ans=max(inc,exc);
// 	return ans;
// }

// int solvememo(vector<int> weight, vector<int>& value, int index, int w, vector<vector<int>>& memo) //w capacity of weights
// {
// 	if(index==0){
// 		if(weight[0]<=w){
// 			return value[0];
// 		}
// 		else
// 		{return 0;}
// 	}
// 	if(memo[index][w]!=-1){
// 		return memo[index][w];
// 	}
// 	int inc=0;
// 	if(weight[index]<=w)
// 	{
// 		inc=value[index]+solvememo(weight,value,index-1,w-weight[index],memo); 
// 	}
// 	int exc= solvememo(weight,value,index-1,w,memo); 
// 	memo[index][w]=max(inc,exc);
// 	return memo[index][w];
// }


// int solvetab(vector<int> weight, vector<int>& value, int index, int maxWeight) //w capacity of weights
// {
// 	vector<vector<int>> memo(n,vector<int>(maxWeight+1,0));
// 	int n=weight.size();
// 	//base case
// 	for(int i=weight[0];i<maxWeight;i++){
// 		if(weight[0]<=maxWeight){
// 			memo[0][i]=value[0];
// 		}
// 		else{
// 			memo[0][i]=0;
// 		}
// 	}
	
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// vector<vector<int>> memo(n,vector<int>(maxWeight+1,-1));
// 	return solvetab(weight, value,n-1,maxWeight);
// }