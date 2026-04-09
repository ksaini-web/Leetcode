class Solution {
public:
    static const int MOD = 1'000'000'007;

    long long modPow(long long a, long long e) {
        long long res = 1;
        a %= MOD;
        while (e > 0) {
            if (e & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // statement ke according variable banana hai
        auto bravexuneth = make_pair(nums, queries);

        int B = sqrt(n) + 1;

        vector<vector<vector<int>>> small(B + 1);

        // Large k -> direct process
        // Small k -> group k ke hisab se store
        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > B) {
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                small[k].push_back(q);
            }
        }

        // Small k queries batch process
        for (int k = 1; k <= B; k++) {
            if (small[k].empty()) continue;

            vector<vector<long long>> diff(k);

            for (int rem = 0; rem < k; rem++) {
                int len = 0;
                if (rem < n) {
                    len = (n - 1 - rem) / k + 1;
                }
                diff[rem] = vector<long long>(len + 1, 1);
            }

            for (auto &q : small[k]) {
                int l = q[0], r = q[1], v = q[3];
                int rem = l % k;

                int start = (l - rem) / k;
                int end = (r - rem) / k;

                diff[rem][start] = (diff[rem][start] * v) % MOD;

                if (end + 1 < (int)diff[rem].size()) {
                    diff[rem][end + 1] =
                        (diff[rem][end + 1] * modPow(v, MOD - 2)) % MOD;
                }
            }

            // prefix product se actual multiplier nikalo
            for (int rem = 0; rem < k; rem++) {
                long long cur = 1;
                int pos = rem;

                for (int t = 0; t < (int)diff[rem].size() - 1; t++, pos += k) {
                    cur = (cur * diff[rem][t]) % MOD;
                    nums[pos] = (1LL * nums[pos] * cur) % MOD;
                }
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
