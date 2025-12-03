class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low=0,mid=0,high=nums.size()-1;

        while(mid<=high){

            if(nums[mid]==0){

                swap(nums[mid],nums[low]);
                mid++;
                low++;

            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;// now your mind have a question why we can not increce the mid++
                //the answer of your question is afher the swap 2 is place at right place but 
                //we can not no which value of mid have so we check and mid++; 

            }


        }

    }
    };
