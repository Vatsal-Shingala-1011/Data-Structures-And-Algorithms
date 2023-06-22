class Solution { //self
public: 
    int left(vector<int>& nums, int target) {
        int n=nums.size();
        int left=-1;
        int s=0,e=n-1,mid=s+((e-s)/2);
        while(s<=e){
            if(target==nums[mid]){
                left= mid;
                e=mid-1;
                }
            else if(target>nums[mid]){s=mid+1;}
            else
            {e=mid-1;}
            mid=s+((e-s)/2);

        }
        return left;
    }
    int right(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1,mid=s+((e-s)/2);
        int right=-1;
        while(s<=e){
            if(target==nums[mid]){
                right= mid;
                s=mid+1;
                }
            else if(target>nums[mid]){s=mid+1;}
            else
            {e=mid-1;}
            mid=s+((e-s)/2);
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {left(nums,target),right(nums,target)};
        
    }
};
