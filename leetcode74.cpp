class Solution {
public:

bool searchInRow(vector<vector<int>>& mat,int midrow,int target){

    int n=mat[0].size();
   int st=0,end=n-1;

    while(st<=end){

        int mid=st+(end-st)/2;
        if(target==mat[midrow][mid]){
            return true;
        }

      else  if(target>mat[midrow][mid]){

            st=mid+1;

        }
        else if(target<mat[midrow][mid]){

            end=mid-1;
        }




    }
return false;
}
    bool searchMatrix(vector<vector<int>>& mat, int target) {
    
    int n=mat[0].size(),m=mat.size();

    int startrow =0,endrow=m-1;

    while(startrow<=endrow){

        int midrow=startrow+(endrow-startrow)/2;

        if(target>=mat[midrow][0]&&(target<=mat[midrow][n-1])){

           return searchInRow(mat, midrow, target);

        }
            //found row;
            else if(target>mat[midrow][n-1]){
                startrow=midrow+1;

            }
            else{
                endrow=midrow-1;
            }


        } 

return false;
    }
   
        
    
};
