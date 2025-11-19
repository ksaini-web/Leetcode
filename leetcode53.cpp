class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int current=0,maxsum=INT_MIN;

        for(int val:nums){

            current+=val;

            maxsum=max(current,maxsum);

            if(current<0){
                current=0;


            }
        }
      return maxsum;  
    }
};