class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sorting by starting index
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                // check starting is less then or equal to last ka end
                if(intervals[i][0]<=ans.back()[1]){
                    ans.back()[1]=max(intervals[i][1],ans.back()[1]);
                }
                else
                {
                    ans.push_back(intervals[i]);
                }
            }
        }
    return ans;  
    }
};