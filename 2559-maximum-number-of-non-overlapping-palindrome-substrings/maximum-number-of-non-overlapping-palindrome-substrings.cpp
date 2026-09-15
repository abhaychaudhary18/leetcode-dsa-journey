class Solution{
    public:
    int maxPalindromes(string s, int k){
        int n= s.size();
        vector<vector<bool>>pal(n,vector<bool>(n,false));
        for(int len = 1;len<=n;len++){
            for(int i =0;i+len-1<n;i++){
                int j =i+len -1;
                if(s[i]==s[j]){
                    if(len<=2)
                    pal[i][j]=true;
                    else
                    pal[i][j]=pal[i+1][j-1];
                }
            }
        }
        vector<int>dp(n+1,0);
        for(int i =0;i<n;i++){
            dp[i+1]=dp[i];
            for(int j=0;j<=i;j++){
                if(i-j+1>=k&&pal[j][i]){
                    dp[i+1]=max(dp[i+1],dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};