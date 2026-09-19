class Solution {
public:
bool dfs(int node, int destination, vector<vector<int>>& graph, vector<int>& vis){
    if(node == destination)
    return true;
    vis[node]=1;
    for(int next: graph[node]){
        if(!vis[next]){
            if(dfs(next,destination,graph,vis))
            return true;
        }
    }
    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(auto edge:edges){
            int u=edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int>vis(n,0);
        return dfs(source, destination, graph,vis);
        
    }
};