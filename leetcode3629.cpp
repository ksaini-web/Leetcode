class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> spf(mx + 1);
        for (int i = 0; i <= mx; i++) spf[i] = i;

        for (long long i = 2; i <= mx; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= mx; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        auto isPrime = [&](int x) {
            return x >= 2 && spf[x] == x;
        };

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                mp[p].push_back(i);
                while (x % p == 0) x /= p;
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        unordered_set<int> usedPrime;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            int val = nums[i];

            if (isPrime(val) && !usedPrime.count(val)) {
                usedPrime.insert(val);

                for (int j : mp[val]) {
                    if (j != i && dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }
            }
        }

        return dist[n - 1];
    }
};
