class Solution {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Collections.sort(robot);
        Arrays.sort(factory, (a, b) -> a[0] - b[0]);

        int n = robot.size();
        int m = factory.length;

        Long[][] dp = new Long[n + 1][m + 1];

        return solve(0, 0, robot, factory, dp);
    }

    private long solve(int i, int j, List<Integer> robot, int[][] factory, Long[][] dp) {
        // All robots fixed
        if (i == robot.size()) return 0;

        // No factories left
        if (j == factory.length) return (long)1e15;

        if (dp[i][j] != null) return dp[i][j];

        long res = solve(i, j + 1, robot, factory, dp); // skip factory

        long cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        // Try assigning k robots
        for (int k = 1; k <= limit && i + k - 1 < robot.size(); k++) {
            cost += Math.abs(robot.get(i + k - 1) - pos);
            res = Math.min(res, cost + solve(i + k, j + 1, robot, factory, dp));
        }

        return dp[i][j] = res;
    }
}