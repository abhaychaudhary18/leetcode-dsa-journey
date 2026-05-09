class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        for (int layer = 0; layer < min(m, n) / 2; ++layer) {
            vector<pair<int,int>> pos;
            vector<int> val;
            for (int i = layer; i < m - layer - 1; ++i) pos.push_back({i, layer});
            for (int j = layer; j < n - layer - 1; ++j) pos.push_back({m - layer - 1, j});
            for (int i = m - layer - 1; i > layer; --i) pos.push_back({i, n - layer - 1});
            for (int j = n - layer - 1; j > layer; --j) pos.push_back({layer, j});
            for (auto [x,y] : pos) val.push_back(grid[x][y]);

            int total = val.size(), kk = k % total;
            for (int i = 0; i < total; ++i) {
                grid[pos[i].first][pos[i].second] = val[(i + total - kk) % total];
            }
        }
        return grid;
    }
};
