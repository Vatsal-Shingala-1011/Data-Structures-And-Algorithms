// //optimization using queue
// //dp
// //leet code 
// class Solution {
//     int solvememo(vector<int>& days ,vector<int>& costs,int size,int index,vector<int>& memo){//100% self
//             if(index>=size) //do one other recursion will do
//                 return 0;           
//             if(memo[index]!=-1)
//                 return memo[index];
//             //1 day
//             int day1=costs[0] + solvememo(days,costs,size,index+1,memo);
//             //7 days
//             int i;
//             for(i=index;i<size && days[i]<days[index]+7;i++);
//             int day7=costs[1] + solvememo(days,costs,size,i,memo);
//             //30days
//             for(i=index;i<size && days[i]<days[index]+30;i++);
//             int day30=costs[2] + solvememo(days,costs,size,i,memo);

//             memo[index]=min(day1,min(day7,day30));
//             return memo[index];
//     }
// int solvetab(vector<int>& days ,vector<int>& costs,int size){ //self can  
//     vector<int> memo(size+1,INT_MAX);
//     memo[size]=0;
//     for(int k=size-1;k>=0;k--)
//     {
//         if(k+1<=size)
//             memo[k]=min(memo[k+1]+costs[0],memo[k]);
//         int i;
//         for(i=k;i<size && days[i]<days[k]+7;i++);
//         memo[k]=min(memo[k],costs[1]+memo[i]);
//         for(i=k;i<size && days[i]<days[k]+30;i++);
//         memo[k]=min(memo[k],costs[2] + memo[i]);     
//     }
//     return memo[0];
//     }
// int solvequeue(vector<int>& days, vector<int>& costs){ //tabulation space optimization
//     queue<pair<int,int>> month;
//     queue<pair<int,int>> week;
//     //       days , min cost till that position
//     int ans=0;
//     for(int day:days){
//     while(!month.empty() && month.front().first+30 <=day){
//         month.pop();
//     }
//     while(!week.empty() && week.front().first+7 <=day){
//         week.pop();
//     }
//     month.push({day,ans+costs[2]});
//     week.push({day,ans+costs[1]});

//     ans=min(ans+costs[0],min(month.front().second,week.front().second));
//     }
// return ans;
// }
// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int size=days.size();
//         // vector<int> memo(size,-1);
//         // return solvememo(days,costs,size,0,memo); 
//         // return solvetab(days,costs,size);  
//         return solvequeue(days,costs);
//     }
// };
