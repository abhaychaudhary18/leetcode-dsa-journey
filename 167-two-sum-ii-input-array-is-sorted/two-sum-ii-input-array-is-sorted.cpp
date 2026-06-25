// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i=0; i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     return{i+1,j+1};
//                 }
//             }
//         }
//         return{};
        
//     }
// };


class Solution{
    public:
    vector<int>twoSum(vector<int>& nums, int target){
        map<int,int> mp;
        for(int i=0;i<nums.size(); i++){
            int temp = target-nums[i];
            if(mp.find(temp)!= mp.end()){
                return {mp[temp]+1,i+1};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};

// class Solution{
//     public:
//     vector<int>twoSum(vector<int>&nums, int target){
//         int left=0;
//         int right = nums.size()-1;
//         while(left<right){
//             int sum = nums[left]+nums[right];
//             if(sum==target)
//             return{left+1,right+1};
//             else if(sum<right)
//             left++;
//             else
//             right--;
//         }
//         return{};
//     }
// }; 