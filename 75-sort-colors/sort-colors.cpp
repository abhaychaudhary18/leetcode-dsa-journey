// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

        
//     }
// };


class Solution{
    public:
    void sortColors(vector<int>&nums){
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0)swap(nums[mid++],nums[low++]);
            else if(nums[mid]==1)mid++;
            else swap(nums[mid],nums[high--]);
        }

    }
};

// class Solution{
//     public:
//     void sortColors(vector<int>&nums){
//         int n = nums.size();
//         int count0s=0;
//         int count1s=0;
//         int count2s=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]==0){
//                 count0s += 1;

//             }else if(nums[i]==1){
//                 count1s+=1;

//             }else{
//                 count2s +=1;
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(count0s>0){
//                 nums[i]=0;
//                 count0s--;
//             }else if(count1s>0){
//                 nums[i]=1;
//                 count1s--;
//             }else if(count2s>0){
//                 nums[i]=2;
//                 count2s--;
//             }
//         }

//   }
// };