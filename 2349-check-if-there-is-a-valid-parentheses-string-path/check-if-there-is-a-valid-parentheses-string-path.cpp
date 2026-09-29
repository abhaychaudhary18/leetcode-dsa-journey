class Solution {
public:
bool dfs(vector<vector<char>>& grid, int i, int j, int balance, vector<vector<vector<int>>>& dp){
    int m = grid.size();
    int n = grid[0].size();
    if(i >= m || j>= n)
    return false;
    if(grid[i][j] == '(')
    balance++;
    else 
    balance--;
    if(balance<0)
    return false;
    if(i==m-1 && j==n-1)
    return balance ==0;
    if(dp[i][j][balance] != -1)
    return dp[i][j][balance];
    return dp[i][j][balance]=dfs(grid, i+1,j,balance,dp)||
    dfs(grid, i, j+1, balance,dp);
}
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        if((m+n-1)%2)
        return false;
        vector<vector<vector<int>>> dp(
            m,vector<vector<int>>(n,vector<int>(m+n,-1)));
            return dfs(grid,0,0,0,dp);

        
    }
};