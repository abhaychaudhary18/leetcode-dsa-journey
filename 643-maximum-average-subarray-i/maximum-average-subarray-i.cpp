class Solution{
    public:
    double findMaxAverage(vector<int>&nums, int k){
        int sum =0;
        int left = 0;
        int right = k-1;
        for(int i =left; i<=right;i++){
            sum += nums[i];
        }
        int maxSum = sum;
        while(right<nums.size()-1){
            sum =sum-nums[left]+ nums[right+1];
            left ++;
            right++;
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum /k;

    }
};
