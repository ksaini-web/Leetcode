class Solution {
public:

void merge(vector<int>&nums,int st,int end,int mid){

vector<int>temp;
int i=st;
int j=mid+1;

while(i<=mid&&j<=end){

    if(nums[i]<=nums[j]){

       temp.push_back(nums[i]);
        i++;
    }
    else{
       temp.push_back(nums[j]);
        j++;  
    }
}
while(i<=mid){
    temp.push_back(nums[i]);
        i++;
}
while(j<=end){
    temp.push_back(nums[j]);
        j++; 
}
for(int idx =0;idx<temp.size();idx++){

    nums[idx+st]=temp[idx];
}
    
}

void mergesort(vector<int>& nums,int st,int end){



if(st>=end){
    return;
}
int mid = st +(end-st)/2;
//for the left side;

mergesort(nums,st,mid);

//for the right side;

mergesort(nums,mid+1,end);

merge(nums,st,end,mid);}

    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums,0,nums.size()-1);
        return nums;
        
    }
};
