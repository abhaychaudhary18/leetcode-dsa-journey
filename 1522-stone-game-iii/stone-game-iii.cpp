class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        int dp[3] = {};
        for (int i = n - 1; i >= 0; --i) {
            int sum = 0;
            int best = INT_MIN;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                sum += a[i + k];
                best = max(best, sum - dp[(i + k + 1) % 3]);
            }
            dp[i % 3] = best;
        }
        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
    }
};