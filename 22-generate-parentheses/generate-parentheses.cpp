class Solution {
public:
void solve(int open, int close, int n, string cur,vector<string>&ans){
    if(open == n && close ==n){
        ans.push_back(cur);
        return;
    }
    if(open <n){
        solve(open+1, close, n, cur+'(',ans);
    }
    if(close<open){
        solve(open, close+1,n,cur+')',ans);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;

        
    }
};