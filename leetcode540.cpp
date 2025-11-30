class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n=nums.size();

        vector<int>freq(n,0);

        for(int x:nums){

            freq[x]++;
            
           
        }
        
        for(int x:nums){

            if(freq[x]==1){

                return x;
            }
        }

        return -1;
        
    }
};
