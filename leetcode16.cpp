class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
      
      sort(nums.begin(),nums.end());

      int best=nums[0]+nums[1]+nums[2];



      for(int i=0;i<n-2;i++){

        int left =i+1,right=n-1;

      while(left<right){

        long long sum=(long long)nums[right]+nums[left]+nums[i];


        if(abs(sum-target)<abs((long long)(best-target))){
            best=(int)sum;
           
        }
        if(target==sum){
            return target;
        }
        if(sum<target){
            ++left;
        }
        else {
            --right;
        }
      }
      }
      return best;
    }
};