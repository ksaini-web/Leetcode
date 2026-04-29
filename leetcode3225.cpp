class Solution {
public:
    int n;
    
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        if (n == 1) return 0;

        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));

        for (int col = 0; col < n; col++) {
            for (int row = 0; row < n; row++) {
                pref[col][row + 1] = pref[col][row] + grid[row][col];
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

        for (int h0 = 0; h0 <= n; h0++) {
            for (int h1 = 0; h1 <= n; h1++) {
                dp[h0][h1] = gain(pref, 0, h0, 0, h1);
            }
        }

        for (int col = 1; col <= n - 2; col++) {
            vector<vector<long long>> ndp(n + 1, vector<long long>(n + 1, 0));

            for (int curr = 0; curr <= n; curr++) {
                vector<long long> leftMax(n + 1, 0);
                vector<long long> rightMax(n + 2, 0);

                leftMax[0] = dp[0][curr];

                for (int left = 1; left <= n; left++) {
                    leftMax[left] = max(leftMax[left - 1], dp[left][curr]);
                }

                for (int left = n; left >= 0; left--) {
                    rightMax[left] = max(
                        rightMax[left + 1],
                        dp[left][curr] + gain(pref, col, curr, left, 0)
                    );
                }

                for (int right = 0; right <= n; right++) {
                    long long op1 = leftMax[right] + gain(pref, col, curr, 0, right);
                    long long op2 = rightMax[right + 1];

                    ndp[curr][right] = max(op1, op2);
                }
            }

            dp = ndp;
        }

        long long ans = 0;

        for (int prev = 0; prev <= n; prev++) {
            for (int last = 0; last <= n; last++) {
                ans = max(ans, dp[prev][last] + gain(pref, n - 1, last, prev, 0));
            }
        }

        return ans;
    }

    long long gain(vector<vector<long long>>& pref, int col, int curr, int left, int right) {
        int mx = max(left, right);

        if (mx <= curr) return 0;

        return pref[col][mx] - pref[col][curr];
    }
};
