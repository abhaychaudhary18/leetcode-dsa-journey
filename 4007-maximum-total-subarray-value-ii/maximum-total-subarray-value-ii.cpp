class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 32 - __builtin_clz(n);

        vector<vector<int>> mx(n, vector<int>(LOG));
        vector<vector<int>> mn(n, vector<int>(LOG));

        for (int i = 0; i < n; i++) {
            mx[i][0] = nums[i];
            mn[i][0] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mx[i][j] = max(mx[i][j - 1],
                               mx[i + (1 << (j - 1))][j - 1]);

                mn[i][j] = min(mn[i][j - 1],
                               mn[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto getMax = [&](int l, int r) {
            int p = 31 - __builtin_clz(r - l + 1);
            return max(mx[l][p], mx[r - (1 << p) + 1][p]);
        };

        auto getMin = [&](int l, int r) {
            int p = 31 - __builtin_clz(r - l + 1);
            return min(mn[l][p], mn[r - (1 << p) + 1][p]);
        };

        priority_queue<tuple<int,int,int>> pq;

        for (int l = 0; l < n; l++) {
            pq.push({getMax(l, n - 1) - getMin(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({
                    getMax(l, r - 1) - getMin(l, r - 1),
                    l,
                    r - 1
                });
            }
        }

        return ans;
    }
};