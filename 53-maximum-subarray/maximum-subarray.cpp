class Solution{
    public:
    int maxSubArray(vector<int>&nums){
        int curMax=nums[0];
        int globalMax=nums[0];
        for(int i=1;i<nums.size();i++){
            curMax = max(nums[i],curMax+nums[i]);
            globalMax = max(globalMax, curMax);
        }
        return globalMax;
    }

};