class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
       int count =0;
        int i=0;
        int j=nums.size();

        vector<int>maxleft(j);
        vector<int>minright(j);
      

         maxleft[0]=nums[0];
       for(int i=1;i<j;i++)
            
            {
            maxleft[i]=max(maxleft[i-1],nums[i]);

            }
            minright[j-1]=nums[j-1];

       for(int i=j-2;i>=0;i--){
        minright[i]=min(minright[i+1],nums[i]);

       }

       for(int i=0;i<j-1;i++){

        if(maxleft[i]<=minright[i+1]){
            return i+1;
        }
       }

       return j;
       

          



           



        
    }
};
