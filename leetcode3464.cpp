class Solution {
public:
    long long getPos(vector<int>& p, int side) {
        long long x = p[0], y = p[1];

        if (y == 0) return x;
        if (x == side) return side + y;
        if (y == side) return 2LL * side + (side - x);
        return 3LL * side + (side - y);
    }

    bool can(vector<long long>& arr, long long per, int k, long long d) {
        int n = arr.size();

        vector<long long> b = arr;
        for (int i = 0; i < n; i++) {
            b.push_back(arr[i] + per);
        }

        int m = b.size();
        vector<int> nxt(m, m);

        for (int i = 0; i < m; i++) {
            nxt[i] = lower_bound(b.begin(), b.end(), b[i] + d) - b.begin();
        }

        for (int start = 0; start < n; start++) {
            int idx = start;
            bool ok = true;

            for (int cnt = 1; cnt < k; cnt++) {
                idx = nxt[idx];

                if (idx >= start + n) {
                    ok = false;
                    break;
                }
            }

            if (ok && b[idx] - b[start] <= per - d) {
                return true;
            }
        }

        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        for (auto& p : points) {
            arr.push_back(getPos(p, side));
        }

        sort(arr.begin(), arr.end());

        long long per = 4LL * side;
        long long low = 1, high = side;
        long long ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (can(arr, per, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
