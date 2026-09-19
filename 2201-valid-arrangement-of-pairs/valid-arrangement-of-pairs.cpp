class Solution {
public:
vector<vector<int>>ans;
int n;
void dfs(int u, unordered_map<int,vector<int>>&mp){
    while(mp[u].size()){
        int v =mp[u].back();
        mp[u].pop_back();
        dfs(v,mp);
        ans.push_back({u,v});
    }
}
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        n=pairs.size();
        unordered_map<int, vector<int>>mp;
        unordered_map<int, int>ind;
        unordered_map<int,int>out;
        for(auto pair:pairs){
            mp[pair[0]].push_back(pair[1]);
            ind[pair[1]]++;
            out[pair[0]]++;
        }
        for(auto ele:mp){
            int val = ele.first;
            if(out[val]-ind[val]==1){
                dfs(val,mp);
                break;
            }
        }
        if(ans.size()==0) dfs(pairs[0][0],mp);
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};