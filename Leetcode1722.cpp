class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (rankv[pa] < rankv[pb]) {
            parent[pa] = pb;
        } else if (rankv[pa] > rankv[pb]) {
            parent[pb] = pa;
        } else {
            parent[pb] = pa;
            rankv[pa]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto &p : allowedSwaps) {
            unite(p[0], p[1]);
        }

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }

        int ans = 0;

        for (auto &it : groups) {
            unordered_map<int, int> freq;

            for (int idx : it.second) {
                freq[source[idx]]++;
            }

            for (int idx : it.second) {
                freq[target[idx]]--;
            }

            for (auto &x : freq) {
                if (x.second > 0) {
                    ans += x.second;
                }
            }
        }

        return ans;
    }
};
