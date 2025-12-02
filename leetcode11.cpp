class Solution {
public:
    int maxArea(vector<int>& height) {

        int i=0,j=height.size()-1;

        int ans=0;

        while(i<j){

            int widht=j-i;

            int minheight=min(height[i],height[j]);

            int current=minheight*widht;

            ans=max(current,ans);

            if(height[i]<height[j]){

                i++;
            }
            else{
                j--;
            }


        }
          
        return ans;
    }

  

};
