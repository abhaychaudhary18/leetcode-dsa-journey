//Time Complexity:  O(n)
//Space Complexity: O(1)

class Solution{
    public:
    int pivotIndex(vector<int>&nums){
        int rightSum=0;
        for(int num:nums){
            rightSum+=num;
        }
        int leftSum=0;
        for(int i=0;i<nums.size();i++){
            rightSum -=nums[i];
            if(leftSum==rightSum){
                return i;
            }
            leftSum +=nums[i];
        }
        return -1;

    }
};
 
// class Solution{
//     public:
//     int pivotIndex(vector<int>& nums){
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int leftSum =0;
//             int rightSum =0;
//             for(int j=0;j<i;j++){
//                 leftSum += nums[j];
//             }
//             for(int j=i+1;j<n;j++){
//                 rightSum += nums[j];
//             }
//             if (leftSum==rightSum){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

//time complexity: O(n^2)
//space complexity: O(1)


