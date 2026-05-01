class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            total += nums[i];
            curr += 1LL * i * nums[i];
        }

        long long ans = curr;

        for (int k = 1; k < n; k++) {
            curr = curr + total - 1LL * n * nums[n - k];
            ans = max(ans, curr);
        }

        return (int)ans;
    }
};
