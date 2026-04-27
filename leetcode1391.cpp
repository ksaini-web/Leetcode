class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dirs = {
            {},
            {0, 1, 0, -1},   // 1: right, left
            {-1, 0, 1, 0},   // 2: up, down
            {0, -1, 1, 0},   // 3: left, down
            {0, 1, 1, 0},    // 4: right, down
            {0, -1, -1, 0},  // 5: left, up
            {0, 1, -1, 0}    // 6: right, up
        };

        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            int type = grid[r][c];

            for (int i = 0; i < 4; i += 2) {
                int nr = r + dirs[type][i];
                int nc = c + dirs[type][i + 1];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n || vis[nr][nc]) {
                    continue;
                }

                int nextType = grid[nr][nc];

                for (int j = 0; j < 4; j += 2) {
                    int backR = nr + dirs[nextType][j];
                    int backC = nc + dirs[nextType][j + 1];

                    if (backR == r && backC == c) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                        break;
                    }
                }
            }
        }

        return false;
    }
};
