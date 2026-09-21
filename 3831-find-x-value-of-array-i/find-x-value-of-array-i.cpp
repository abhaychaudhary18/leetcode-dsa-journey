// class Solution {
// public:
//     int k;
//     vector<int> tree;
//     void build(int node, int l, int r, vector<int>& nums) {
//         if (l == r) {
//             tree[node] = nums[l] % k;
//             return;
//         }
//         int mid = (l + r) / 2;
//         build(node * 2, l, mid, nums);
//         build(node * 2 + 1, mid + 1, r, nums);
//         tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % k;
//     }
//     void update(int node, int l, int r, int idx, int val) {
//         if (l == r) {
//             tree[node] = val % k;
//             return;
//         }
//         int mid = (l + r) / 2;
//         if (idx <= mid)
//             update(node * 2, l, mid, idx, val);
//         else
//             update(node * 2 + 1, mid + 1, r, idx, val);
//         tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % k;
//     }
//     int query(int node, int l, int r, int ql, int qr) {
//         if (qr < l || r < ql)
//             return 1;
//         if (ql <= l && r <= qr)
//             return tree[node];
//         int mid = (l + r) / 2;
//         int left = query(node * 2, l, mid, ql, qr);
//         int right = query(node * 2 + 1, mid + 1, r, ql, qr);
//         return (left * right) % k;
//     }
//     vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
//         this->k = k;
//         int n = nums.size();
//         tree.resize(4 * n);
//         build(1, 0, n - 1, nums);
//         vector<int> ans;
//         for (auto& q : queries) {
//             if (q[0] == 1) {
//                 update(1, 0, n - 1, q[1], q[2]);
//             } else {
//                 ans.push_back(query(1, 0, n - 1, q[1], q[2]));
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            int x = num % k;
            vector<long long> next(k, 0);
            next[x] = 1;
            for (int r = 0; r < k; r++) {
                int nr = (r * x) % k;
                next[nr] += dp[r];
            }
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }
            dp = next;
        }
        return ans;
    }
};