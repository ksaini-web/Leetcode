#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;




int threesumcloset(vector<int>& nums,int target){

    int n=nums.size();

    int start =0;
    int end=n-1;
    if(n<3)
    {cout<<"not diffent";
    return 0;}

    sort(nums.begin(),nums.end());

    int best=nums[0]+nums[1]+nums[2];

    for(int i=0;i<n-2;i++){

        int left=i+1, right=n-1;

        while(left<right){

            long long sum=(long long)nums[left]+nums[right]+nums[i];

            if(abs(sum-target)<abs((long long)best-target)){

                best=(int)sum;

               

            }
            if(sum==target){

                return target;
            }

            else if(sum<target){
                ++left;
            }
            else{
                --right;
            }
        }
    }

    return best;

};

int main(){

    

    vector<int>nums={-1,2,1,-4};

    cout<<threesumcloset(nums,1);








    return 0;
}