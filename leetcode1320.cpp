class Solution {
public:
    int getDist(int a, int b) {
        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n, vector<int>(26, INF));

        for (int j = 0; j < 26; j++) {
            dp[0][j] = 0;
        }

        for (int i = 0; i < n - 1; i++) {
            int cur = word[i] - 'A';
            int nxt = word[i + 1] - 'A';

            for (int j = 0; j < 26; j++) {
                if (dp[i][j] == INF) continue;

                
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + getDist(cur, nxt));

              
                dp[i + 1][cur] = min(dp[i + 1][cur], dp[i][j] + getDist(j, nxt));
            }
        }

        int ans = INF;
        for (int j = 0; j < 26; j++) {
            ans = min(ans, dp[n - 1][j]);
        }

        return ans;
    }
};
