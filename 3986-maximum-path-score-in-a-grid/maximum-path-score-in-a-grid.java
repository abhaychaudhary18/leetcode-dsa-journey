class Solution {
    int[][] grid;
    int m, n, k;
    int[][][] memo;

    public int maxPathScore(int[][] grid, int k) {
        this.grid = grid;
        this.k = k;
        m = grid.length;
        n = grid[0].length;

        memo = new int[m][n][k + 1];

        for (int[][] a : memo)
            for (int[] b : a)
                Arrays.fill(b, -2);

        int ans = dfs(0, 0, 0);
        return ans < 0 ? -1 : ans;
    }

    int dfs(int i, int j, int cost) {
        if (cost > k) return -1;
        if (i == m || j == n) return -1;

        if (i == m - 1 && j == n - 1)
            return 0;

        if (memo[i][j][cost] != -2)
            return memo[i][j][cost];

        int down = -1, right = -1;

        if (i + 1 < m) {
            int v = grid[i + 1][j];
            int res = dfs(i + 1, j, cost + (v != 0 ? 1 : 0));
            if (res != -1) down = v + res;
        }

        if (j + 1 < n) {
            int v = grid[i][j + 1];
            int res = dfs(i, j + 1, cost + (v != 0 ? 1 : 0));
            if (res != -1) right = v + res;
        }

        return memo[i][j][cost] = Math.max(down, right);
    }
}