class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {

        int n=nums.size();
        int st=1;
        int end=n-1;

        while(st<=end){

            int mid=st+(end-st)/2;

            if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1]){
                return mid;
            }

            if(nums[mid]<nums[mid-1]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
      return -1;  
    }
};
