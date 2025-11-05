class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If start or end is blocked → no path
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        // Base case: bottom-right cell
        dp[m - 1][n - 1] = 1;

        // Fill bottom-up
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // obstacle
                    continue;
                }

                if (i + 1 < m) dp[i][j] += dp[i + 1][j]; // from below
                if (j + 1 < n) dp[i][j] += dp[i][j + 1]; // from right
            }
        }

        return dp[0][0];
    }
};
