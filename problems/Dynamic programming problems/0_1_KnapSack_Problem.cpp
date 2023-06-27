// #include <bits/stdc++.h> 
// ninja

// int solveRec(vector<int> weight, vector<int>& value, int index, int w) //w capacity of weights
// {
// 	if(index==0){//call by include or exclude doesn't matter if we take 0th element if possible then it's give max value
// 		if(weight[0]<=w){
// 			return value[0];
// 		}
// 		else
// 		{return 0;}
// 	}         //done
// 	int inc=0; //think only one case other recursion will do
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
// 	if(index==0){ //call by include or exclude doesn't matter if we take oth element if possible then it's give max value
// 		if(weight[0]<=w){
// 			return value[0];
// 		}
// 		else
// 		{return 0;}
// 	}
// 	if(memo[index][w]!=-1){
// 		return memo[index][w];
// 	}
// 	int inc=0;//for same weight
// 	if(weight[index]<=w)
// 	{
// 		inc=value[index]+solvememo(weight,value,index-1,w-weight[index],memo); 
// 	}
// 	int exc= solvememo(weight,value,index-1,w,memo); 
// 	memo[index][w]=max(inc,exc);
// 	return memo[index][w];
// }


// int solvetab(vector<int> weight, vector<int>& value, int maxWeight) //w capacity of weights
// {
// 	int n=weight.size();
// 	vector<vector<int>> memo(n,vector<int>(maxWeight+1,0));
// 	//base case
// 	for(int i=weight[0];i<=maxWeight;i++){
// 		if(weight[0]<=maxWeight){
// 			memo[0][i]=value[0];
// 		}
// 		else{
// 			memo[0][i]=0;
// 		}
// 	}
// 	//for other
// 	for(int i=1;i<n;i++){
// 		for(int j=1;j<=maxWeight;j++)
// 		{
// 			int inc=0;
// 			if(weight[i]<=j){
// 				inc=memo[i-1][j-weight[i]]+value[i];
// 			}
// 			int exc=memo[i-1][j];
// 			memo[i][j]=max(inc,exc);
// 		}
// 	}
// 	return memo[n-1][maxWeight];
	
// }
// int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
// {
// 	// vector<vector<int>> memo(n,vector<int>(maxWeight+1,-1));
// 	return solvetab(weight, value,maxWeight);
// }