class Solution {
public:

int reverseNum(int num){

    int rev = 0;

   while(num>0){
      
      
      rev=rev*10+num%10;
      num/=10;
    
   }

   return rev;
}
    int minMirrorPairDistance(vector<int>& nums) {
       
        unordered_map<int,int> lastIndex ;

        int ans = INT_MAX;

        for(int j =0 ; j<nums.size();j++){

           

            if(lastIndex.find(nums[j]) != lastIndex.end()){

                ans = min(ans,j-lastIndex[nums[j]]);
            }
              // save in map 
                int rev = reverseNum(nums[j]);
            lastIndex[rev] =j;
        }

        return (ans==INT_MAX)?-1:ans;
        
    }
};
