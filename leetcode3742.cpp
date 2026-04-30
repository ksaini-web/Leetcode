class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        dp[0][0] = 0;

        for (int i = 0; i < m; i++) {
            vector<vector<int>> newDp(n, vector<int>(k + 1, -1));

            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                int cost = (val == 0) ? 0 : 1;

                for (int c = cost; c <= k; c++) {
                    if (i == 0 && j == 0) {
                        newDp[0][0] = 0;
                        continue;
                    }

                    int best = -1;

                    // from top
                    if (i > 0 && dp[j][c - cost] != -1) {
                        best = max(best, dp[j][c - cost] + val);
                    }

                    // from left
                    if (j > 0 && newDp[j - 1][c - cost] != -1) {
                        best = max(best, newDp[j - 1][c - cost] + val);
                    }

                    newDp[j][c] = max(newDp[j][c], best);
                }
            }

            dp = newDp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n - 1][c]);
        }

        return ans;
    }
};
