class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        int MOD = 1_000_000_007;


        for (int[] query : queries) {
            int li = query[0];
            int ri = query[1];
            int ki = query[2]; 
            int vi = query[3];
            description, multiplier

           
            for (int idx = li; idx <= ri; idx += ki) {
            
                nums[idx] = (int)(((long)nums[idx] * vi) % MOD);
            }
        }

        // Calculate the bitwise XOR of all elements in the final nums array
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        return xorSum;
    }
}
