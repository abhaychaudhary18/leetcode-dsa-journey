class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int> curr, vector<vector<int>>& ans) {
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        vector<int> take = curr;
        take.push_back(nums[i]);
        solve(i + 1, nums, take, ans);
        solve(i + 1, nums, curr, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, nums, curr, ans);
        return ans;
    }
};