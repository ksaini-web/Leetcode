class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // store all indices of each value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& pos = mp[nums[q]];

            // if only one occurrence
            if (pos.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int idx = lower_bound(pos.begin(), pos.end(), q) - pos.begin();

            int res = INT_MAX;

          
            int leftIndex;
            if (idx == 0) leftIndex = pos.back();
            else leftIndex = pos[idx - 1];

            int d1 = abs(q - leftIndex);
            res = min(res, min(d1, n - d1));

          
            int rightIndex;
            if (idx == pos.size() - 1) rightIndex = pos[0];
            else rightIndex = pos[idx + 1];

            int d2 = abs(q - rightIndex);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};
