class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //find the pivot

        int pivot=-1,n=nums.size();

        for(int i=n-2;i>=0;i--){

            if(nums[i]<nums[i+1]){

                pivot=i;

                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        //step: next larger element

        for(int i=n-1;i>pivot;i--){

            if(nums[pivot]<nums[i]){

                swap(nums[i],nums[pivot]);
                break;
            }
        } 
        //3rd step:revers (pivot to n-1)     

        int i=pivot+1,j=n-1;

        while(i<j){

            swap(nums[i++],nums[j--]);
        }  
    }
};