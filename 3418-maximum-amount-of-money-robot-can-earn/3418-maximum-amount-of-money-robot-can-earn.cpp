class Solution {
public:
    int maximumAmount(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int K = 2; // max skips allowed (problem me given hota hai)

        vector dp(n, vector(m, vector<int>(K+1, INT_MIN)));

        // base case
        dp[0][0][0] = grid[0][0];
        if (grid[0][0] < 0) {
            dp[0][0][1] = 0; // skip
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k <= K; k++) {

                    if (i == 0 && j == 0) continue;

                    int val = grid[i][j];

                    // from top
                    if (i > 0) {
                        // normal
                        if (dp[i-1][j][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);

                        // skip
                        if (val < 0 && k > 0 && dp[i-1][j][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                    }

                    // from left
                    if (j > 0) {
                        // normal
                        if (dp[i][j-1][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);

                        // skip
                        if (val < 0 && k > 0 && dp[i][j-1][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }

        int ans = INT_MIN;
        for (int k = 0; k <= K; k++) {
            ans = max(ans, dp[n-1][m-1][k]);
        }

        return ans;
    }
};