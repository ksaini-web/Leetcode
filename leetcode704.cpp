class Solution {
public:
       int binary_search(vector<int>arr,int target,int st,int end){

        if(st<=end){
            int mid=st+(end-st)/2;

            if(target==arr[mid])return mid;

            if(target<=arr[mid])
            return binary_search(arr,target,st,mid-1);

            if(target>=arr[mid])
            return binary_search(arr,target,mid+1,end);
        }
        return -1;
       }


    int search(vector<int>& nums, int target) {

        int st=0,end=nums.size()-1;

        return binary_search(nums,target,st,end);






        
    }
};
