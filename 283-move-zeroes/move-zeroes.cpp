class Solution{
    public:
    void moveZeroes(vector<int>&arr){
        int left = 0;
        for(int right=0; right<arr.size(); right++){
            if(arr[right]!=0){
                swap(arr[left],arr[right]);
                left++;
            }
        }
    }
};