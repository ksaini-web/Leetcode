class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int curmax=0,maxSUM=INT_MIN;
        int curmin=0,minSUM=INT_MAX,total=0;
        

        for(int val:nums){

            total+=val;

            curmax+=val;
            maxSUM=max(maxSUM,curmax);
            if(curmax<0){
                curmax=0;
            }
            curmin+=val;
            minSUM=min(minSUM,curmin);
            if(curmin>0){
                curmin=0;
            }


        }//
        // IMPORTANT edge case: all numbers negative;
         if (maxSUM < 0) return maxSUM;
        return max(maxSUM,total-minSUM);
        
    }
};