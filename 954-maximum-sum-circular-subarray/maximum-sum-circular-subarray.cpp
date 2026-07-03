class Solution{
    public:
    int maxSubarraySumCircular(vector<int>& nums){
        int total=0;
        int maxSum =nums[0];
        int minSum =nums[0];
        int curMax=0;
        int curMin =0;
        for(int x:nums){
            total +=x;
            curMax=max(x,curMax+x); //kadane's algo for max subarray
            maxSum = max(maxSum, curMax);
            curMin = min(x,curMin+x); // kadane's for min subArray
            minSum = min(minSum, curMin);
        }
        if(maxSum<0) // if all  elemnts are negative then return maxSum
        return maxSum;
        return max(maxSum, total-minSum);// for circular sum
    }
};