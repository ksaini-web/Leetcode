class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans = grid;

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {
            int top = layer, left = layer;
            int bottom = m - 1 - layer, right = n - 1 - layer;

            vector<int> vals;

            for (int c = left; c <= right; c++)
                vals.push_back(grid[top][c]);

            for (int r = top + 1; r < bottom; r++)
                vals.push_back(grid[r][right]);

            for (int c = right; c >= left; c--)
                vals.push_back(grid[bottom][c]);

            for (int r = bottom - 1; r > top; r--)
                vals.push_back(grid[r][left]);

            int len = vals.size();
            int shift = k % len;

            vector<int> rotated(len);
            for (int i = 0; i < len; i++) {
                rotated[i] = vals[(i + shift) % len];
            }

            int idx = 0;

            for (int c = left; c <= right; c++)
                ans[top][c] = rotated[idx++];

            for (int r = top + 1; r < bottom; r++)
                ans[r][right] = rotated[idx++];

            for (int c = right; c >= left; c--)
                ans[bottom][c] = rotated[idx++];

            for (int r = bottom - 1; r > top; r--)
                ans[r][left] = rotated[idx++];
        }

        return ans;
    }
};
