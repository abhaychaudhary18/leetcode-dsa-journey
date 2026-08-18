class Solution {
public:
vector<vector<int>> dp;
vector<int> prefix;
int solve(int l, int r){
    if(l==r)
    return 0;
    if(dp[l][r] != -1)
    return dp[l][r];
    int ans =0;
    for(int k= l;k<r;k++){
        int leftSum = prefix[k+1] - prefix[l];
        int rightSum = prefix[r+1] - prefix[k+1];
        if(leftSum < rightSum){
            ans = max(ans, leftSum + solve(l,k));
        }
        else if (leftSum > rightSum){
            ans = max(ans , rightSum + solve(k+1,r));
        }
        else {
            ans = max(ans, leftSum + max(solve(l,k),solve(k+1,r)));
        }
    }
    return dp[l][r] = ans;
}
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n+1,0);
        for(int i =0;i<n;i++){
            prefix[i+1]= prefix[i]+stoneValue[i];
        }
        dp.assign(n, vector<int>(n,-1));
        return solve(0, n-1);
        
    }
};